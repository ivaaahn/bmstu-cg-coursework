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

float3 RaysHandling::castRay(const float3& src, const float3& dir, const std::shared_ptr<Scene>& scene, size_t depth) {
    float3 hit, N;
    Material material;

    if (depth > 3 || !scene->isIntersect(src, dir, hit, N, material))
        return float3{0.2, 0.7, 0.8}; // background color

    float3 reflect_dir = normalize(RaysHandling::getReflectionVector(dir, N));

    // offset the original point to avoid occlusion by the object itself
    float3 reflectSrc = dot(reflect_dir, N) < 0 ? (hit - N * (float)1e-3) : (hit + N * (float)1e-3);

    auto reflect_color = RaysHandling::castRay(reflectSrc, reflect_dir, scene, depth + 1);

    float diffuse_light_intensity = 0, specular_light_intensity = 0;
    for (auto& light: scene->_lights)
    {
        float3 light_dir = normalize((light->getPosition() - hit));
        float light_distance = linalg::distance2(light->getPosition(), hit);

        // checking if the point lies in the shadow of the light
        float3 shadow_src = dot(light_dir, N) < 0 ? hit - N * (float)1e-3 : hit + N * (float)1e-3;
        float3 shadow_hit, shadow_N;
        Material tmp_material;
        if (scene->isIntersect(shadow_src, light_dir, shadow_hit, shadow_N, tmp_material) &&
            distance2(shadow_hit, shadow_src) < light_distance)
            continue;

        diffuse_light_intensity += light->getIntensity() * std::max(0.f, dot(light_dir, N));

        auto reflect_vector = RaysHandling::getReflectionVector(-light_dir, N);

        specular_light_intensity +=
                powf(std::max(0.f, linalg::dot(-reflect_vector, dir)), material.getSpecularExp()) *
                light->getIntensity();
    }

    auto alb = material.getAlbedo();

    return material.getDiffuseColor() * diffuse_light_intensity * alb[0]
           + float3(1.) * specular_light_intensity * alb[1]
           + reflect_color * alb[2];
}