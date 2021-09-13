//
// Created by ivaaahn on 06.09.2021.
//

#include "material.hpp"
#include <fstream>
#include <exceptions/load_exceptions.hpp>

auto a = Material();

Material::Material(std::shared_ptr<std::ifstream> srcFile) {
    this->_readAlbedo(srcFile);
    this->_readDiffuseColor(srcFile);
    this->_readSpecularExp(srcFile);
}

void Material::_readAlbedo(std::shared_ptr<std::ifstream> srcFile) {
    float x, y, z;

    if (!(*srcFile >> x >> y >> z))
        throw FileFormatError(__FILE__, __LINE__, "invalid model-file format");

    this->_albedo = float3{x, y, z};
}

void Material::_readDiffuseColor(std::shared_ptr<std::ifstream> srcFile) {
    float x, y, z;

    if (!(*srcFile >> x >> y >> z))
        throw FileFormatError(__FILE__, __LINE__, "invalid model-file format");

    this->_diffuseColor = float3{x, y, z};
}

void Material::_readSpecularExp(std::shared_ptr<std::ifstream> srcFile) {
    float tempSpecularExp = 0.f;

    if (!(*srcFile >> tempSpecularExp))
        throw FileFormatError(__FILE__, __LINE__, "invalid model-file format");

    this->_specularExp = tempSpecularExp;
}
