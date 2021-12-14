//
// Created by ivaaahn on 24.05.2021.
//

#include "scene.hpp"


#define EPS 1e-5

Scene::Scene() = default;

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
    this->_models.erase(it);
}

void Scene::removeLight(const LightIterator& it) {
    this->_lights.erase(it);
}

LightIterator Scene::lightsBegin() {
    return this->_lights.begin();
}

LightIterator Scene::lightsEnd() {
    return this->_lights.end();
}

#define PLANE_Y 4
#define PLANE_X_BOUNDS 12
#define PLANE_Z_MIN (-30)
#define PLANE_Z_MAX 0

bool Scene::isIntersect(const std::shared_ptr<Ray>& ray, float3& hit, float3& N, Material& material) {
    float figuresDist = std::numeric_limits<float>::max();

    float currDist;
    float3 currN, currHit;


    for (const auto& model: this->_models)
    {
        if (model->rayIntersect(ray, currDist, currN, currHit) && currDist < figuresDist)
        {
            figuresDist = currDist;
            hit = currHit;
            N = currN;
            material = model->getMaterial();
        }
    }

    float checkerboard_dist = std::numeric_limits<float>::max();
    if (ray->dir.y > EPS || ray->dir.y < -EPS)
    {
        float d = -(ray->src.y + PLANE_Y) / ray->dir.y;     // the checkerboard plane has equation y = -1
        float3 pt = ray->src + ray->dir * d;

        if (d > EPS && fabs(pt.x) < PLANE_X_BOUNDS && pt.z < PLANE_Z_MAX && pt.z > PLANE_Z_MIN && d < figuresDist) {
            checkerboard_dist = d;
            hit = pt;
            N = {0, 1, 0};
            material.setDiffuseColor(((int)(0.5 * pt.x + 1000) + (int)(0.5 * pt.z)) & 1 ? float3{0.3, 0.3, 0.3} : float3{0.3, 0.2, 0.1});
            material.setAlbedo({0.2,0.5,0.3,0.0});
            material.setSpecularExp(2);
            material.setRefIdx(1);
        }
    }

    return std::min(figuresDist, checkerboard_dist) < 1000;
}
