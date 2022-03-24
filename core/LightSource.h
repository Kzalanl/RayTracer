/*
 * LightSource.h
 *
 */

#ifndef LIGHTSOURCE_H_
#define LIGHTSOURCE_H_

#include "rapidjson/document.h"
#include "RayHitStructs.h"

using namespace rapidjson;

namespace rt{

class LightSource{
public:

    static LightSource * createLightSource(Value& lightSpecs);

    LightSource(){};

    virtual ~LightSource(){};

    virtual void printLightSource() = 0;

    virtual Lighting sampleLi(Vec3f pointsurface) = 0;

    virtual Ray pathToLight(Hit isect) = 0;

private:

};

} //namespace rt



#endif /* LIGHTSOURCE_H_ */
