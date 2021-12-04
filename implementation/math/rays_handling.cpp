//
// Created by ivaaahn on 07.09.2021.
//

#include "rays_handling.hpp"
#include <cstddef>
#include <iostream>

using namespace linalg;

float3 RaysHandling::getReflectionVector(const float3& I, const float3& N) {
    return I - N * 2.f * linalg::dot(I, N);
}

float3 RaysHandling::castRayCPU(const std::shared_ptr<Ray> &ray, const std::shared_ptr<Scene>& scene, size_t depth) {
    float3 hit, N;
    Material material;

    if (depth > 3 || !scene->isIntersect(ray, hit, N, material))
//    if (!scene->isIntersect(ray, hit, N, material))
        return float3{0.2, 0.7, 0.8}; // background color

//    float3 reflectDir = normalize(RaysHandling::getReflectionVector(ray->dir, N));

    // offset the original point to avoid occlusion by the object itself
//    float3 reflectSrc = dot(reflectDir, N) < 0 ? (hit - N * (float)1e-3) : (hit + N * (float)1e-3);

//    auto reflect_color = RaysHandling::castRayCPU(std::make_shared<Ray>(reflectSrc, reflectDir), scene, depth + 1);

    float diffuseLightIntensity = 0, specularLightIntensity = 0;
    for (const auto &light: scene->_lights)
    {
        float3 lightDir = normalize((light->getPosition() - hit));
        float lightDist = linalg::distance2(light->getPosition(), hit);

        // checking if the point lies in the shadow of the light
        float3 shadowSrc = dot(lightDir, N) < 0 ? hit - N * (float)1e-3 : hit + N * (float)1e-3;
        float3 shadowHit, shadowN;
        Material tmpMaterial;
        if (scene->isIntersect(std::make_shared<Ray>(shadowSrc, lightDir), shadowHit, shadowN, tmpMaterial) &&
            distance2(shadowHit, shadowSrc) < lightDist)
            continue;

        diffuseLightIntensity += light->getIntensity() * std::max(0.f, dot(lightDir, N));

        auto reflect_vector = RaysHandling::getReflectionVector(-lightDir, N);

        specularLightIntensity +=
                powf(std::max(0.f, linalg::dot(-reflect_vector, ray->dir)), material.getSpecularExp()) *
                light->getIntensity();
    }

    auto alb = material.getAlbedo();

    return material.getDiffuseColor() * diffuseLightIntensity * alb[0]
           + float3(1.) * specularLightIntensity * alb[1];
//             + reflect_color * alb[2];
}


float3 RaysHandling::castRayGPU(const std::shared_ptr<Ray> &ray, const std::shared_ptr<Scene>& scene, size_t depth) {
    float3 hit, N;
    Material material;

//    if (depth > 3 || !scene->isIntersect(ray, hit, N, material))
    if (!scene->isIntersect(ray, hit, N, material))
        return float3{0.2, 0.7, 0.8}; // background color
    else
        return float3{0.4, 0.4, 0.3};

//    float3 reflectDir = normalize(RaysHandling::getReflectionVector(ray->dir, N));
//
//    // offset the original point to avoid occlusion by the object itself
//    float3 reflectSrc = dot(reflectDir, N) < 0 ? (hit - N * (float)1e-3) : (hit + N * (float)1e-3);
//
//    auto reflect_color = RaysHandling::castRay(std::make_shared<Ray>(reflectSrc, reflectDir), scene, depth + 1);
//
//    float diffuseLightIntensity = 0, specularLightIntensity = 0;
//    for (auto& light: scene->_lights)
//    {
//        float3 lightDir = normalize((light->getPosition() - hit));
//        float lightDist = linalg::distance2(light->getPosition(), hit);
//
//        // checking if the point lies in the shadow of the light
//        float3 shadowSrc = dot(lightDir, N) < 0 ? hit - N * (float)1e-3 : hit + N * (float)1e-3;
//        float3 shadowHit, shadowN;
//        Material tmpMaterial;
//        if (scene->isIntersect(std::make_shared<Ray>(shadowSrc, lightDir), shadowHit, shadowN, tmpMaterial) &&
//            distance2(shadowHit, shadowSrc) < lightDist)
//            continue;
//
//        diffuseLightIntensity += light->getIntensity() * std::max(0.f, dot(lightDir, N));
//
//        auto reflect_vector = RaysHandling::getReflectionVector(-lightDir, N);
//
//        specularLightIntensity +=
//                powf(std::max(0.f, linalg::dot(-reflect_vector, ray->dir)), material.getSpecularExp()) *
//                light->getIntensity();
//    }
//
//    auto alb = material.getAlbedo();
//
//    return material.getDiffuseColor() * diffuseLightIntensity * alb[0]
//           + float3(1.) * specularLightIntensity * alb[1]
//           + reflect_color * alb[2];
}