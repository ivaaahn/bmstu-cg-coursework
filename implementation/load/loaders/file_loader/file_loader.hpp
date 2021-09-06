//
// Created by ivaaahn on 24.05.2021.
//

#ifndef __LAB_03_FILE_LOADER_HPP__
#define __LAB_03_FILE_LOADER_HPP__


#include <cstddef>
#include <string>
#include <memory>
#include "load/loaders/base_loader.hpp"


class FileLoader : public BaseLoader {
public:
    FileLoader() = default;

    void open(const std::string &src_name) override;

    void loadPointsCount(size_t &count) override;

    void loadPointCoords(double &x, double &y, double &z) override;

    void loadEdgesCount(size_t &count) override;

    void loadEdge(size_t &p1_id, size_t &p2_id) override;

    void close() override;

private:
    std::shared_ptr<std::ifstream> src_file;

};


#endif //__LAB_03_FILE_LOADER_HPP__
