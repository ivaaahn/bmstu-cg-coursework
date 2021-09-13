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


using namespace linalg::aliases;

class Sphere final : public Figure {
public:
    Sphere(const float3& c, float r, const Material& m) : Figure(m, c), _radius(r) {}

    explicit Sphere(std::shared_ptr<std::ifstream> srcFile);

    [[nodiscard]] float getRadius() const { return this->_radius; }

    bool rayIntersect(const float3& source, const float3& dir, float& distTo1stIntersect) const final;

    void transform(const float3& move, const float3& scale, const float3& rotate) final;

    ~Sphere() final = default;

private:
    float _radius;

    void _loadRadius(std::shared_ptr<std::ifstream> srcFile);

    void _loadCenter(std::shared_ptr<std::ifstream> srcFile);
};


#endif //__CG_COURSEWORK_SPHERE_HPP__
