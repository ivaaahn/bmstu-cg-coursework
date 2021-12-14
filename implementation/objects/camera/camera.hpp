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

#define DEFAULT_FOV 60

using namespace linalg::aliases;

typedef struct __attribute__ ((packed)) _raw_camera {
    cl_float3 pos;
    cl_int2 angles;
    cl_int fov;
} raw_camera;


class Camera {
public:
    Camera() = default;

    explicit Camera(float3 position, float2 angles = {0, 0}, float fov = DEFAULT_FOV) : position(position) {}

    explicit Camera(const std::shared_ptr<std::ifstream>& srcFile);

    ~Camera() = default;

    void shift(const float3& value) { this->position += value; }

    [[nodiscard]] const float3& getPos() const { return this->position; }

    [[nodiscard]] const int2& getAngles() const { return this->angles; }

    [[nodiscard]] int getFov() const { return this->fov; }

    void setPos(const float3& value) { this->position = value; }

    void rotate(const int2& value) { this->angles += value; }

    void setFov(int value) { this->fov = value; }

    [[nodiscard]] std::shared_ptr<Ray> getRay(int w, int h) const;

    [[nodiscard]] raw_camera clFormat() const {
        return {
                cl_float3{
                        cl_float(position.x),
                        cl_float(position.y),
                        cl_float(position.z),
                },
                cl_int2{
                        cl_int(angles.x),
                        cl_int(angles.y),
                },
                cl_int(fov),
        };
    }

private:
    float3 position{0., 0., 1.};
    int2 angles = {0, 0};
    int fov = DEFAULT_FOV;
};


#endif //__LAB_03_CAMERA_HPP__
