//
// Created by ivaaahn on 24.05.2021.
//

#ifndef __LAB_03_FILE_LOADER_HPP__
#define __LAB_03_FILE_LOADER_HPP__


#include <cstddef>
#include <string>
#include <memory>
#include <objects/model/figure.hpp>
#include <objects/camera/camera.hpp>
#include <objects/light/light.hpp>
#include <load/loaders/base/base_loader.hpp>


//class FileLoader : public BaseLoader {
//public:
//    FileLoader() = default;
//
//    void open(const std::string& filename) override;
//
//    void close() override;
//
//    virtual ~FileLoader() = default;
////    void loadPointsCount(size_t &count) override;
////
////    void loadPointCoords(double &x, double &y, double &z) override;
////
////    void loadEdgesCount(size_t &count) override;
////
////    void loadEdge(size_t &p1_id, size_t &p2_id) override;
//
//
//private:
//    std::shared_ptr<std::ifstream> srcFile;
//
//};


class FigureLoader : public BaseLoader {
public:
    FigureLoader() = default;

    virtual std::shared_ptr<Figure> load(const std::string& filename) = 0;
};

class CameraLoader : public BaseLoader {
public:

    CameraLoader() = default;

    ~CameraLoader() override = default;

    std::shared_ptr<Camera> load(const std::string& filename);
};

class LightLoader : public BaseLoader {
public:

    LightLoader() = default;

    ~LightLoader() override = default;

    std::shared_ptr<Light> load(const std::string& filename);
};


class SphereLoader : public FigureLoader {
public:
    std::shared_ptr<Figure> load(const std::string& filename) override;
    ~SphereLoader() override = default;
};

class AnyLoader : public FigureLoader {};

#endif //__LAB_03_FILE_LOADER_HPP__
