//
// Created by ivaaahn on 24.05.2021.
//

#include <utility>
#include <memory>
#include <math/rays_handling.hpp>
#include <iostream>

#include "draw_manager.hpp"
#include "scene/scene.hpp"

void DrawManager::setDrawer(std::shared_ptr<Drawer> dr) {
    this->drawer = std::move(dr);
}

//void DrawManager::setRayTracer(std::shared_ptr<RayTracer> rt) {
//    this->raytracer = std::move(rt);
//}

void DrawManager::draw(const std::shared_ptr<Scene> &scene, const std::shared_ptr<Camera> &cam) {
    auto raytracer = RayTracerCreator().get();
//    raytracer->cpuRender(scene, cam, this->drawer);
    raytracer->gpuRender(scene, cam, this->drawer);
}


void DrawManagerCreator::createManager() {
    static auto manager = std::make_shared<DrawManager>();
    this->manager = manager;
}

std::shared_ptr<DrawManager> DrawManagerCreator::getManager() {
    if (this->manager == nullptr) this->createManager();
    return this->manager;
}