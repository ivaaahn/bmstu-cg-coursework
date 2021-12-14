//
// Created by ivaaahn on 24.05.2021.
//

#include <cmath>
#include <exceptions/load_exceptions.hpp>
#include "camera.hpp"
#include "../../../consts.hpp"
#include "math/linalg.hpp"

using linalg::aliases::float3;

Camera::Camera(const std::shared_ptr<std::ifstream>& srcFile) {
    float x, y, z;

    if (!(*srcFile >> x >> y >> z))
        throw FileFormatError(__FILE__, __LINE__, "invalid model-file format");

    this->position = float3{x, y, z};
}


static void rotateY(float3 *p, float angle) {
    float cos_y = cos(toRad(angle));
    float sin_y = sin(toRad(angle));

    float tmp_x = p->x;

    p->x = p->x * cos_y - p->z * sin_y;
    p->z = p->z * cos_y + tmp_x * sin_y;
}


static void rotateX(float3 *p, float angle) {
    float cos_x = cos(toRad(angle));
    float sin_x = sin(toRad(angle));
    float tmp_y = p->y;

    p->y = p->y * cos_x - p->z * sin_x;
    p->z = p->z * cos_x + tmp_y * sin_x;
}

std::shared_ptr<Ray> Camera::getRay(const int w, const int h) const {
    auto base_x = (float)((w + 0.5) - WIDTH / 2.);
    auto base_y = (float)(-((h + 0.5) - HEIGHT / 2.));
    auto base_z = (float)(-HEIGHT / (2. * tan(toRad((float)this->fov) / 2.)));

    auto p = float3{base_x, base_y, base_z};

    if (this->angles.x) rotateX(&p, (float)this->angles.x);
    if (this->angles.y) rotateY(&p, (float)this->angles.y);

    return std::make_shared<Ray>(this->position, linalg::normalize(p));
}
