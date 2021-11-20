//
// Created by ivaaahn on 24.05.2021.
//

#include "scene.hpp"

#include <utility>
//#include "objects/composite/composite.hpp"

Scene::Scene() {}

//void Scene::add(const std::shared_ptr<Object> &object) {
//    this->obj->add(object);

//    if (obj->is_visible())
//        this->models_count++;
//    else
//        this->cameras_count++;
//}

//void Scene::remove(const CamIterator &it) {
//    if((*it)->is_visible())
//        this->models_count--;
//    else
//        this->cameras_count--;

//    this->obj->remove(it);
//}

//size_t Scene::getCamerasCount() const {
//    return this->cameras_count;
//}
//
//size_t Scene::getModelsCount() const {
//    return this->models_count;
//}

CamIterator Scene::camBegin() {
    return this->_cameras.begin();
}

CamIterator Scene::camEnd() {
    return this->_cameras.end();
}

ModelIterator Scene::modelsBegin() {
    return this->_models.begin();
}

ModelIterator Scene::modelsEnd() {
    return this->_models.end();
}
//
//CamIterator Scene::end() {
//    return this->obj->end();
//}
//
//void Scene::accept(std::shared_ptr<Visitor> visitor) {
//    this->obj->accept(std::move(visitor));
//}
//
//ConstIterator Scene::cbegin() const {
//    return this->obj->cbegin();
//}
//
//ConstIterator Scene::cend() const {
//    return this->obj->cend();
//}
//
//
//ConstIterator Scene::begin() const {
//    return this->obj->cbegin();
//}
//
//ConstIterator Scene::end() const {
//    return this->obj->cend();
//}

void Scene::addCamera(const std::shared_ptr<Camera>& cam) {
    this->_cameras.push_back(cam);
}

void Scene::addModel(const std::shared_ptr<Figure>& figure) {
    this->_models.push_back(figure);
}

void Scene::addLight(const std::shared_ptr<Light>& light) {
    this->_lights.push_back(light);
}

void Scene::removeCamera(const CamIterator& it) {
    this->_cameras.erase(it);
}

void Scene::removeModel(const ModelIterator& it) {
    //TODO
}

void Scene::removeLight(const LightIterator& it) {
//    TODO
}

LightIterator Scene::lightsBegin() {
    return this->_lights.begin();
}

LightIterator Scene::lightsEnd() {
    return this->_lights.end();
}

bool Scene::isIntersect(const std::shared_ptr<Ray>& ray, float3& hit, float3& N, Material& material) {
    float dist = std::numeric_limits<float>::max();

    float currDist;
    float3 currN, currHit;

    for (const auto& model: this->_models)
    {
        if (model->rayIntersect(ray, currDist, currN, currHit) && currDist < dist)
        {
            dist = currDist;
            hit = currHit;
            N = currN;
            material = model->getMaterial();
        }
    }
    return dist < 1000; // TODO ?
}
