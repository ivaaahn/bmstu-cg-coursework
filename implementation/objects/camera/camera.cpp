//
// Created by ivaaahn on 24.05.2021.
//

#include <exceptions/load_exceptions.hpp>
#include "camera.hpp"
#include "../../../consts.hpp"

using linalg::aliases::float3;

Camera::Camera(const float3 &position) : position(position) {}

void Camera::shift(const float3 &params) {
    this->position.x += params.x;
    this->position.y += params.y;
    this->position.z += params.z;
}

const float3& Camera::getPos() const {
    return this->position;
}

Camera::Camera(const std::shared_ptr<std::ifstream>& srcFile) {
    float x, y, z;

    if (!(*srcFile >> x >> y >> z))
        throw FileFormatError(__FILE__, __LINE__, "invalid model-file format");

    this->position = float3 {x, y, z};
}

std::shared_ptr<Ray> Camera::getRay(const int w, const int h) const {
    float x = (2 * (w + 0.5) / (float)WIDTH - 1) * tan(this->fov / 2.) * WIDTH / (float)HEIGHT;
    float y = -(2 * (h + 0.5) / (float)HEIGHT - 1) * tan(this->fov / 2.);
    return std::make_shared<Ray>(this->position, normalize(float3{x, y, -1}));
}
