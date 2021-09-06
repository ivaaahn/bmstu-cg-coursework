    //
// Created by ivaaahn on 24.05.2021.
//

#ifndef __LAB_03_LOAD_DIRECTOR_HPP__
#define __LAB_03_LOAD_DIRECTOR_HPP__


#include <memory>
#include <utility>

#include "load/loaders/base_loader.hpp"
#include "objects/object.hpp"


class LoadDirector {
public:
    LoadDirector() = default;

    ~LoadDirector() = default;

    virtual std::shared_ptr<Object> make(const std::string &name) = 0;

protected:
    std::shared_ptr<BaseLoader> loader;
};

#endif //__LAB_03_LOAD_DIRECTOR_HPP__
