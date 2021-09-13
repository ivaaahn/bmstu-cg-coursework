//
// Created by ivaaahn on 06.09.2021.
//

#include "light.hpp"

#include <exceptions/load_exceptions.hpp>


Light::Light(const std::shared_ptr<std::ifstream>& srcFile) {
    this->_loadPosition(srcFile);
    this->_loadIntensity(srcFile);
}

void Light::_loadPosition(const std::shared_ptr<std::ifstream>& srcFile) {
    float x, y, z;

    if (!(*srcFile >> x >> y >> z))
        throw FileFormatError(__FILE__, __LINE__, "invalid model-file format");

    this->_position = float3{x, y, z};
}

void Light::_loadIntensity(const std::shared_ptr<std::ifstream>& srcFile) {
    float tempIntensity;

    if (!(*srcFile >> tempIntensity))
        throw FileFormatError(__FILE__, __LINE__, "invalid model-file format");

    this->_intensity = tempIntensity;
}


