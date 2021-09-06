//
// Created by ivaaahn on 24.05.2021.
//

#ifndef __LAB_03_MODEL_DIRECTOR_HPP__
#define __LAB_03_MODEL_DIRECTOR_HPP__

#include <load/builders/model/model_builder.hpp>
#include "../load_director.hpp"

class ModelDirector : public LoadDirector {
public:
    ModelDirector();
    ~ModelDirector() = default;

    std::shared_ptr<Object> make(const std::string &src_name) override;

private:
    std::shared_ptr<ModelBuilder> builder;
};


#endif //__LAB_03_MODEL_DIRECTOR_HPP__
