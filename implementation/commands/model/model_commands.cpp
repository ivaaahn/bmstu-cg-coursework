//
// Created by ivaaahn on 07.09.2021.
//

#include "model_commands.hpp"

#include <utility>
#include "managers/scene/scene_manager.hpp"
#include "managers/load/load_manager.hpp"

AddModel::AddModel(std::shared_ptr<Figure> model) : model(std::move(model)) {}

//LoadModel::LoadModel(std::string filename) : filename(std::move(filename)) {}

LoadTriangularModel::LoadTriangularModel(std::string filename) : filename(std::move(filename)) {}

RemoveModel::RemoveModel(size_t modelId) : value(modelId) {}

TranslateModel::TranslateModel(size_t modelId, const float3& value) : modelId(modelId), value(value) {}

RotateModel::RotateModel(size_t modelId, const float3& value) : modelId(modelId), value(value) {}

ScaleModel::ScaleModel(size_t modelId, const float3& value) : modelId(modelId), value(value) {}

//TransformModel::TransformModel(size_t modelId, const float3& move, const float3& scale, const float3& rotate)
//        : modelId(modelId), move(move), scale(scale), rotate(rotate) {}

LoadSphere::LoadSphere(std::string filename) : filename(std::move(filename)) {}


//CountModels::CountModels(std::shared_ptr<size_t> &count) : count(count) {}
//
//void CountModels::execute() {
//    *(this->count) = SceneManagerCreator().getManager()->getScene()->getModelsCount();
//}
//

void AddModel::execute() {
    SceneManagerCreator().getManager()->getScene()->addModel(this->model);
}

//void LoadModel::execute() {
////    auto load_manager = LoadManagerCreator().getManager();
////    load_manager->setFigureLoader(std::make_shared<>())
////
////    load_manager->setDirector(std::make_shared<ModelDirector>());
////
////    auto model = load_manager->load(filename);
////    SceneManagerCreator().getManager()->getScene()->add(model);
//}

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


//void TransformModel::execute() {
//    auto sceneManager = SceneManagerCreator().getManager();
//    auto modelsIt = sceneManager->getScene()->modelsBegin();
//
//    std::advance(modelsIt, value);
//    (*modelsIt)->transform(move, scale, rotate);
//}

