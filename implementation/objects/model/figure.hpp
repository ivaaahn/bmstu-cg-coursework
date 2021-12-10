//
// Created by ivaaahn on 06.09.2021.
//

#ifndef __CG_COURSEWORK_FIGURE_HPP__
#define __CG_COURSEWORK_FIGURE_HPP__

#include "math/linalg.hpp"
#include "objects/material/material.hpp"
#include <ray/ray.hpp>
#include <CL/cl.hpp>

using namespace linalg::aliases;

#define NP 5000
#define NF 8000

enum FigureType {
    POLYGONAL,
    SPHERE,
};

// TODO add material support
typedef struct __attribute__ ((packed)) _raw_figure {
    cl_float3 points[NP];
    cl_int3 faces[NF];
    cl_float3 box_bounds[2];
    cl_int num_of_points;
    cl_int num_of_faces;
    raw_material material;
    cl_float3 center;
    cl_float radius;
    int fig_type;  // пока что у полигона - 0, а у сферы - 1
} raw_figure;


class Figure {
protected:
    Material _material;

public:
    Figure() = default;

    explicit Figure(const Material& m) : _material(m) {}

    virtual bool
    rayIntersect(const std::shared_ptr<Ray>& ray, float& distTo1stIntersect, float3& N, float3& hit) const = 0;

//    virtual void transform(const float3& move, const float3& scale, const float3& rotate) = 0;
    virtual void rotate(const float3& value) = 0;
    virtual void translate(const float3& value) = 0;
    virtual void scale(const float3& value) = 0;
    virtual ~Figure() = 0;

    void editMaterial(const Material &mat) { this->_material = mat; }

    [[nodiscard]] const Material& getMaterial() const { return this->_material; }

    [[nodiscard]] Material getMaterial() { return this->_material; }

    [[nodiscard]] virtual float3 getCenter() const = 0;

    [[nodiscard]] raw_material clMaterial() const { return _material.clFormat(); }

    [[nodiscard]] virtual raw_figure clFormat() const = 0;
};

#endif //__CG_COURSEWORK_FIGURE_HPP__
