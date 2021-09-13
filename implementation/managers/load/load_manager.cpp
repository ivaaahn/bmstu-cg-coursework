//
// Created by ivaaahn on 24.05.2021.
//

#include <exceptions/load_exceptions.hpp>
#include "load_manager.hpp"


void LoadManager::setFigureLoader(const std::shared_ptr<FigureLoader>& loader) {
    this->figLoader = loader;
}

//std::shared_ptr<Object> LoadManager::load(const std::string &name) {
//    if (this->director == nullptr) throw NoDirectorError(__FILE__, __LINE__, "no directors");
//
//    return this->director->make(name);
//}

std::shared_ptr<Camera> LoadManager::cameraLoad(const string& filename) {
    return this->camLoader->load(filename);
}

std::shared_ptr<Figure> LoadManager::figureLoad(const string& filename) {
    return this->figLoader->load(filename);
}

LoadManager::LoadManager() {
    this->camLoader = std::make_shared<CameraLoader>();
    this->lightLoader = std::make_shared<LightLoader>();
}

std::shared_ptr<Light> LoadManager::lightLoad(const string& filename) {
    return this->lightLoader->load(filename);
}

void LoadManagerCreator::createManager() {
    static auto manager = std::make_shared<LoadManager>();
    this->manager = manager;
}

std::shared_ptr<LoadManager> LoadManagerCreator::getManager() {
    if (this->manager == nullptr) this->createManager();

    return this->manager;
}