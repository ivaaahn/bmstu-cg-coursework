//
// Created by ivaaahn on 06.09.2021.
//

#ifndef __CG_COURSEWORK_MATERIAL_HPP__
#define __CG_COURSEWORK_MATERIAL_HPP__

#include <memory>
#include "math/linalg.hpp"
#include <CL/cl.hpp>

using namespace linalg::aliases;

typedef struct __attribute__ ((packed)) _raw_material {
    cl_float4 albedo;           // ( Диффуз (Ламберт), Зерк. Отраж., Преломл.  )
    cl_float3 diffuseColor;     // Диффузное освещение
    cl_float specularExp;       // Степень, аппроксимирующая пространственное распределение зеркально отраженного света
    cl_float refIdx;            // Показатель преломления среды (для з. Снеллиуса)
    cl_float ambient;
} raw_material;


class Material {
private:
    float4 _albedo;
    float3 _diffuseColor;
    float _specularExp;
    float _refIdx; // Refractive index
    float _ambient;

    void _readAlbedo(const std::shared_ptr<std::ifstream>& srcFile);

    void _readDiffuseColor(const std::shared_ptr<std::ifstream>& srcFile);

    void _readSpecularExp(const std::shared_ptr<std::ifstream>& srcFile);

    void _readRefIdx(const std::shared_ptr<std::ifstream>& srcFile);

    void _readAmbient(const std::shared_ptr<std::ifstream>& srcFile);

public:

    Material() = default;

    Material(float ref_idx, const float4& albedo, const float3& color, float spec, float ambient) :
            _refIdx(ref_idx), _albedo(albedo), _diffuseColor(color), _specularExp(spec), _ambient(ambient) {}


    explicit Material(const std::shared_ptr<std::ifstream>& srcFile);

    const float4& getAlbedo() {
        return this->_albedo;
    }

    const float3& getDiffuseColor() {
        return this->_diffuseColor;
    }

    [[nodiscard]] float getSpecularExp() const {
        return this->_specularExp;
    }

    [[nodiscard]] raw_material clFormat() const {
        return {
                cl_float3{_albedo.x, _albedo.y, _albedo.z,},
                cl_float3{_diffuseColor.x, _diffuseColor.y, _diffuseColor.z},
                cl_float{_specularExp},
                cl_float{_refIdx},
                cl_float{_ambient}
        };
    }
};


#endif //__CG_COURSEWORK_MATERIAL_HPP__
