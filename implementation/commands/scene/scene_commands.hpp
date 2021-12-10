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

class EditAmbientLightIntensity : public SceneCommand {
public:
    EditAmbientLightIntensity() = delete;

    explicit EditAmbientLightIntensity(float value);

    void execute() override;

    ~EditAmbientLightIntensity() override = default;

private:
    float value;
};

class EditRTreeHeightMax : public SceneCommand {
public:
    EditRTreeHeightMax() = delete;

    explicit EditRTreeHeightMax(int value): value(value) {}

    void execute() override;

    ~EditRTreeHeightMax() override = default;

private:
    int value;
};

class GetRTreeHeightMax : public SceneCommand {
public:
    GetRTreeHeightMax() = delete;

    explicit GetRTreeHeightMax(std::shared_ptr<int> &value): value(value) {}

    void execute() override;

    ~GetRTreeHeightMax() override = default;

private:
    std::shared_ptr<int> &value;
};

class GetAmbientLightIntensity : public SceneCommand {
public:
    GetAmbientLightIntensity() = delete;

    explicit GetAmbientLightIntensity(std::shared_ptr<float> &value);

    void execute() override;

    ~GetAmbientLightIntensity() override = default;

private:
    std::shared_ptr<float> &value;
};

#endif //__CG_COURSEWORK_SCENE_COMMANDS_HPP__
