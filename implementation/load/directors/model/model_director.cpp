//
// Created by ivaaahn on 24.05.2021.
//

#include <vector>

#include <load/solutions/model/model_load_solution.hpp>
#include "model_director.hpp"


ModelDirector::ModelDirector() : builder(std::make_shared<ModelBuilder>()){
    this->loader = ModelLoadSolution::getCreator()->create();
}

std::shared_ptr<Object> ModelDirector::make(const std::string &src_name) {
    this->loader->open(src_name);
    this->builder->reset();

//    Making points...

    size_t p_count = 0;
    this->loader->loadPointsCount(p_count);

    double x = 0, y = 0, z = 0;
    for (size_t i = 0; i < p_count; ++i)
    {
        this->loader->loadPointCoords(x, y, z);
        this->builder->buildPoint(x, y, z);
    }

//    Making center...

    this->loader->loadPointCoords(x, y, z);
    this->builder->buildCenter(x, y, z);

//    Making edges...
    size_t e_count = 0;
    this->loader->loadEdgesCount(e_count);

    size_t p1_id = 0, p2_id = 0;
    for (size_t i = 0; i < e_count; ++i)
    {
        this->loader->loadEdge(p1_id, p2_id);
        this->builder->buildEdge(p1_id, p2_id);
    }

    this->loader->close();

    return this->builder->get();
}
