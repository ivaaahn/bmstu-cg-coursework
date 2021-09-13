//
// Created by ivaaahn on 06.09.2021.
//

#ifndef __CG_COURSEWORK_LIGHT_HPP__
#define __CG_COURSEWORK_LIGHT_HPP__

#include <memory>
#include <fstream>

#include <objects/object.hpp>
#include "math/linalg.hpp"

using namespace linalg::aliases;

class Light {
public:
    Light(const float3& p, const float& i) : _position(p), _intensity(i) {}

    explicit Light(const std::shared_ptr<std::ifstream>& srcFile);


    [[nodiscard]] const float3& getPosition() {
        return this->_position;
    }

    [[nodiscard]] float getIntensity() const {
        return this->_intensity;
    }

private:
    float3 _position;
    float _intensity;

    void _loadPosition(const std::shared_ptr<std::ifstream>& srcFile);

    void _loadIntensity(const std::shared_ptr<std::ifstream>& srcFile);
};


#endif //__CG_COURSEWORK_LIGHT_HPP__
