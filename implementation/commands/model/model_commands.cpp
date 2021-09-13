//
// Created by ivaaahn on 07.09.2021.
//

#include "model_commands.hpp"
#include "managers/scene/scene_manager.hpp"
#include "managers/load/load_manager.hpp"

AddModel::AddModel(std::shared_ptr<Figure> model) : model(model) {}

LoadModel::LoadModel(const std::string& filename) : filename(filename) {}

MoveModel::MoveModel(size_t modelId, const float dx, const float dy, const float dz)
        : modelId(modelId), dx(dx), dy(dy), dz(dz) {}

RemoveModel::RemoveModel(size_t modelId) : modelId(modelId) {}

RotateModel::RotateModel(size_t modelId, const float ax, const float ay, const float az)
        : modelId(modelId), ax(ax), ay(ay), az(az) {}


ScaleModel::ScaleModel(size_t modelId, const float kx, const float ky, const float kz)
        : modelId(modelId), kx(kx), ky(ky), kz(kz) {}

TransformModel::TransformModel(size_t modelId, const float3& move, const float3& scale, const float3& rotate)
        : modelId(modelId), move(move), scale(scale), rotate(rotate) {}

LoadSphere::LoadSphere(const std::string& filename) : filename(filename) {}


//CountModels::CountModels(std::shared_ptr<size_t> &count) : count(count) {}
//
//void CountModels::execute() {
//    *(this->count) = SceneManagerCreator().getManager()->getScene()->getModelsCount();
//}
//

void AddModel::execute() {
    SceneManagerCreator().getManager()->getScene()->addModel(this->model);
}

void LoadModel::execute() {
//    auto load_manager = LoadManagerCreator().getManager();
//    load_manager->setFigureLoader(std::make_shared<>())
//
//    load_manager->setDirector(std::make_shared<ModelDirector>());
//
//    auto model = load_manager->load(filename);
//    SceneManagerCreator().getManager()->getScene()->add(model);
}

void LoadSphere::execute() {
    auto load_manager = LoadManagerCreator().getManager();
    load_manager->setFigureLoader(std::make_shared<SphereLoader>());
    auto model = load_manager->figureLoad(this->filename);
    AddModel(model).execute();
}

void RemoveModel::execute() {
    auto scene = SceneManagerCreator().getManager()->getScene();
    auto modelsIt = scene->modelsBegin();
    std::advance(modelsIt, this->modelId);
    scene->removeModel(modelsIt);
}

void MoveModel::execute() {
    float3 move{this->dx, this->dy, this->dz};
    float3 scale{1};
    float3 rotate{};
    TransformModel(this->modelId, move, scale, rotate).execute();
}


void RotateModel::execute() {
    float3 move{};
    float3 scale{1};
    float3 rotate{this->ax, this->ay, this->az};
    TransformModel(this->modelId, move, scale, rotate).execute();
}


void ScaleModel::execute() {
    float3 move(0, 0, 0);
    float3 scale(this->kx, this->ky, this->kz);
    float3 rotate(0, 0, 0);
    TransformModel(this->modelId, move, scale, rotate).execute();
}


void TransformModel::execute() {
    auto sceneManager = SceneManagerCreator().getManager();
    auto modelsIt = sceneManager->getScene()->modelsBegin();

    std::advance(modelsIt, modelId);
    (*modelsIt)->transform(move, scale, rotate);
}

