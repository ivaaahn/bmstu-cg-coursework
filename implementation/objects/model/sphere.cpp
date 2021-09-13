//
// Created by ivaaahn on 06.09.2021.
//

#include "sphere.hpp"
#include <fstream>
#include <exceptions/load_exceptions.hpp>


bool Sphere::rayIntersect(const float3& source, const float3& dir, float& distTo1stIntersect) const {
    float3 L = this->_center - source;


    float dFromSrcToProjOfCenter = dot(L, dir);
    float distToRaySqr = linalg::length2(L) - dFromSrcToProjOfCenter * dFromSrcToProjOfCenter;

    if (distToRaySqr > this->_radius * this->_radius)
    {
        return false;
    }

    float halfChordLength = sqrtf(this->_radius * this->_radius - distToRaySqr);

    distTo1stIntersect = dFromSrcToProjOfCenter - halfChordLength;
    float distTo2ndIntersect = dFromSrcToProjOfCenter + halfChordLength;

    if (distTo1stIntersect < 0)
    {
        distTo1stIntersect = distTo2ndIntersect;
    }

    if (distTo1stIntersect < 0)
    {
        return false;
    }

    return true;
}

Sphere::Sphere(std::shared_ptr<std::ifstream> srcFile) {
    this->_loadCenter(srcFile);
    this->_loadRadius(srcFile);
    this->_material = Material(srcFile);
}

void Sphere::_loadRadius(std::shared_ptr<std::ifstream> srcFile) {
    float tempRadius = 0.f;

    if (!(*srcFile >> tempRadius))
        throw FileFormatError(__FILE__, __LINE__, "invalid model-file format");

    this->_radius = tempRadius;
}

void Sphere::_loadCenter(std::shared_ptr<std::ifstream> srcFile) {
    float x, y, z;

    if (!(*srcFile >> x >> y >> z))
        throw FileFormatError(__FILE__, __LINE__, "invalid model-file format");

    this->_center = float3{x, y, z};
}

void Sphere::transform(const float3& move, const float3& scale, const float3& rotate) {
//TODO
}
