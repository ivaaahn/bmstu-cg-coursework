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
    cl_float4 albedo;           // ( Ka Kd Ks Kt  )
    cl_float3 diffuseColor;     // Диффузное освещение
    cl_float specularExp;       // Степень, аппроксимирующая пространственное распределение зеркально отраженного света
    cl_float refIdx;            // Показатель преломления среды (для з. Снеллиуса)
} raw_material;


class Material {
private:
    float4 _albedo;
    float3 _diffuseColor;
    float _specularExp;
    float _refIdx; // Refractive index

    void _readAlbedo(const std::shared_ptr<std::ifstream>& srcFile);

    void _readDiffuseColor(const std::shared_ptr<std::ifstream>& srcFile);

    void _readSpecularExp(const std::shared_ptr<std::ifstream>& srcFile);

    void _readRefIdx(const std::shared_ptr<std::ifstream>& srcFile);

public:

    Material() = default;

    Material(float ref_idx, const float4& albedo, const float3& color, float spec) :
            _refIdx(ref_idx), _albedo(albedo), _diffuseColor(color), _specularExp(spec) {}

    void setAlbedo(float4 value) { this->_albedo = value; }
    void setDiffuseColor(float3 value) { this->_diffuseColor = value; }
    void setSpecularExp(float value) { this->_specularExp = value; }
    void setRefIdx(float value) { this->_refIdx = value; }

    explicit Material(const std::shared_ptr<std::ifstream>& srcFile);

    [[nodiscard]] const float4& getAlbedo() const {
        return this->_albedo;
    }

    [[nodiscard]] const float3& getDiffuseColor() const {
        return this->_diffuseColor;
    }

    [[nodiscard]] float getSpecExp() const {
        return this->_specularExp;
    }

    [[nodiscard]] float getRefIdx() const {
        return this->_refIdx;
    }


    [[nodiscard]] float getSpecularExp() const {
        return this->_specularExp;
    }

    [[nodiscard]] raw_material clFormat() const {
        return {
                cl_float4{_albedo[0], _albedo[1], _albedo[2], _albedo[3]},
                cl_float3{_diffuseColor.x, _diffuseColor.y, _diffuseColor.z},
                cl_float{_specularExp},
                cl_float{_refIdx},
        };
    }
};


#endif //__CG_COURSEWORK_MATERIAL_HPP__
