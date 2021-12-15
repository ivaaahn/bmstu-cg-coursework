//
// Created by ivaaahn on 24.05.2021.
//

#include <utility>
#include <memory>
#include <math/rays_handling.hpp>
#include <iostream>

#include "draw_manager.hpp"
#include "scene/scene.hpp"

using namespace std::chrono;


void DrawManager::setDrawer(std::shared_ptr<Drawer> dr) {
    this->drawer = std::move(dr);
}

//void DrawManager::setRayTracer(std::shared_ptr<RayTracer> rt) {
//    this->raytracer = std::move(rt);
//}

#define CNT 5

int sizes[CNT] = {300, 500, 700, 900,0};
int threads[CNT] = {1, 2, 4, 8, 16};

void DrawManager::draw(const std::shared_ptr<Scene>& scene, const std::shared_ptr<Camera>& cam) {
    auto raytracer = RayTracerCreator().get();
//
//    long long summary;
//
//    for (int size : sizes) {
//        for (int thread : threads) {
//            summary = 0;
//            for (int k = 0; k < 1; ++k) {
//                auto start = high_resolution_clock::now();
//                raytracer->cpuRender(scene, cam, this->drawer, size, thread);
//                auto stop = high_resolution_clock::now();
//                auto duration = duration_cast<microseconds>(stop - start);
//                summary += duration.count();
//            }
//            summary /= (CNT * CNT);
//            std::cout << "[CPU] size: " << size << "; threads: " << thread << "; == " << summary << " mcs"
//                      << std::endl;
//        }
//    }
//
//    for (int size : sizes) {
//        summary = 0;
//        for (int k = 0; k < 1; ++k) {
//            auto start = high_resolution_clock::now();
//            raytracer->gpuRender(scene, cam, this->drawer, size);
//            auto stop = high_resolution_clock::now();
//            auto duration = duration_cast<microseconds>(stop - start);
//            summary += duration.count();
//        }
//        summary /= (CNT * CNT);
//        std::cout << "[CPU] size: " << size << "; threads: GPU; == " << summary << " mcs" << std::endl;
//    }

//    raytracer->cpuRender(scene, cam, this->drawer);
    raytracer->gpuRender(scene, cam, this->drawer, -1);


}


void DrawManagerCreator::createManager() {
    static auto manager = std::make_shared<DrawManager>();
    this->manager = manager;
}

std::shared_ptr<DrawManager> DrawManagerCreator::getManager() {
    if (this->manager == nullptr) this->createManager();
    return this->manager;
}