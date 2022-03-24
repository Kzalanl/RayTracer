/*
 * RayTracer.cpp
 *
 */
#include "RayTracer.h"


namespace rt{


/**
 * Performs ray tracing to render a photorealistic scene
 *
 * @param camera the camera viewing the scene
 * @param scene the scene to render, including objects and lightsources
 * @param nbounces the number of bounces to consider for raytracing
 *
 * @return a pixel buffer containing pixel values in linear RGB format
 */
Vec3f* RayTracer::render(Camera* camera, Scene* scene, int nbounces){

	Vec3f* pixelbuffer=new Vec3f[camera->getWidth()*camera->getHeight()];

	for(int y = 0; y<camera->getHeight(); y++)
	{
		for(int x = 0; x < camera->getWidth(); x++)
		{
			Ray * ray = camera->GenerateRay(Vec2i(x, y));
			Hit h = scene->shootRay(*ray);
			if( !h.unobstructed ) 
			{
				Vec3f color = scene->illumination(h, *ray);
				pixelbuffer[y*camera->getWidth() + x] = color;
			}
			else 
			{
				pixelbuffer[y*camera->getWidth() + x] = Vec3f(0,0,0);
			}
		}
	}



	return pixelbuffer;

}

/**
 * Tonemaps the rendered image (conversion of linear RGB values [0-1] to low dynamic range [0-255]
 *
 * @param pixelbuffer the array of size width*height containing linear RGB pixel values
 *
 * @return the tonemapped image
 */
Vec3f* RayTracer::tonemap(Vec3f* pixelbuffer, int size){
	for(int i = 0; i < size; i++)
	{
		*(pixelbuffer+i) *= 255;
		(pixelbuffer+i)->clip(0, 255);
	}
	return pixelbuffer;

}





} //namespace rt


