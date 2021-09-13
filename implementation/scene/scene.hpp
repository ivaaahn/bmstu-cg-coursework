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

class Scene {
public:
    Scene();

    ~Scene() = default;

    void addCamera(const std::shared_ptr<Camera>& cam);

    void removeCamera(const CamIterator& it);

    void addModel(const std::shared_ptr<Figure>& figure);

    void removeModel(const ModelIterator& it);

    void addLight(const std::shared_ptr<Light>& light);

    void removeLight(const LightIterator& it);

    bool isIntersect(const float3& src,
                     const float3& dir,
                     float3 hit,
                     float3& N,
                     Material& material);

    CamIterator camBegin();

    CamIterator camEnd();

    ModelIterator modelsBegin();

    ModelIterator modelsEnd();

    LightIterator lightsBegin();

    LightIterator lightsEnd();


//    void add(const std::shared_ptr<Object> &object);
//
//    void remove(const CamIterator &it);
//
//    CamIterator begin();
//
//    CamIterator end();
//
//    [[nodiscard]] ConstIterator begin() const;
//
//    [[nodiscard]] ConstIterator end() const;
//
//    [[nodiscard]] ConstIterator cbegin() const;
//
//    [[nodiscard]] ConstIterator cend() const;
//
    std::vector<std::shared_ptr<Light>> _lights;
    std::vector<std::shared_ptr<Camera>> _cameras;
    std::vector<std::shared_ptr<Figure>> _models;
    std::vector<ColorRGB> framebuffer;
//    std::shared_ptr<Object> obj;
};


#endif //__LAB_03_SCENE_HPP__
