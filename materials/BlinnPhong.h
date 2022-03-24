/*
 * BlinnPhong.h
 *
 *
 */

#ifndef BLINNPHONG_H_
#define BLINNPHONG_H_

#include "core/Material.h"


namespace rt{

class BlinnPhong: public Material{
public:
    BlinnPhong(){};
    BlinnPhong(float ks, float kd, float specularexponent, Vec3f diffuse_color):
    ks(ks), kd(kd), specularexp(specularexponent), diffusecolor(diffuse_color){};

    ~BlinnPhong(){};

    Vec3f paint(Vec3f surfacenorm, Vec3f incomingRay, Vec3f lightRay, Lighting lighting) override; 




//Getters and setters
    float getKs()
    {
        return ks;
    }

    void setKs(float kspecular)
    {
        ks = kspecular;
    }

    float getKd()
    {
        return kd;
    }


    void setKd( float kdiffuse)
    {
        kd = kdiffuse;
    }

private:
    float ks;
    float kd;
    float specularexp;
    Vec3f diffusecolor;

};



} //namespace rt



#endif /* BLINNPHONG_H_ */
