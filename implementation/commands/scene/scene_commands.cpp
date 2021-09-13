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

    drawManager->setCamera(sceneManager->getMainCamera());
    drawManager->setDrawer(this->drawer);

//    this->drawer->clearScene();
    drawManager->draw(sceneManager->getScene());
}