//
// Created by ivahn on 9/14/2021.
//

#ifndef __CG_COURSEWORK_RAYTRACER_HPP__
#define __CG_COURSEWORK_RAYTRACER_HPP__
#include <utility>
#include <vector>
#include <memory>
#include <objects/model/figure.hpp>
#include "drawer/drawer.hpp"
#include <CL/cl.hpp>

class RayTracer {
public:
    RayTracer();
    static void cpuRender(const std::shared_ptr<Scene> &scene, const std::shared_ptr<Camera> &cam, const std::shared_ptr<Drawer> &drawer);
    void gpuRender(const std::shared_ptr<Scene> &scene, const std::shared_ptr<Camera> &cam, const std::shared_ptr<Drawer> &drawer);

private:
    cl::Device device;
    cl::Context ctx;
    cl::Program program;


    void init_device();
    cl::Device get_default_device();
};


class RayTracerCreator {
public:
    std::shared_ptr<RayTracer> get();

private:
    void create();

    std::shared_ptr<RayTracer> rt;
};


#endif //__CG_COURSEWORK_RAYTRACER_HPP__
