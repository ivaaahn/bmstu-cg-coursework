//
// Created by ivaaahn on 28.05.2021.
//

#include "model_builder.hpp"

ModelBuilder::ModelBuilder() : model_details(nullptr) {}

bool ModelBuilder::isBuild() {
    return this->model_details != nullptr;
}

void ModelBuilder::reset() {
    this->model_details = std::make_shared<ModelDetails>();
}

void ModelBuilder::buildCenter(const double x, const double y, const double z) {
    this->model_details->setCenter(Point(x, y, z));
}

void ModelBuilder::buildPoint(const double x, const double y, const double z) {
    this->model_details->addPoint(Point(x, y, z));
}

void ModelBuilder::buildEdge(const size_t p1_id, const size_t p2_id) {
    this->model_details->addEdge(Edge(p1_id, p2_id));
}

std::shared_ptr<Model> ModelBuilder::get() {
    return std::make_shared<Model>(this->model_details);
}
