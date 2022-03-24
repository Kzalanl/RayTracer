/*
 * PointLight.cpp
 *
 *
 */
#include "PointLight.h"

#include <iostream>


namespace rt{

PointLight::PointLight(Vec3f position, Vec3f is, Vec3f id):
                LightSource(), position(position), is(is), id(id)
{

}

PointLight::~PointLight()
{
    std::cout<<"Pointlight destroyed :("<<std::endl;
}

void PointLight::printLightSource()
{
    printf("I am a pointlight!\n");
}

Lighting PointLight::sampleLi(Vec3f surfacepoint)
{
    float factor = 1/(surfacepoint - position).length();
    return Lighting{ is*factor, id*factor };
}

Ray PointLight::pathToLight(Hit isect)
{
    Vec3f direction = position - isect.point;
    return Ray{ RayType::SHADOW, isect.point, direction.normalize() };
}

} //namespace rt
