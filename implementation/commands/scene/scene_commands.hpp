//
// Created by ivaaahn on 07.09.2021.
//

#ifndef __CG_COURSEWORK_SCENE_COMMANDS_HPP__
#define __CG_COURSEWORK_SCENE_COMMANDS_HPP__

#include "commands/command.hpp"
#include <memory>
#include "drawer/drawer.hpp"

class SceneCommand : public Command {};

class RenderScene : public SceneCommand {
public:
    RenderScene() = delete;

    explicit RenderScene(std::shared_ptr<Drawer> drawer);

    void execute() override;

    ~RenderScene() override = default;

private:
    std::shared_ptr<Drawer> drawer;
};

#endif //__CG_COURSEWORK_SCENE_COMMANDS_HPP__
