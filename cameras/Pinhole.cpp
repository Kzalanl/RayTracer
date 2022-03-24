/*
 * Pinhole.cpp
 *
 *
 */
#include <iostream>

#include "Pinhole.h"



namespace rt{

	//
	// Pinhole constructor (example)
	//
	Pinhole::Pinhole(int width, int height, int fov,
				Vec3f position, Vec3f lookat):
					Camera(width, height, fov, position, lookat){}

	Pinhole::~Pinhole(){
		std::cout<<"Pinhole is destroyed :("<<std::endl;
	}

	/**
	 * Prints camera data
	 * this function implements the abstract function of the base Camera class
	 */
	void Pinhole::printCamera(){
		printf("I am a pinhole camera! \n");
		printf("width: %dpx, height: %dpx, fov:%d \n", width, height, fov);
	}

	Ray * Pinhole::GenerateRay(Vec2i film)
	{
		Vec3f direction = lookat + (film.x-width/2)*cameraX + (film.y-height/2)*cameraY;
		
		Ray * ray = new Ray{ RayType::PRIMARY, position, direction.normalize()};

		return ray;
	}



} //namespace rt