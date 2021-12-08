//
// Created by ivaaahn on 07.09.2021.
//

#ifndef __CG_COURSEWORK_LIGHT_COMMANDS_HPP__
#define __CG_COURSEWORK_LIGHT_COMMANDS_HPP__

#include "commands/command.hpp"
#include <string>
#include "math/linalg.hpp"

using namespace linalg::aliases;


class LightCommand : public Command {};

class AddLight : public LightCommand {
public:
    AddLight() = delete;

    AddLight(const float3& cords, float intens) : cords(cords), intensity(intens) {}

    ~AddLight() override = default;

    void execute() override;

private:
    float3 cords;
    float intensity;
};

class LoadLight : public LightCommand {
public:
    explicit LoadLight(std::string filename) : filename(std::move(filename)) {}

    void execute() override;

private:
    std::string filename;
};

class RemoveLight : public LightCommand {
public:
    explicit RemoveLight(std::size_t lightId) : lightId(lightId) {}

    void execute() override;

private:
    std::size_t lightId;
};

#endif //__CG_COURSEWORK_LIGHT_COMMANDS_HPP__
