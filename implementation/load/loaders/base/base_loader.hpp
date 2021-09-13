//
// Created by ivaaahn on 07.09.2021.
//

#ifndef __CG_COURSEWORK_BASE_LOADER_HPP__
#define __CG_COURSEWORK_BASE_LOADER_HPP__


#include <objects/model/figure.hpp>
#include <memory>
#include <fstream>

class BaseLoader {
public:
    BaseLoader() = default;

    virtual ~BaseLoader() = default;

    virtual void open(const std::string& filename);

    virtual void close();

protected:
    std::shared_ptr<std::ifstream> srcFile;
};


#endif //__CG_COURSEWORK_BASE_LOADER_HPP__
