/*
 * Shape.h
 *
 */

#ifndef SHAPE_H_
#define SHAPE_H_

#include "core/RayHitStructs.h"
#include "core/Material.h"
#include "rapidjson/document.h"

using namespace rapidjson;

namespace rt{

class Shape{
public:

	//
	// Constructors
	//
	Shape(){};

	static Shape* createShape(Value& shapeSpec);

	void attachMaterial(Value& materialSpecs)
	{
		material = Material::createMaterial(materialSpecs);
	}

	//
	// Destructor (must be overriden in subclass)
	//
	~Shape()
	{ delete material; };

	virtual void printShape()=0;

	//
	// Shape abstract methods (to be implemented by subclasses)
	//
	virtual Hit intersect(Ray ray)=0;



protected:

	Material * material;

};


} //namespace rt


#endif /* SHAPE_H_ */
