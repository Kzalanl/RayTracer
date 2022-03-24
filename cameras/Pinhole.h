/*
 * Pinhole.h
 *
 *
 */

#ifndef PINHOLE_H_
#define PINHOLE_H_

#include "core/Camera.h"
#include "math/geometry.h"

namespace rt{

class Pinhole:public Camera{
public:

	//
	// Constructors
	//
	Pinhole();
	Pinhole(int width, int height, int fov, 
			Vec3f position, Vec3f lookat);

	//
	//Destructor
	//
	~Pinhole();

	//
	// print function (implementing abstract function of base class)
	//
	void printCamera();

	Ray * GenerateRay(Vec2i film) override;
	
};



} //namespace rt




#endif /* PINHOLE_H_ */
