//
// Created by ivaaahn on 24.05.2021.
//

#include "scene.hpp"

#include <utility>
#include "objects/composite/composite.hpp"

Scene::Scene() : obj(std::make_shared<Composite>()) {}

void Scene::add(const std::shared_ptr<Object> &object) {
    this->obj->add(object);

//    if (obj->is_visible())
//        this->models_count++;
//    else
//        this->cameras_count++;
}

void Scene::remove(const Iterator &it) {
//    if((*it)->is_visible())
//        this->models_count--;
//    else
//        this->cameras_count--;

    this->obj->remove(it);
}

//size_t Scene::getCamerasCount() const {
//    return this->cameras_count;
//}
//
//size_t Scene::getModelsCount() const {
//    return this->models_count;
//}

Iterator Scene::begin() {
    return this->obj->begin();
}

Iterator Scene::end() {
    return this->obj->end();
}
//
//void Scene::accept(std::shared_ptr<Visitor> visitor) {
//    this->obj->accept(std::move(visitor));
//}

ConstIterator Scene::cbegin() const {
    return this->obj->cbegin();
}

ConstIterator Scene::cend() const {
    return this->obj->cend();
}


ConstIterator Scene::begin() const {
    return this->obj->cbegin();
}

ConstIterator Scene::end() const {
    return this->obj->cend();
}
