//
// Created by ivaaahn on 06.09.2021.
//

#include "sphere.hpp"
#include <fstream>
#include <exceptions/load_exceptions.hpp>


bool Sphere::rayIntersect(const std::shared_ptr<Ray>& ray, float& distTo1stIntersect, float3& N, float3& hit) const {
    float3 L = this->_center - ray->src;


    float dFromSrcToProjOfCenter = dot(L, ray->dir);
    float distToRaySqr = linalg::length2(L) - dFromSrcToProjOfCenter * dFromSrcToProjOfCenter;

    if (distToRaySqr > this->_radius * this->_radius) {
        return false;
    }

    float halfChordLength = sqrtf(this->_radius * this->_radius - distToRaySqr);

    distTo1stIntersect = dFromSrcToProjOfCenter - halfChordLength;
    float distTo2ndIntersect = dFromSrcToProjOfCenter + halfChordLength;

// Он заведомо больше чем первый
    if (distTo2ndIntersect < 0) return false;

    if (distTo1stIntersect < 0) {
        distTo1stIntersect = distTo2ndIntersect;
    }

    hit = ray->src + ray->dir * distTo1stIntersect;
    N = linalg::normalize((hit - this->getCenter()));

    return true;
}

Sphere::Sphere(const std::shared_ptr<std::ifstream>& srcFile) {
    this->_loadCenter(srcFile);
    this->_loadRadius(srcFile);
    this->_material = Material(srcFile);
}

void Sphere::_loadRadius(const std::shared_ptr<std::ifstream>& srcFile) {
    float tempRadius = 0.f;

    if (!(*srcFile >> tempRadius))
        throw FileFormatError(__FILE__, __LINE__, "invalid model-file format");

    this->_radius = tempRadius;
}

void Sphere::_loadCenter(const std::shared_ptr<std::ifstream>& srcFile) {
    float x, y, z;

    if (!(*srcFile >> x >> y >> z))
        throw FileFormatError(__FILE__, __LINE__, "invalid model-file format");

    this->_center = float3{x, y, z};
}

void Sphere::transform(const float3& move, const float3& scale, const float3& rotate) {
//TODO
}

raw_figure Sphere::clFormat() const {
    return {
            {},
            {},
            {},
            0,
            0,
            this->clMaterial(),
            cl_float3{_center.x, _center.y, _center.z},
            cl_float{_radius},
            FigureType::SPHERE,
    };
}

