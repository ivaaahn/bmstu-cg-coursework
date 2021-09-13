//
// Created by ivaaahn on 24.05.2021.
//

#include <fstream>
#include <exceptions/load_exceptions.hpp>
#include <memory>
#include <objects/model/sphere.hpp>
#include <objects/light/light.hpp>
#include "loaders.hpp"

//void FileLoader::loadPointsCount(size_t &count) {
//    size_t tmp_count = 0;
//
//    if (!(*srcFile >> tmp_count))
//        throw FileFormatError(__FILE__, __LINE__, "invalid model-file format");
//
//    if (tmp_count < 1)
//        throw FileFormatError(__FILE__, __LINE__, "number of points is invalid");
//
//    count = tmp_count;
//}
//
//
//void FileLoader::loadEdgesCount(size_t &count) {
//    size_t tmp_count = 0;
//
//    if (!(*srcFile >> tmp_count))
//        throw FileFormatError(__FILE__, __LINE__, "invalid model-file format");
//
//    if (tmp_count <= 1)
//        throw FileFormatError(__FILE__, __LINE__, "number of edges is invalid");
//
//    count = tmp_count;
//}
//
//
//void FileLoader::loadPointCoords(double &x, double &y, double &z) {
//    double tmp_x, tmp_y, tmp_z;
//    if (!(*srcFile >> tmp_x >> tmp_y >> tmp_z))
//        throw FileFormatError(__FILE__, __LINE__, "invalid model-file format");
//
//    x = tmp_x, y = tmp_y, z = tmp_z;
//}
//
//void FileLoader::loadEdge(size_t &p1_id, size_t &p2_id) {
//    size_t tmp_p1_id, tmp_p2_id;
//
//    if (!(*srcFile >> tmp_p1_id >> tmp_p2_id))
//        throw FileFormatError(__FILE__, __LINE__, "invalid model-file format");
//
//    p1_id = tmp_p1_id, p2_id = tmp_p2_id;
//}
std::shared_ptr<Figure> SphereLoader::load(const std::string &filename) {
    this->open(filename);

    auto fig = std::make_shared<Sphere>(this->srcFile);

    this->close();

    return fig;
}

std::shared_ptr<Camera> CameraLoader::load(const string& filename) {
    this->open(filename);

    auto cam = std::make_shared<Camera>(this->srcFile);

    this->close();

    return cam;
}

std::shared_ptr<Light> LightLoader::load(const string &filename) {
    this->open(filename);

    auto light = std::make_shared<Light>(this->srcFile);

    this->close();

    return light;
}