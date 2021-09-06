//
// Created by ivaaahn on 24.05.2021.
//

#include "file_loader.hpp"

#include <fstream>
#include <exceptions/load_exceptions.hpp>
#include <memory>

void FileLoader::open(const std::string &src_name) {
    this->src_file = std::make_shared<std::ifstream>(src_name);

    if (!*(this->src_file))
        throw FileOpenError(__FILE__, __LINE__, "could not open model-file");
}

void FileLoader::close() {
    this->src_file->close();
}

void FileLoader::loadPointsCount(size_t &count) {
    size_t tmp_count = 0;

    if (!(*src_file >> tmp_count))
        throw FileFormatError(__FILE__, __LINE__, "invalid model-file format");

    if (tmp_count < 1)
        throw FileFormatError(__FILE__, __LINE__, "number of points is invalid");

    count = tmp_count;
}


void FileLoader::loadEdgesCount(size_t &count) {
    size_t tmp_count = 0;

    if (!(*src_file >> tmp_count))
        throw FileFormatError(__FILE__, __LINE__, "invalid model-file format");

    if (tmp_count <= 1)
        throw FileFormatError(__FILE__, __LINE__, "number of edges is invalid");

    count = tmp_count;
}


void FileLoader::loadPointCoords(double &x, double &y, double &z) {
    double tmp_x, tmp_y, tmp_z;
    if (!(*src_file >> tmp_x >> tmp_y >> tmp_z))
        throw FileFormatError(__FILE__, __LINE__, "invalid model-file format");

    x = tmp_x, y = tmp_y, z = tmp_z;
}

void FileLoader::loadEdge(size_t &p1_id, size_t &p2_id) {
    size_t tmp_p1_id, tmp_p2_id;

    if (!(*src_file >> tmp_p1_id >> tmp_p2_id))
        throw FileFormatError(__FILE__, __LINE__, "invalid model-file format");

    p1_id = tmp_p1_id, p2_id = tmp_p2_id;
}