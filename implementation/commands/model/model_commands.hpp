//
// Created by ivaaahn on 07.09.2021.
//

#ifndef __CG_COURSEWORK_MODEL_COMMANDS_HPP__
#define __CG_COURSEWORK_MODEL_COMMANDS_HPP__

#include <memory>
#include "commands/command.hpp"
#include "objects/model/figure.hpp"

class ModelCommand : public Command {};

class AddModel : public ModelCommand {
public:
    AddModel() = delete;

    explicit AddModel(std::shared_ptr<Figure> model);

    ~AddModel() override = default;

    void execute() override;

private:
    std::shared_ptr<Figure> model;
};

class LoadSphere : public ModelCommand {
public:
    LoadSphere() = delete;

    explicit LoadSphere(std::string filename);

    ~LoadSphere() override = default;

    void execute() override;

private:
    std::string filename;
};

class LoadTriangularModel : public ModelCommand {
public:
    LoadTriangularModel() = delete;

    explicit LoadTriangularModel(std::string filename);

    ~LoadTriangularModel() override = default;

    void execute() override;

private:
    std::string filename;
};

class TranslateModel : public ModelCommand {
public:
    TranslateModel() = delete;

    TranslateModel(size_t modelId, const float3& value);

    ~TranslateModel() override = default;

    void execute() override;

private:
    size_t modelId;
    float3 value;
};

class RemoveModel : public ModelCommand {
public:
    RemoveModel() = delete;

    explicit RemoveModel(size_t modelId);

    ~RemoveModel() override = default;

    void execute() override;

private:
    size_t value;
};

class RotateModel : public ModelCommand {
public:
    RotateModel() = delete;

    RotateModel(size_t modelId, const float3& value);

    ~RotateModel() override = default;

    void execute() override;

private:
    size_t modelId;
    float3 value;
};

class ScaleModel : public ModelCommand {
public:
    ScaleModel() = delete;

    ScaleModel(size_t modelId, const float3& value);

    ~ScaleModel() override = default;

    void execute() override;

private:
    size_t modelId;
    float3 value;
};

class GetModelInfo : public ModelCommand {
public:
    GetModelInfo() = delete;

    GetModelInfo(size_t modelId, std::shared_ptr<Material>& mat);

    ~GetModelInfo() override = default;

    void execute() override;

private:
    size_t modelId;
    std::shared_ptr<Material> &mat;
};

class EditModelMaterial : public ModelCommand {
public:
    EditModelMaterial() = delete;

    EditModelMaterial(size_t modelId, const Material& mat);

    ~EditModelMaterial() override = default;

    void execute() override;

private:
    size_t modelId;
    const Material &mat;
};

#endif //__CG_COURSEWORK_MODEL_COMMANDS_HPP__
