//
// Created by ivahn on 9/14/2021.
//

#ifndef __CG_COURSEWORK_RAY_HPP__
#define __CG_COURSEWORK_RAY_HPP__


#include "math/linalg.hpp"

using linalg::aliases::float3;
using linalg::aliases::int3;

struct Ray {
    float3 src{}, dir{}, invdir{};
    int3 sign;

    Ray(float3 src, float3 dir): src(src), dir(dir), invdir(1 / dir) {

        this->sign.x = (invdir.x < 0);
        this->sign.y = (invdir.y < 0);
        this->sign.z = (invdir.z < 0);
    }
};


#endif //__CG_COURSEWORK_RAY_HPP__
