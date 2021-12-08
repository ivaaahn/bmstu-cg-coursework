//
// Created by ivaaahn on 23.05.2021.
//

#ifndef __LAB_03_MODEL_HPP__
#define __LAB_03_MODEL_HPP__


#include <memory>
#include <vector>
#include <iostream>
#include <visitor/draw_visitor/draw_visitor.hpp>
#include "model_details/model_details.hpp"
#include "objects/object.hpp"
#include "figure.hpp"

using namespace linalg::aliases;


struct Triangle {
    Triangle() = default;

    explicit Triangle(int3 verts) : verts(verts) {}

    int3 verts{};
};


class TriangularModel : public Figure {
private:
    std::vector<float3> _points;
    std::vector<Triangle> _faces;
    float3 _box_bounds[2] = {};
    float3 _corners[8] = {};

    bool _rayFaceIntersect(const std::shared_ptr<Ray>& ray, const Triangle& face, float& ray_tvalue) const;

    void _updCorners();

    void _createBox();

    static void _rotX(float3& p, float angle);

    static void _rotY(float3& p, float angle);

    static void _rotZ(float3& p, float angle);

//    static void _scale(float3& point, const float3& scale);

//    void _rot(float3& point, const float3& rotate);

    void rotate(const float3& value) override;
    void translate(const float3& value) override;
    void scale(const float3& value) override;

    [[nodiscard]] bool _rayBoxIntersect(const std::shared_ptr<Ray>& ray) const;

public:
    explicit TriangularModel(const std::shared_ptr<std::ifstream>& srcFile);

    [[nodiscard]] float3 getCenter() const override;

    [[nodiscard]] int numOfPoints() const;

    [[nodiscard]] int numOfFaces() const;

    [[nodiscard]] const float3& getPoint(int point_idx) const;

    float3& getPoint(int point_idx);

    [[nodiscard]] const Triangle& getFace(int face_idx) const;

    [[nodiscard]] float3 getN(const Triangle& face, const std::shared_ptr<Ray>& ray) const;

    bool
    rayIntersect(const std::shared_ptr<Ray>& ray, float& distTo1stIntersect, float3& N, float3& hit) const override;

//    void transform(const float3& move, const float3& scale, const float3& rotate) override;

    [[nodiscard]] raw_figure clFormat() const override;

    ~TriangularModel() override = default;
};


#endif //__LAB_03_MODEL_HPP__
