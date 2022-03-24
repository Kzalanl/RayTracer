/*
 * LightSource.cpp
 *
 */
#include "LightSource.h"
#include "lights/PointLight.h"

namespace rt{

    LightSource * LightSource::createLightSource(Value& lightSpecs)
    {
        Vec3f pos = Vec3f(
                lightSpecs["position"][0].GetFloat(),
                lightSpecs["position"][1].GetFloat(),
                lightSpecs["position"][2].GetFloat());

        Vec3f is = Vec3f(
                lightSpecs["is"][0].GetFloat(),
                lightSpecs["is"][1].GetFloat(),
                lightSpecs["is"][2].GetFloat());

        Vec3f id = Vec3f(
                lightSpecs["id"][0].GetFloat(),
                lightSpecs["id"][1].GetFloat(),
                lightSpecs["id"][2].GetFloat());

        
        return new PointLight(pos, is, id);
    }



} //namespace rt

