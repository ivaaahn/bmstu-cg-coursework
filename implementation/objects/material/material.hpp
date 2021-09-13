//
// Created by ivaaahn on 06.09.2021.
//

#ifndef __CG_COURSEWORK_MATERIAL_HPP__
#define __CG_COURSEWORK_MATERIAL_HPP__

#include <memory>
#include "math/linalg.hpp"

using namespace linalg::aliases;

class Material {
public:
    Material(const float3& albedo, const float3& color, const float& spec) : _albedo(albedo), _diffuseColor(color),
                                                                             _specularExp(spec) {}


    Material() : _albedo(1, 0, 0), _diffuseColor(), _specularExp() {}


    explicit Material(std::shared_ptr<std::ifstream> srcFile);

    const float3& getAlbedo() {
        return this->_albedo;
    }

    const float3& getDiffuseColor() {
        return this->_diffuseColor;
    }

    [[nodiscard]] float getSpecularExp() const {
        return this->_specularExp;
    }


private:
    float3 _albedo;
    float3 _diffuseColor;
    float _specularExp;

    void _readAlbedo(std::shared_ptr<std::ifstream> srcFile);
    void _readDiffuseColor(std::shared_ptr<std::ifstream> srcFile);
    void _readSpecularExp(std::shared_ptr<std::ifstream> srcFile);
};


#endif //__CG_COURSEWORK_MATERIAL_HPP__
