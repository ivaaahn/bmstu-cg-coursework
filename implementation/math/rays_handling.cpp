//
// Created by ivaaahn on 07.09.2021.
//

#include "rays_handling.hpp"
#include <cstddef>

using namespace linalg;

float3 RaysHandling::getReflectionVec(const float3& I, const float3& N) {
    return I - N * 2.f * linalg::dot(I, N);
}

float3 RaysHandling::getRefractionVec(const float3& I, const float3& N, const float eta_t, const float eta_i) {
    float cosi = -std::max(-1.f, std::min(1.f, dot(I, N)));
    if (cosi < 0)  // if the ray comes from the inside the object, swap the air and the media
        return RaysHandling::getRefractionVec(I, -N, eta_i, eta_t);
    float eta = eta_i / eta_t;
    float k = 1 - eta * eta * (1 - cosi * cosi);
    return k < 0 ? float3{1, 0, 0} : I * eta + N * (eta * cosi - sqrtf(k));
}


#define COLOR_R 60.
#define COLOR_G 41.
#define COLOR_B 105.

float3 RaysHandling::castRayCPU(const std::shared_ptr<Ray>& ray, const std::shared_ptr<Scene>& scene, size_t depth) {
    float3 hit, N;
    Material material;

    if (depth > scene->ray_tree_height_max || !scene->isIntersect(ray, hit, N, material))
        return float3{COLOR_R/255, COLOR_G/255, COLOR_B/255} * scene->ambient_light_intensity; // background color

    float3 reflectDir = normalize(RaysHandling::getReflectionVec(ray->dir, N));
    float3 refractDir = normalize(RaysHandling::getRefractionVec(ray->dir, N, material.getRefIdx()));

    float3 reflectSrc = dot(reflectDir, N) < 0 ? hit - N * (float)1e-3 : hit + N * (float)1e-3;
    float3 refractSrc = dot(refractDir, N) < 0 ? hit - N * (float)1e-3 : hit + N * (float)1e-3;

    float3 reflectColor = RaysHandling::castRayCPU(std::make_shared<Ray>(reflectSrc, reflectDir), scene, depth + 1);
    float3 refractColor = RaysHandling::castRayCPU(std::make_shared<Ray>(refractSrc, refractDir), scene, depth + 1);

    float DLI = 0, SLI = 0;
    for (const auto& light: scene->_lights) {
        float3 lightDir = normalize((light->getPos() - hit));

        // checking if the point lies in the shadow of the light
        float3 shadowSrc = dot(lightDir, N) < 0 ? hit - N * (float)1e-3 : hit + N * (float)1e-3;

        float currDLI = light->getIntensity() * std::max(0.f, dot(lightDir, N));
        float currSLI = powf(std::max(0.f, linalg::dot(-RaysHandling::getReflectionVec(-lightDir, N), ray->dir)), material.getSpecularExp()) *
                        light->getIntensity();

        Material shadowMaterial;
        float3 shadowHit, shadowN;
        if (scene->isIntersect(std::make_shared<Ray>(shadowSrc, lightDir), shadowHit, shadowN, shadowMaterial) &&
            distance2(shadowHit, shadowSrc) < linalg::distance2(light->getPos(), hit)) {
            currDLI *= shadowMaterial.getAlbedo()[3];
            currSLI *= shadowMaterial.getAlbedo()[3];
        }

        DLI += currDLI;
        SLI += currSLI;
    }

    auto alb = material.getAlbedo();

    return float3{scene->ambient_light_intensity} * alb[0] + material.getDiffuseColor() * DLI * alb[1] +
           float3{1.} * SLI * alb[2] + reflectColor * alb[2] + refractColor * alb[3];
}


float3 RaysHandling::castRayGPU(const std::shared_ptr<Ray>& ray, const std::shared_ptr<Scene>& scene, size_t depth) {return float3{0.};}
