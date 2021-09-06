//
// Created by ivaaahn on 23.05.2021.
//

#include <managers/scene/scene_manager.hpp>
#include "remove_camera.hpp"

RemoveCamera::RemoveCamera(std::size_t camera_id) : camera_id(camera_id) {}

void RemoveCamera::execute() {
    auto scene = SceneManagerCreator().getManager()->getScene();
    auto it = scene->begin();

    std::advance(it, camera_id);
    scene->remove(it);
}
