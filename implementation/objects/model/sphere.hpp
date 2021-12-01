//
// Created by ivaaahn on 06.09.2021.
//

#ifndef __CG_COURSEWORK_SPHERE_HPP__
#define __CG_COURSEWORK_SPHERE_HPP__


#include <memory>
#include <fstream>
#include "math/linalg.hpp"
#include "objects/material/material.hpp"
#include "objects/model/figure.hpp"
#include <ray/ray.hpp>


using namespace linalg::aliases;

class Sphere final : public Figure {
private:
    float _radius;
    void _loadRadius(const std::shared_ptr<std::ifstream>& srcFile);
    void _loadCenter(const std::shared_ptr<std::ifstream>& srcFile);

public:
    Sphere(const float3& c, float r, const Material& m) : Figure(m, c), _radius(r) {}

    explicit Sphere(const std::shared_ptr<std::ifstream>& srcFile);

    [[nodiscard]] float getRadius() const { return this->_radius; }

    bool rayIntersect(const std::shared_ptr<Ray> &ray, float& distTo1stIntersect, float3& N, float3& hit) const final;

    void transform(const float3& move, const float3& scale, const float3& rotate) final;

//    [[nodiscard]] cl_float4 clFormat() const override {
//        return { cl_float(_center.x), cl_float(_center.y), cl_float(_center.z), cl_float(this->_radius) };
//    }

    [[nodiscard]] raw_figure clFormat() const override {
        return raw_figure {};
    }

    ~Sphere() final = default;
};


#endif //__CG_COURSEWORK_SPHERE_HPP__
