/*
 * Material.h
 *
 */

#ifndef MATERIAL_H_
#define MATERIAL_H_

#include "math/geometry.h"
#include "rapidjson/document.h"
#include "Lighting.h"

using namespace rapidjson;

namespace rt{

class Material{
public:

    Material(){};

    ~Material(){};

    static Material * createMaterial(Value& materialSpecs);

    virtual Vec3f paint(Vec3f surfacenorm, Vec3f incomingRay, Vec3f lightRay, Lighting lighting)=0; 

    
private:

};


} //namespace rt



#endif /* MATERIAL_H_ */
