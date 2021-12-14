//
// Created by ivaaahn on 06.09.2021.
//

#include "material.hpp"
#include <fstream>
#include <exceptions/load_exceptions.hpp>

Material::Material(const std::shared_ptr<std::ifstream>& srcFile) {
    this->_readAlbedo(srcFile);
    this->_readDiffuseColor(srcFile);
    this->_readSpecularExp(srcFile);
    this->_readRefIdx(srcFile);
}

void Material::_readAlbedo(const std::shared_ptr<std::ifstream>& srcFile) {
    float x, y, z, t;

    if (!(*srcFile >> x >> y >> z >> t))
        throw FileFormatError(__FILE__, __LINE__, "invalid model-file format");

    this->_albedo = float4{x, y, z, t};
}

void Material::_readDiffuseColor(const std::shared_ptr<std::ifstream>& srcFile) {
    float x, y, z;

    if (!(*srcFile >> x >> y >> z))
        throw FileFormatError(__FILE__, __LINE__, "invalid model-file format");

    this->_diffuseColor = float3{x, y, z};
}

void Material::_readSpecularExp(const std::shared_ptr<std::ifstream>& srcFile) {
    float tempSpecularExp = 0.f;

    if (!(*srcFile >> tempSpecularExp))
        throw FileFormatError(__FILE__, __LINE__, "invalid model-file format");

    this->_specularExp = tempSpecularExp;
}

void Material::_readRefIdx(const std::shared_ptr<std::ifstream>& srcFile) {
    float tempRefIdx = 0.f;

    if (!(*srcFile >> tempRefIdx))
        throw FileFormatError(__FILE__, __LINE__, "invalid model-file format");

    this->_refIdx = tempRefIdx;
}

