//
// Created by ivaaahn on 24.05.2021.
//

#include <utility>
#include <memory>
#include <math/rays_handling.hpp>
#include <iostream>

#include "draw_manager.hpp"
#include "scene/scene.hpp"

void DrawManager::setDrawer(std::shared_ptr<Drawer> drawer) {
    this->drawer = std::move(drawer);
}

void DrawManager::setCamera(std::shared_ptr<Camera> camera) {
    this->camera = std::move(camera);
}

void DrawManager::draw(const std::shared_ptr<Scene> &scene) {
//    int w = (*scene)->wi
//    std::cout << w << ' ' << h << std::endl;
    const int width = 1081;
    const int height = 900;
    const float fov = M_PI / 3.;

#pragma omp parallel for num_threads(16)
    for (size_t j = 0; j < height; j++)
    {
        for (size_t i = 0; i < width; i++)
        {
            float x = (2 * (i + 0.5) / (float)width - 1) * tan(fov / 2.) * width / (float)height;
            float y = -(2 * (j + 0.5) / (float)height - 1) * tan(fov / 2.);
            auto dir = normalize(float3{x, y, -1});

            auto c = RaysHandling::castRay(this->camera->getPos(), dir, scene);

            float max = std::max(c[0], std::max(c[1], c[2]));
            if (max > 1) c *= (1.f / max);

            c[0] = std::max(0.f, std::min(1.f, c[0]));
            c[1] = std::max(0.f, std::min(1.f, c[1]));
            c[2] = std::max(0.f, std::min(1.f, c[2]));

            c *= 255;

            this->drawer->putPixel(int2{(int)i, (int)j}, c);
        }
    }

}

void DrawManagerCreator::createManager() {
    static auto manager = std::make_shared<DrawManager>();
    this->manager = manager;
}

std::shared_ptr<DrawManager> DrawManagerCreator::getManager() {
    if (this->manager == nullptr) this->createManager();

    return this->manager;
}