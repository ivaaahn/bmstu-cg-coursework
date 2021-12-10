//
// Created by ivaaahn on 07.09.2021.
//

#ifndef __CG_COURSEWORK_LIGHT_COMMANDS_HPP__
#define __CG_COURSEWORK_LIGHT_COMMANDS_HPP__

#include <string>
#include <memory>

#include "commands/command.hpp"
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

class GetLightInfo : public LightCommand {
public:
    GetLightInfo() = delete;

    GetLightInfo(size_t lightId, std::shared_ptr<float3>& cords, std::shared_ptr<float>& intens) :
            lightId(lightId), cords(cords), intens(intens) {}

    ~GetLightInfo() override = default;

    void execute() override;

private:
    std::size_t lightId;
    std::shared_ptr<float3>& cords;
    std::shared_ptr<float>& intens;
};

class EditLight : public LightCommand {
public:
    EditLight() = delete;

    EditLight(size_t lightId, const float3 &cords, float intens);

    ~EditLight() override = default;

    void execute() override;

private:
    std::size_t lightId;
    const float3 &cords;
    float intens;
};

#endif //__CG_COURSEWORK_LIGHT_COMMANDS_HPP__
