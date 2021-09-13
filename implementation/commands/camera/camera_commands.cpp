//
// Created by ivaaahn on 07.09.2021.
//

#include "camera_commands.hpp"
#include <memory>
#include "objects/camera/camera.hpp"
#include "math/linalg.hpp"
#include "managers/scene/scene_manager.hpp"
#include "managers/load/load_manager.hpp"

using linalg::aliases::float3;

AddCamera::AddCamera(float xPos, float yPos, float zPos) : xPos(xPos), yPos(yPos), zPos(zPos) {}

LoadCamera::LoadCamera(const std::string& filename) : filename(std::move(filename)) {}

MoveCamera::MoveCamera(size_t cameraId, float shiftX, float shiftY, float shiftZ = 0)
        : cameraId(cameraId), shiftX(shiftX), shiftY(shiftY), shiftZ(shiftZ) {}

RemoveCamera::RemoveCamera(size_t cameraId) : cameraId(cameraId) {}

SetCamera::SetCamera(size_t newCameraId) : cameraId(newCameraId) {}

void AddCamera::execute() {
    auto camera = std::make_shared<Camera>(float3{xPos, yPos, zPos});

    auto sceneManager = SceneManagerCreator().getManager();
    auto scene = sceneManager->getScene();

    scene->addCamera(camera);
    sceneManager->setCurrentCamera(scene->camEnd() - 1);
}


void LoadCamera::execute() {
    auto loadManager = LoadManagerCreator().getManager();
    auto sceneManager = SceneManagerCreator().getManager();

    auto camera = loadManager->cameraLoad(this->filename);
    sceneManager->getScene()->addCamera(camera);
}


void MoveCamera::execute() {
    auto sceneManager = SceneManagerCreator().getManager();
    auto it = sceneManager->getScene()->camBegin();
    std::advance(it, this->cameraId);

    (*it)->shift(float3{this->shiftX, this->shiftY, this->shiftZ});
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


//CountCameras::CountCameras(std::shared_ptr<size_t> &count) : count(count) {}
//
//void CountCameras::execute() {
//    *(this->count) = SceneManagerCreator().getManager()->getScene()->getCamerasCount();
//}
//