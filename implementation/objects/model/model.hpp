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
    explicit Triangle(int3 verts): verts(verts) {}
    int3 verts {};
};


class TriangularModel : public Figure {
private:
    std::vector<float3> _points;
    std::vector<Triangle> _faces;
    float3 _box_bounds[2] = {};

    bool _rayFaceIntersect(const std::shared_ptr<Ray> &ray, const Triangle& face, float &ray_tvalue) const;
//    void _loadPoints(const std::shared_ptr<std::ifstream>& srcFile);
//    void _loadFaces(const std::shared_ptr<std::ifstream>& srcFile);
    [[nodiscard]] bool _rayBoxIntersect(const std::shared_ptr<Ray>& ray) const;

public:
    explicit TriangularModel(const std::shared_ptr<std::ifstream>& srcFile);



    [[nodiscard]] int numOfPoints() const;
    [[nodiscard]] int numOfFaces() const;

    [[nodiscard]] const float3& getPoint(int point_idx) const;
    float3& getPoint(int point_idx);

    [[nodiscard]] const Triangle& getFace(int face_idx) const;

    void getBox(float3& p_min, float3& p_max);

    bool rayIntersect(const std::shared_ptr<Ray>& ray, float& distTo1stIntersect, float3& N, float3& hit) const override;

    [[nodiscard]] float3 getNormal(const Triangle& face, const std::shared_ptr<Ray>& ray) const;


    void transform(const float3& move, const float3& scale, const float3& rotate) override {}

    [[nodiscard]] raw_figure clFormat() const override;

    ~TriangularModel() override = default;

//    bool rayTriangleIntersect(const )

//    explicit TriangularModel(std::shared_ptr<ModelDetails> details);

//    TriangularModel(const Model &model);
//
//    ~Model() override = default;
//
//    void transform(const Point &move_params, const Point &scale_params, const Point &rotate_params) override;
//
//    void accept(std::shared_ptr<Visitor> visitor) override;
//
//    friend void DrawVisitor::visit(const Model &model);
//
//protected:
//    [[nodiscard]] const std::shared_ptr<ModelDetails> getDetails() const;
//
//private:
//    std::shared_ptr<ModelDetails> details;
};


#endif //__LAB_03_MODEL_HPP__
