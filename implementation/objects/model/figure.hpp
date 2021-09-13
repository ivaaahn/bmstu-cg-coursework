//
// Created by ivaaahn on 06.09.2021.
//

#ifndef __CG_COURSEWORK_FIGURE_HPP__
#define __CG_COURSEWORK_FIGURE_HPP__

#include "math/linalg.hpp"
#include "objects/material/material.hpp"
#include "objects/model/figure.hpp"

using namespace linalg::aliases;

class Figure {
public:
    Figure(const Material& m, const float3 &center) : _material(m), _center(center) {}

//    Figure(std::shared_ptr<std::ifstream> srcFile) = 0;

    Figure() = default;

    virtual bool rayIntersect(const float3& source, const float3& dir, float& distTo1stIntersect) const = 0;

    virtual void transform(const float3& move, const float3& scale, const float3& rotate) = 0;

    virtual ~Figure() = 0;

    [[nodiscard]] const Material& getMaterial() const { return this->_material; }

    [[nodiscard]] const float3& getCenter() const { return this->_center; }

protected:
    Material _material;
    float3 _center;
};

#endif //__CG_COURSEWORK_FIGURE_HPP__
