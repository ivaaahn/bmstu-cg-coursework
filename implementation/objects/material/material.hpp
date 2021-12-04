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
    cl_float3 albedo;
    cl_float3 diffuseColor;
    cl_float specularExp;
} raw_material;


class Material {
private:
    float3 _albedo;
    float3 _diffuseColor;
    float _specularExp;

    void _readAlbedo(const std::shared_ptr<std::ifstream>& srcFile);

    void _readDiffuseColor(const std::shared_ptr<std::ifstream>& srcFile);

    void _readSpecularExp(std::shared_ptr<std::ifstream> srcFile);

public:
    Material(const float3& albedo, const float3& color, const float& spec) : _albedo(albedo), _diffuseColor(color),
                                                                             _specularExp(spec) {}


    Material() : _albedo(1, 0, 0), _diffuseColor(), _specularExp() {}

    explicit Material(const std::shared_ptr<std::ifstream>& srcFile);

    const float3& getAlbedo() {
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
                cl_float {_specularExp}
        };

//    [[nodiscard]] cl_float8 clFormat() const {
//        return {
//            cl_float(_albedo.x),
//            cl_float(_albedo.y),
//            cl_float(_albedo.z),
//            cl_float(_diffuseColor.x),
//            cl_float(_diffuseColor.y),
//            cl_float(_diffuseColor.z),
//            cl_float(_specularExp),
//            0
//        };
    }
};


#endif //__CG_COURSEWORK_MATERIAL_HPP__
