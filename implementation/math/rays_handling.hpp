//
// Created by ivaaahn on 07.09.2021.
//

#ifndef __CG_COURSEWORK_RAYS_HANDLING_HPP__
#define __CG_COURSEWORK_RAYS_HANDLING_HPP__

#include "linalg.hpp"
#include "scene/scene.hpp"

using namespace linalg::aliases;

class RaysHandling {
public:
    static float3 castRayGPU(const std::shared_ptr<Ray> &ray,
                          const std::shared_ptr<Scene> &scene,
                          size_t depth = 0);

    static float3 castRayCPU(const std::shared_ptr<Ray> &ray,
                          const std::shared_ptr<Scene> &scene,
                          size_t depth = 0);

private:
    static float3 getReflectionVec(const float3 &I, const float3 &N);
    static float3 getRefractionVec(const float3 &I, const float3 &N, float eta_t, float eta_i=1.f);
};


#endif //__CG_COURSEWORK_RAYS_HANDLING_HPP__
