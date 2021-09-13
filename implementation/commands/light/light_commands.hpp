//
// Created by ivaaahn on 07.09.2021.
//

#ifndef __CG_COURSEWORK_LIGHT_COMMANDS_HPP__
#define __CG_COURSEWORK_LIGHT_COMMANDS_HPP__

#include "commands/command.hpp"
#include <string>

class LightCommand : public Command {};

class AddLight : public LightCommand{
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
    explicit LoadLight (const std::string &filename);

    void execute() override;

private:
    std::string filename;
};


#endif //__CG_COURSEWORK_LIGHT_COMMANDS_HPP__
