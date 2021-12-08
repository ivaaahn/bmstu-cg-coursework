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

//class CountModels : public ModelCommand {
//public:
//    CountModels() = delete;
//
//    explicit CountModels(std::shared_ptr<size_t> &count);
//
//    ~CountModels() override = default;
//
//    void execute() override;
//
//private:
//    std::shared_ptr<size_t> &count;
//};

//class LoadModel : public ModelCommand {
//public:
//    LoadModel() = delete;
//
//    explicit LoadModel(std::string filename);
//
//    ~LoadModel() override = default;
//
//    void execute() override;
//
//private:
//    std::string filename;
//};


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

//class TransformModel : public ModelCommand {
//public:
//    TransformModel() = delete;
//
//    TransformModel(size_t value, const float3& move, const float3& scale, const float3& rotate);
//
//    ~TransformModel() override = default;
//
//    void execute() override;
//
//private:
//    size_t value;
//
//    float3 move, scale, rotate;
//};

#endif //__CG_COURSEWORK_MODEL_COMMANDS_HPP__
