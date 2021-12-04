//
// Created by ivaaahn on 06.09.2021.
//

#ifndef __CG_COURSEWORK_FIGURE_HPP__
#define __CG_COURSEWORK_FIGURE_HPP__

#include "math/linalg.hpp"
#include "objects/material/material.hpp"
#include "objects/model/figure.hpp"
#include <ray/ray.hpp>
#include <CL/cl.hpp>
using namespace linalg::aliases;

#define NP 5000
#define NF 8000

// TODO add material support
typedef struct __attribute__ ((packed)) _raw_figure {
    cl_float3 points[NP];
    cl_int3 faces[NF];
    cl_float3 box_bounds[2];
    cl_int num_of_points;
    cl_int num_of_faces;
    raw_material material;
} raw_figure;


class Figure {
protected:
    Material _material;
    float3 _center {};

public:
    Figure(const Material& m, const float3 &center) : _material(m), _center(center) {}

    Figure() = default;

    virtual bool rayIntersect(const std::shared_ptr<Ray>& ray, float& distTo1stIntersect, float3& N, float3& hit) const = 0;

    virtual void transform(const float3& move, const float3& scale, const float3& rotate) = 0;

    virtual raw_figure clFormat() const = 0;

    virtual ~Figure() = 0;

    [[nodiscard]] const Material& getMaterial() const { return this->_material; }

    [[nodiscard]] const float3& getCenter() const { return this->_center; }

    raw_material clMaterial() const { return _material.clFormat(); }
};

#endif //__CG_COURSEWORK_FIGURE_HPP__
