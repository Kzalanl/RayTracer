/*
 * Sphere.cpp
 *
 *
 */
#include "Sphere.h"

#include <iostream>

namespace rt{

	Sphere::Sphere(Vec3f center, float radius):center(center), radius(radius){};

	Sphere::~Sphere()
	{
		std::cout<<"Sphere is destroyed :("<<std::endl;
	}

	void Sphere::printShape()
	{
		std::cout<<"I am a sphere!"<<std::endl;
		std::cout<<"radius: "<<radius<<", center: "<<center<<std::endl;
	}

	/**
	 * Computes whether a ray hit the specific instance of a sphere shape and returns the hit data
	 *
	 * @param ray cast ray to check for intersection with shape
	 *
	 * @return hit struct containing intersection information
	 *
	 */
	Hit Sphere::intersect(Ray ray){

		Hit h = Hit();
		//Quadratic formula for parametric line and sphere intersection
		Vec3f OC = ray.origin - center;
		float delta = ray.direction.dotProduct(OC);
		delta *= delta;
		delta -= OC.norm()-radius*radius;
		if(delta >= 0)
		{
			if(ray.raytype == RayType::SHADOW)
			{
				//Shady solution
				float scalar1 = ray.direction.dotProduct(OC)-sqrt(delta);
				float scalar2 = ray.direction.dotProduct(OC)+sqrt(delta);
				if( scalar1 > 0.01 || scalar2 > 0.01 )
				{
					h.unobstructed = true;
					return h;
				}
				else
				{
					h.unobstructed = false;
					return h;
				}
			}
			else
			{
				//Apply if ray is primary
				float linescalar = -ray.direction.dotProduct(OC)-sqrt(delta);
				Vec3f intersection = ray.origin + linescalar*ray.direction;
				Vec3f surfacenorm = (intersection - center).normalize();
				h = Hit{ intersection, linescalar, surfacenorm, material };
				h.unobstructed = false;
			}
		}
		return h;

	}



} //namespace rt


