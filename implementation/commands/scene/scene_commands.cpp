//
// Created by ivaaahn on 07.09.2021.
//

#include "scene_commands.hpp"
#include "managers/scene/scene_manager.hpp"
#include "managers/draw/draw_manager.hpp"

RenderScene::RenderScene(std::shared_ptr<Drawer> drawer) : drawer(std::move(drawer)) {}

void RenderScene::execute() {
    auto sceneManager = SceneManagerCreator().getManager();
    auto drawManager = DrawManagerCreator().getManager();

    drawManager->setDrawer(this->drawer);

    drawManager->draw(sceneManager->getScene(), sceneManager->getMainCamera());
}

EditAmbientLightIntensity::EditAmbientLightIntensity(float value) : value(value) {}

void EditAmbientLightIntensity::execute() {
    auto sceneManager = SceneManagerCreator().getManager();
    sceneManager->getScene()->setAmbientLightIntensity(this->value);
}

GetAmbientLightIntensity::GetAmbientLightIntensity(std::shared_ptr<float>& value) : value(value) {}

void GetAmbientLightIntensity::execute() {
    auto sceneManager = SceneManagerCreator().getManager();
    *this->value = sceneManager->getScene()->getAmbientLightIntensity();
}


void EditRTreeHeightMax::execute() {
    auto sceneManager = SceneManagerCreator().getManager();
    sceneManager->getScene()->setRTreeHeightMax(this->value);
}

void GetRTreeHeightMax::execute() {
    auto sceneManager = SceneManagerCreator().getManager();
    *this->value = sceneManager->getScene()->getRTreeHeightMax();
}
