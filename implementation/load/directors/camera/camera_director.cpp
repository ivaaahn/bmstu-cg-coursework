//
// Created by ivaaahn on 26.05.2021.
//

#include <load/solutions/camera/camera_load_solution.hpp>
#include "camera_director.hpp"

CameraDirector::CameraDirector() : builder(std::make_shared<CameraBuilder>()) {
    this->loader = CameraLoadSolution::getCreator()->create();
}

std::shared_ptr<Object> CameraDirector::make(const std::string &src_name) {
    this->loader->open(src_name);
    this->builder->reset();

    double x = 0, y = 0, z = 0;
    this->loader->loadPointCoords(x, y, z);
    this->builder->buildPosition(x, y, z);

    this->loader->close();

    return this->builder->get();
}
