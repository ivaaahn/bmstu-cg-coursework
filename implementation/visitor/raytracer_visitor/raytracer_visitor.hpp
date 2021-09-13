//
// Created by ivaaahn on 06.09.2021.
//

#ifndef __CG_COURSEWORK_RAYTRACER_VISITOR_HPP__
#define __CG_COURSEWORK_RAYTRACER_VISITOR_HPP__

#include <memory>
#include "objects/model/model_details/point/point.hpp"
#include "objects/camera/camera.hpp"
#include "objects/composite/composite.hpp"
#include "drawer/drawer.hpp"
#include "visitor/visitor.hpp"


class RaytracerVisitor : public Visitor {
    RaytracerVisitor() = default;
    void visit(const Figure &figure) override;
};


#endif //__CG_COURSEWORK_RAYTRACER_VISITOR_HPP__
