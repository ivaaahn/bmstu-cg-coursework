//
// Created by ivaaahn on 24.05.2021.
//

#ifndef __LAB_03_CAMERA_HPP__
#define __LAB_03_CAMERA_HPP__


#include <memory>
#include <fstream>
#include <ray/ray.hpp>

#include "math/linalg.hpp"
#include <CL/cl.hpp>

using namespace linalg::aliases;

class Camera {
public:
    Camera() = default;

    explicit Camera(const float3& position);

    explicit Camera(const std::shared_ptr<std::ifstream>& srcFile);

    ~Camera() = default;

    void shift(const float3& params);

    [[nodiscard]] const float3& getPos() const;

    [[nodiscard]] std::shared_ptr<Ray> getRay(int w, int h) const;

    [[nodiscard]] cl_float4 clFormat() const {
        return {cl_float(position.x), cl_float(position.y), cl_float(position.z), cl_float(fov)};
    }

private:
    float3 position{};
    float fov = M_PI / 3.;
};


#endif //__LAB_03_CAMERA_HPP__
