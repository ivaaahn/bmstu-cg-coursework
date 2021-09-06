//
// Created by ivaaahn on 26.05.2021.
//

#ifndef __LAB_03_SOLUTION_HPP__
#define __LAB_03_SOLUTION_HPP__

#include <map>
#include <cstddef>
#include <memory>
#include "load/loaders/loader_creator.hpp"


using CallbackMapObject = std::map<size_t, std::shared_ptr<LoaderCreator>>;

class Solution {
public:
    Solution() = default;

    ~Solution() = default;

    bool registerLoaderCreator(size_t id, const std::shared_ptr<LoaderCreator> &loader_creator);

    std::shared_ptr<LoaderCreator> getLoaderCreator(size_t id);

private:
    CallbackMapObject callbacks;
};


#endif //__LAB_03_SOLUTION_HPP__
