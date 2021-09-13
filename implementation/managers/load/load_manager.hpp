//
// Created by ivaaahn on 24.05.2021.
//

#ifndef __LAB_03_LOAD_MANAGER_HPP__
#define __LAB_03_LOAD_MANAGER_HPP__


#include <memory>
//#include <load/directors/load_director.hpp>
#include <load/loaders/loaders.hpp>
#include <objects/light/light.hpp>
#include "managers/manager.hpp"
#include "objects/object.hpp"

class LoadManager : public Manager {
public:
    LoadManager();

    LoadManager(const LoadManager&) = delete;

    LoadManager& operator=(const LoadManager&) = delete;

    ~LoadManager() override = default;

    std::shared_ptr<Camera> cameraLoad(const std::string& filename);
    std::shared_ptr<Light> lightLoad(const std::string& filename);
    std::shared_ptr<Figure> figureLoad(const std::string& filename);

//    virtual std::shared_ptr<Object> load(const std::string &name);

    void setFigureLoader(const std::shared_ptr<FigureLoader>& loader);

private:
    std::shared_ptr<FigureLoader> figLoader;
    std::shared_ptr<CameraLoader> camLoader;
    std::shared_ptr<LightLoader> lightLoader;
//    std::shared_ptr<LoadDirector> director;
};

class LoadManagerCreator {
public:
    std::shared_ptr<LoadManager> getManager();

private:
    void createManager();

    std::shared_ptr<LoadManager> manager;
};


#endif //__LAB_03_LOAD_MANAGER_HPP__
