//
// Created by ivaaahn on 07.09.2021.
//

#ifndef __CG_COURSEWORK_LIGHT_COMMANDS_HPP__
#define __CG_COURSEWORK_LIGHT_COMMANDS_HPP__

#include "commands/command.hpp"
#include <string>

class LightCommand : public Command {};

class AddLight : public LightCommand {
public:
    AddLight() = delete;

    AddLight(float xPos, float yPos, float zPos, float intensity);

    ~AddLight() override = default;

    void execute() override;

private:
    float xPos, yPos, zPos, intensity;
};

class LoadLight : public LightCommand {
public:
    explicit LoadLight (std::string filename);

    void execute() override;

private:
    std::string filename;
};

class RemoveLight : public LightCommand {
public:
    explicit RemoveLight(std::size_t lightId);

    void execute() override;

private:
    std::size_t lightId;
};

#endif //__CG_COURSEWORK_LIGHT_COMMANDS_HPP__
