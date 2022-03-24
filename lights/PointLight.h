/*
 * PointLight.h
 *
 *
 */

#ifndef POINTLIGHT_H_
#define POINTLIGHT_H_

#include "core/LightSource.h"

namespace rt{

class PointLight: public LightSource{
public:

    PointLight(Vec3f position, Vec3f is, Vec3f id);

    ~PointLight();

    void printLightSource();

    Lighting sampleLi(Vec3f pointsurface) override;

    Ray pathToLight(Hit isect) override;

    Vec3f getPosition()
    {
        return position;
    };

private:
	Vec3f position;
	Vec3f is;
    Vec3f id;
};



} //namespace rt




#endif /* POINTLIGHT_H_ */
