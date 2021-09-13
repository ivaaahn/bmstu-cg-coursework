//
// Created by ivaaahn on 07.09.2021.
//

#ifndef __CG_COURSEWORK_RAYS_HPP__
#define __CG_COURSEWORK_RAYS_HPP__

class RaysHandling {
    static float3
    cast_ray(const float3& src,
             const float3& dir,
             const std::vector <Sphere>& spheres,
             const std::vector <Light>& lights,
             size_t depth = 0
    )
};

float3
cast_ray(const float3& src, const float3& dir, const std::vector <Sphere>& spheres, const std::vector <Light>& lights,
         size_t depth = 0) {
    float3 hit, N;
    Material material;

    if (depth > 3 || !scene_intersect(src, dir, spheres, hit, N, material))
    {
        return float3{0.2, 0.7, 0.8}; // background color
    }

    float3 reflect_dir = linalg::normalize(get_reflection_vector(dir, N));

    // offset the original point to avoid occlusion by the object itself
    float3 reflect_orig = linalg::dot(reflect_dir, N) < 0 ? (hit - N * (float)1e-3) : (hit + N * (float)1e-3);
    auto reflect_color = cast_ray(reflect_orig, reflect_dir, spheres, lights, depth + 1);

    float diffuse_light_intensity = 0, specular_light_intensity = 0;
    for (auto light: lights)
    {
        float3 light_dir = normalize((light.position - hit));
        float light_distance = linalg::distance2(light.position, hit);

        // checking if the point lies in the shadow of the light
        float3 shadow_src = linalg::dot(light_dir, N) < 0 ? hit - N * (float)1e-3 : hit + N * (float)1e-3;
        float3 shadow_hit, shadow_N;
        Material tmp_material;
        if (scene_intersect(shadow_src, light_dir, spheres, shadow_hit, shadow_N, tmp_material) &&
            linalg::distance2(shadow_hit, shadow_src) < light_distance)
            continue;

        diffuse_light_intensity += light.intensity * std::max(0.f, linalg::dot(light_dir, N));

        auto reflect_vector = get_reflection_vector(-light_dir, N);
        specular_light_intensity +=
                powf(std::max(0.f, linalg::dot(-reflect_vector, dir)), material.specular_exponent) *
                light.intensity;
    }

    return material.diffuse_color * diffuse_light_intensity * material.albedo[0] +
           float3(1.) * specular_light_intensity * material.albedo[1] + reflect_color * material.albedo[2];
}

#endif //__CG_COURSEWORK_RAYS_HPP__
