//
// Created by ivaaahn on 07.09.2021.
//

#include "camera_commands.hpp"
#include <memory>
#include <utility>
#include "objects/camera/camera.hpp"
#include "math/linalg.hpp"
#include "managers/scene/scene_manager.hpp"
#include "managers/load/load_manager.hpp"

using linalg::aliases::float3;

AddCamera::AddCamera(const float3& cords) : cords(cords) {}

//LoadCamera::LoadCamera(std::string filename) : filename(std::move(filename)) {}

MoveCamera::MoveCamera(size_t cameraId, const float3& cords) : cameraId(cameraId), cords(cords) {}

RemoveCamera::RemoveCamera(size_t cameraId) : cameraId(cameraId) {}

SetCamera::SetCamera(size_t newCameraId) : cameraId(newCameraId) {}

void AddCamera::execute() {
    auto sceneManager = SceneManagerCreator().getManager();
    auto scene = sceneManager->getScene();

    scene->addCamera(std::make_shared<Camera>(this->cords));
    sceneManager->setCurrentCamera(scene->camEnd() - 1);
}


//void LoadCamera::execute() {
//    auto loadManager = LoadManagerCreator().getManager();
//    auto sceneManager = SceneManagerCreator().getManager();
//
//    auto camera = loadManager->cameraLoad(this->filename);
//    sceneManager->getScene()->addCamera(camera);
//}


void MoveCamera::execute() {
    auto sceneManager = SceneManagerCreator().getManager();
    auto it = sceneManager->getScene()->camBegin();
    std::advance(it, this->cameraId);

    (*it)->shift(this->cords);
}


void RemoveCamera::execute() {
    auto scene = SceneManagerCreator().getManager()->getScene();
    auto it = scene->camBegin();

    std::advance(it, this->cameraId);
    scene->removeCamera(it);
}


void SetCamera::execute() {
    auto sceneManager = SceneManagerCreator().getManager();
    auto it = sceneManager->getScene()->camBegin();

    std::advance(it, this->cameraId);

    sceneManager->setCurrentCamera(it);
}

void GetLocation::execute() {
    auto sceneManager = SceneManagerCreator().getManager();
    auto it = sceneManager->getScene()->camBegin();

    std::advance(it, this->camId);

    *this->cords = (*it)->getPos();
}

