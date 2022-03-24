/*
 * Material.cpp
 *
 */
#include "Material.h"
#include "materials/BlinnPhong.h"

namespace rt{


    Material * Material::createMaterial(Value& materialSpecs)
    {
        //if (materialSpecs.HasMember("")){
	    //}
        
        float ks = materialSpecs["ks"].GetFloat();
        float kd = materialSpecs["kd"].GetFloat();
        float specular = materialSpecs["specularexponent"].GetFloat();
        Vec3f diffusecolor = Vec3f(
                    materialSpecs["diffusecolor"][0].GetFloat(),
                    materialSpecs["diffusecolor"][1].GetFloat(),
                    materialSpecs["diffusecolor"][2].GetFloat());

        return new BlinnPhong(ks,ks, specular, diffusecolor);
    }


} //namespace rt


