#pragma clang diagnostic push
#pragma ide diagnostic ignored "openmp-use-default-none"
//
// Created by ivahn on 9/14/2021.
//

#include <CL/cl.hpp>
#include <math/rays_handling.hpp>
#include <drawer/drawer.hpp>
#include <iostream>
#include "raytracer.hpp"
#include "../../consts.hpp"
#include <omp.h>
#include <QImage>
#include <objects/model/trismodel.hpp>
//#include <boost/compute/system.hpp>
//#include <boost/compute/image/image2d.hpp>
//#include <boost/compute/interop/qt.hpp>
//#include <boost/compute/utility/dim.hpp>
//#include <boost/compute/utility/source.hpp>
//namespace compute = boost::compute;

//using std::cin, std::cout;

void RayTracer::cpuRender(const std::shared_ptr<Scene>& scene, const std::shared_ptr<Camera>& cam,
                          const std::shared_ptr<Drawer>& drawer) {
#pragma omp parallel for num_threads(8)
    for (int j = 0; j < HEIGHT; j++) {
        for (int i = 0; i < WIDTH; i++) {
            auto c = RaysHandling::castRayCPU(cam->getRay(i, j), scene);

            float max = std::max(c[0], std::max(c[1], c[2]));
            if (max > 1) c *= (1.f / max);

            c[0] = std::max(0.f, std::min(1.f, c[0]));
            c[1] = std::max(0.f, std::min(1.f, c[1]));
            c[2] = std::max(0.f, std::min(1.f, c[2]));

            c *= 255;

            drawer->putPixel(int2{i, j}, c);
        }
    }
}


#define NUM_OF_ELEMENTS WIDTH * HEIGHT

void RayTracer::gpuRender(const std::shared_ptr<Scene>& scene, const std::shared_ptr<Camera>& cam,
                          const std::shared_ptr<Drawer>& drawer) {

    auto *hFigures = new raw_figure[scene->_models.size()];
    auto *hLights = new raw_light[scene->_lights.size()];
    auto *hCamera = new raw_camera[1];                  // Camera
    auto *hDim = new cl_int2[1];                        // Dimensions
    auto *hFigSize = new cl_int[1];                     // Figures List's Size
    auto *hLightSize = new cl_int[1];                   // Lights List's Size
    auto *hSceneAmbientLight = new cl_float[1];                   // Lights List's Size
    auto *hRayTreeHeightMax = new cl_int[1];                   // Lights List's Size

    cl_uchar *hImg = drawer->getImage()->bits();
    int hImgLen = (int)drawer->getImage()->sizeInBytes();

#pragma omp parallel for num_threads(16)
    for (int i = 0; i < int(scene->_models.size()); ++i)
        hFigures[i] = scene->_models[i]->clFormat();


#pragma omp parallel for num_threads(16)
    for (int i = 0; i < int(scene->_lights.size()); ++i)
        hLights[i] = scene->_lights[i]->clFormat();


    hCamera[0] = cam->clFormat();     // Gathering cameras
    hDim[0] = {WIDTH, HEIGHT};
    hFigSize[0] = int(scene->_models.size());
    hLightSize[0] = int(scene->_lights.size());
    hSceneAmbientLight[0] = scene->getAmbientLightIntensity();
    hRayTreeHeightMax[0] = scene->getRTreeHeightMax();


    cl::Buffer bImg(this->ctx, CL_MEM_WRITE_ONLY | CL_MEM_HOST_READ_ONLY, hImgLen * sizeof(cl_uchar));
    cl::Buffer bFigures(this->ctx, CL_MEM_READ_ONLY | CL_MEM_HOST_NO_ACCESS | CL_MEM_USE_HOST_PTR,
                        scene->_models.size() * sizeof(raw_figure), hFigures);
    cl::Buffer bLights(this->ctx, CL_MEM_READ_ONLY | CL_MEM_HOST_NO_ACCESS | CL_MEM_USE_HOST_PTR,
                       scene->_lights.size() * sizeof(raw_light), hLights);
    cl::Buffer bCamera(this->ctx, CL_MEM_READ_ONLY | CL_MEM_HOST_NO_ACCESS | CL_MEM_USE_HOST_PTR,
                        1 * sizeof(raw_camera), hCamera);
    cl::Buffer bDim(this->ctx, CL_MEM_READ_ONLY | CL_MEM_HOST_NO_ACCESS | CL_MEM_USE_HOST_PTR, 1 * sizeof(cl_int2),
                    hDim);
    cl::Buffer bFigSize(this->ctx, CL_MEM_READ_ONLY | CL_MEM_HOST_NO_ACCESS | CL_MEM_USE_HOST_PTR, 1 * sizeof(cl_int),
                        hFigSize);
    cl::Buffer bLightSize(this->ctx, CL_MEM_READ_ONLY | CL_MEM_HOST_NO_ACCESS | CL_MEM_USE_HOST_PTR, 1 * sizeof(cl_int),
                          hLightSize);
    cl::Buffer bSceneAmbientLight(this->ctx, CL_MEM_READ_ONLY | CL_MEM_HOST_NO_ACCESS | CL_MEM_USE_HOST_PTR, 1 * sizeof(cl_float),
                          hSceneAmbientLight);
    cl::Buffer bRayTreeHeightMax(this->ctx, CL_MEM_READ_ONLY | CL_MEM_HOST_NO_ACCESS | CL_MEM_USE_HOST_PTR, 1 * sizeof(cl_int),
                          hRayTreeHeightMax);

    cl::Kernel kernel(this->program, "Render", nullptr);
    kernel.setArg(0, bImg);
    kernel.setArg(1, bFigures);
    kernel.setArg(2, bLights);
    kernel.setArg(3, bCamera);
    kernel.setArg(4, bDim);
    kernel.setArg(5, bFigSize);
    kernel.setArg(6, bLightSize);
    kernel.setArg(7, bSceneAmbientLight);
    kernel.setArg(8, bRayTreeHeightMax);

    cl::CommandQueue queue(this->ctx, this->device);
    queue.enqueueNDRangeKernel(kernel, cl::NullRange, cl::NDRange(NUM_OF_ELEMENTS));
    auto err = queue.enqueueReadBuffer(bImg, CL_TRUE, 0, hImgLen * sizeof(cl_uchar), hImg);

    if (err == CL_SUCCESS) {
        std::cout << "enqueueReadBuffer ok" << std::endl;
    }

}

RayTracer::RayTracer() {
    this->device = this->get_default_device();
    this->init_device();
}

void RayTracer::init_device() {
    std::ifstream kernel_file("../raytracer.cl");
    std::string src(std::istreambuf_iterator<char>(kernel_file), (std::istreambuf_iterator<char>()));

    cl::Program::Sources sources(1, std::make_pair(src.c_str(), src.length() + 1));

    this->ctx = cl::Context(device);
    this->program = cl::Program(this->ctx, sources);

    auto err = this->program.build();
    if (err != CL_BUILD_SUCCESS) {
        std::cerr << "Error!\nBuild Status: " << program.getBuildInfo<CL_PROGRAM_BUILD_STATUS>(device)
                  << "\nBuild Log:\t " << program.getBuildInfo<CL_PROGRAM_BUILD_LOG>(device) << std::endl;
        exit(1);
    }
    std::cerr << "Program was built!" << std::endl;
}

cl::Device RayTracer::get_default_device() {

    std::vector<cl::Platform> platforms;
    cl::Platform::get(&platforms);

    if (platforms.empty()) {
        std::cerr << "No platforms found!" << std::endl;
        exit(1);
    }

    auto platform = platforms.front();

    std::vector<cl::Device> devices;
    platform.getDevices(CL_DEVICE_TYPE_GPU, &devices);

    if (devices.empty()) std::cerr << "No devices found!" << std::endl;

    return devices.front();
}


void RayTracerCreator::create() {
    static auto raytracer = std::make_shared<RayTracer>();
    this->rt = raytracer;
    std::cerr << "raytracer was created!" << std::endl;
}

std::shared_ptr<RayTracer> RayTracerCreator::get() {
    if (this->rt == nullptr) this->create();
    return this->rt;
}

#pragma clang diagnostic pop