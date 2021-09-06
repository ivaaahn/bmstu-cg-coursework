//
// Created by ivaaahn on 26.05.2021.
//

#ifndef __LAB_03_LOADER_CREATOR_HPP__
#define __LAB_03_LOADER_CREATOR_HPP__

#include <memory>
#include "base_loader.hpp"

class LoaderCreator {
public:
    LoaderCreator() = default;

    virtual ~LoaderCreator() = default;

    virtual std::shared_ptr<BaseLoader> create() = 0;
};

template<typename LoaderType>
class ConLoaderCreator : public LoaderCreator {
public:
    ConLoaderCreator() = default;

    ~ConLoaderCreator() override = default;

    std::shared_ptr<BaseLoader> create() override {
        return std::make_shared<LoaderType>();
    }
};


#endif //__LAB_03_LOADER_CREATOR_HPP__
