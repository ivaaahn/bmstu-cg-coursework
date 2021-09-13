//
// Created by ivaaahn on 07.09.2021.
//

#include "light_commands.hpp"
#include "objects/light/light.hpp"
#include "managers/scene/scene_manager.hpp"
#include "managers/load/load_manager.hpp"
#include <memory>
#include "math/linalg.hpp"

using linalg::aliases::float3;

AddLight::AddLight(float xPos, float yPos, float zPos, float intensity) : xPos(xPos), yPos(yPos), zPos(zPos),
                                                                          intensity(intensity) {}

LoadLight::LoadLight(const std::string& filename) : filename(filename) {}


void AddLight::execute() {
    auto light = std::make_shared<Light>(float3{xPos, yPos, zPos}, intensity);

    auto sceneManager = SceneManagerCreator().getManager();
    auto scene = sceneManager->getScene();

    scene->addLight(light);
}

void LoadLight::execute() {
    auto loadManager = LoadManagerCreator().getManager();
    auto sceneManager = SceneManagerCreator().getManager();

    auto light = loadManager->lightLoad(this->filename);
    sceneManager->getScene()->addLight(light);
}
