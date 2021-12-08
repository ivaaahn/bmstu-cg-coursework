//
// Created by ivaaahn on 07.09.2021.
//

#include "light_commands.hpp"
#include "objects/light/light.hpp"
#include "managers/scene/scene_manager.hpp"
#include "managers/load/load_manager.hpp"
#include <memory>


void AddLight::execute() {
    auto sceneManager = SceneManagerCreator().getManager();
    auto scene = sceneManager->getScene();
    scene->addLight(std::make_shared<Light>(this->cords, this->intensity));
}

void LoadLight::execute() {
    auto loadManager = LoadManagerCreator().getManager();
    auto sceneManager = SceneManagerCreator().getManager();
    sceneManager->getScene()->addLight(loadManager->lightLoad(this->filename));
}

void RemoveLight::execute() {
    auto scene = SceneManagerCreator().getManager()->getScene();
    auto it = scene->lightsBegin();

    std::advance(it, this->lightId);
    scene->removeLight(it);
}