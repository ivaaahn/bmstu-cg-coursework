//
// Created by ivaaahn on 24.05.2021.
//

#ifndef __LAB_03_CAMERA_HPP__
#define __LAB_03_CAMERA_HPP__


#include <memory>
#include <fstream>

#include "math/linalg.hpp"

using namespace linalg::aliases;

class Camera {
public:
    Camera() = default;

    explicit Camera(const float3& position);

    explicit Camera(const std::shared_ptr<std::ifstream>& srcFile);

    ~Camera() = default;

    void shift(const float3& params);

    [[nodiscard]] const float3& getPos() const;

private:
    float3 position{};
};


#endif //__LAB_03_CAMERA_HPP__
