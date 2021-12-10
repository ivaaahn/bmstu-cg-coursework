//
// Created by ivaaahn on 07.09.2021.
//

#include "model_commands.hpp"

#include <utility>
#include "managers/scene/scene_manager.hpp"
#include "managers/load/load_manager.hpp"

AddModel::AddModel(std::shared_ptr<Figure> model) : model(std::move(model)) {}

LoadTriangularModel::LoadTriangularModel(std::string filename) : filename(std::move(filename)) {}

RemoveModel::RemoveModel(size_t modelId) : value(modelId) {}

TranslateModel::TranslateModel(size_t modelId, const float3& value) : modelId(modelId), value(value) {}

RotateModel::RotateModel(size_t modelId, const float3& value) : modelId(modelId), value(value) {}

ScaleModel::ScaleModel(size_t modelId, const float3& value) : modelId(modelId), value(value) {}

LoadSphere::LoadSphere(std::string filename) : filename(std::move(filename)) {}

GetModelInfo::GetModelInfo(size_t modelId, std::shared_ptr<Material>& mat): modelId(modelId), mat(mat) {}



void AddModel::execute() {
    SceneManagerCreator().getManager()->getScene()->addModel(this->model);
}

void LoadSphere::execute() {
    auto load_manager = LoadManagerCreator().getManager();
    load_manager->setFigureLoader(std::make_shared<SphereLoader>());
    auto model = load_manager->figureLoad(this->filename);
    AddModel(model).execute();
}

void LoadTriangularModel::execute() {
    auto load_manager = LoadManagerCreator().getManager();
    load_manager->setFigureLoader(std::make_shared<TriangularModelLoader>());
    auto model = load_manager->figureLoad(this->filename);
    AddModel(model).execute();
}

void RemoveModel::execute() {
    auto scene = SceneManagerCreator().getManager()->getScene();
    auto modelsIt = scene->modelsBegin();
    std::advance(modelsIt, this->value);
    scene->removeModel(modelsIt);
}

void TranslateModel::execute() {
    auto sceneManager = SceneManagerCreator().getManager();
    auto modelsIt = sceneManager->getScene()->modelsBegin();

    std::advance(modelsIt, modelId);
    (*modelsIt)->translate(value);
}


void RotateModel::execute() {
    auto sceneManager = SceneManagerCreator().getManager();
    auto modelsIt = sceneManager->getScene()->modelsBegin();

    std::advance(modelsIt, modelId);
    (*modelsIt)->rotate(value);
}

void ScaleModel::execute() {
    auto sceneManager = SceneManagerCreator().getManager();
    auto modelsIt = sceneManager->getScene()->modelsBegin();

    std::advance(modelsIt, modelId);
    (*modelsIt)->scale(value);
}

void GetModelInfo::execute() {
    auto sceneManager = SceneManagerCreator().getManager();
    auto it = sceneManager->getScene()->modelsBegin();

    std::advance(it, this->modelId);

    *this->mat = (*it)->getMaterial();
}

EditModelMaterial::EditModelMaterial(size_t modelId, const Material &mat) : modelId(modelId), mat(mat) {}

void EditModelMaterial::execute() {
    auto sceneManager = SceneManagerCreator().getManager();
    auto it = sceneManager->getScene()->modelsBegin();

    std::advance(it, this->modelId);

    (*it)->editMaterial(mat);
}
