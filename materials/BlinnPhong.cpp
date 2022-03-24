/*
 * BlinnPhong.cpp
 *
 *
 */

#include "BlinnPhong.h"



namespace rt{

    Vec3f BlinnPhong::paint(Vec3f surfacenorm, Vec3f viewdirection, Vec3f lightdirection, Lighting lighting)
    {
        Vec3f color = Vec3f();
        color = color 
			+  kd*lighting.diffuse*(lightdirection.dotProduct(surfacenorm));
			//Blinn-Phong model
			Vec3f halfangle = (lightdirection - viewdirection).normalize();
			color = color 
			+  ks*lighting.specular*pow(halfangle.dotProduct(surfacenorm),specularexp);
        return color;
    }



} //namespace rt
