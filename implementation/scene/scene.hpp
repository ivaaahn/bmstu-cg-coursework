//
// Created by ivaaahn on 24.05.2021.
//

#ifndef __LAB_03_SCENE_HPP__
#define __LAB_03_SCENE_HPP__


#include <memory>
#include <objects/object.hpp>
#include <objects/light/light.hpp>
#include <objects/model/figure.hpp>
#include "objects/camera/camera.hpp"

using CamIterator = std::vector<std::shared_ptr<Camera>>::iterator;
using ModelIterator = std::vector<std::shared_ptr<Figure>>::iterator;
using LightIterator = std::vector<std::shared_ptr<Light>>::iterator;

#define ALI_DEFAULT 0.5 // Ambient Light Intensity
#define RTREE_HEIGHT_MAX 1

class Scene {
public:
    Scene();

    ~Scene() = default;

    [[nodiscard]] float getAmbientLightIntensity() const { return this->ambient_light_intensity.x; }

    void setAmbientLightIntensity(float value) { this->ambient_light_intensity = float3{value}; }

    [[nodiscard]] int getRTreeHeightMax() const { return this->ray_tree_height_max; }

    void setRTreeHeightMax(int value) { this->ray_tree_height_max = value; }

    void addCamera(const std::shared_ptr<Camera>& cam);

    void removeCamera(const CamIterator& it);

    void addModel(const std::shared_ptr<Figure>& figure);

    void removeModel(const ModelIterator& it);

    void addLight(const std::shared_ptr<Light>& light);

    void removeLight(const LightIterator& it);

    bool isIntersect(const std::shared_ptr<Ray>& ray,
                     float3& hit,
                     float3& N,
                     Material& material);

    CamIterator camBegin();

    CamIterator camEnd();

    ModelIterator modelsBegin();

    ModelIterator modelsEnd();

    LightIterator lightsBegin();
    LightIterator lightsEnd();

    std::vector<std::shared_ptr<Light>> _lights;
    std::vector<std::shared_ptr<Camera>> _cameras;
    std::vector<std::shared_ptr<Figure>> _models;
    std::vector<ColorRGB> framebuffer;

    float3 ambient_light_intensity{ALI_DEFAULT, ALI_DEFAULT, ALI_DEFAULT};
    int ray_tree_height_max = RTREE_HEIGHT_MAX;
};


#endif //__LAB_03_SCENE_HPP__
