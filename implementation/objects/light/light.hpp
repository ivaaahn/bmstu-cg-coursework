//
// Created by ivaaahn on 06.09.2021.
//

#ifndef __CG_COURSEWORK_LIGHT_HPP__
#define __CG_COURSEWORK_LIGHT_HPP__

#include <memory>
#include <fstream>

#include <objects/object.hpp>
#include "math/linalg.hpp"
#include <CL/cl.hpp>

using namespace linalg::aliases;

typedef struct __attribute__ ((packed)) _raw_light {
    cl_float3 position;
    cl_float intensity;
} raw_light;


class Light {
public:
    Light(const float3& p, float i) : _position(p), _intensity(i) {}

    explicit Light(const std::shared_ptr<std::ifstream>& srcFile);


    void setPos(const float3& value) { this->_position = value; }

    void setIntensity(float value) { this->_intensity = value; }

    [[nodiscard]] const float3& getPos() {
        return this->_position;
    }

    [[nodiscard]] float getIntensity() const {
        return this->_intensity;
    }

    [[nodiscard]] raw_light clFormat() const {
        return {
                cl_float3{_position.x, _position.y, _position.z},
                cl_float{_intensity}
        };
    }

private:
    float3 _position;
    float _intensity;

    void _loadPosition(const std::shared_ptr<std::ifstream>& srcFile);

    void _loadIntensity(const std::shared_ptr<std::ifstream>& srcFile);
};


#endif //__CG_COURSEWORK_LIGHT_HPP__
