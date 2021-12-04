//
// Created by ivaaahn on 28.05.2021.
//

#ifndef __LAB_03_MODEL_BUILDER_HPP__
#define __LAB_03_MODEL_BUILDER_HPP__


#include <vector>
#include <objects/model/model_details/point/point.hpp>
#include <objects/model/model_details/edge/edge.hpp>
#include <memory>
#include <objects/model/trismodel.hpp>

class ModelBuilder {
public:
    ModelBuilder();

    ~ModelBuilder() = default;

    bool isBuild();

    void reset();

    void buildCenter(double x, double y, double z);

    void buildPoint(double x, double y, double z);

    void buildEdge(size_t p1_id, size_t p2_id);

    std::shared_ptr<Model> get();

private:
    std::shared_ptr<ModelDetails> model_details;
};


#endif //__LAB_03_MODEL_BUILDER_HPP__
