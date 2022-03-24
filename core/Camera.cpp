/*
 * Camera.cpp
 *
 */
#include <iostream>

#include "Camera.h"
#include "cameras/Pinhole.h"
#include "cameras/ThinLens.h"

namespace rt{

	Camera::~Camera(){};


	Camera::Camera(int height, int width, int fov, Vec3f position, Vec3f lookat):height(height), width(width), fov(fov),
	position(position), lookat(lookat)
	{
		Vec3f z = Vec3f(0,0,1);
		float pixelsize = 2*lookat.length()*std::tan(float(fov*180/3.141592654)/2.0)/sqrt(width*width + height*height);
		Vec3f cX = lookat.crossProduct(z);
		Vec3f cY = lookat.crossProduct(cX);
		cameraY = cY.normalize()*pixelsize;
		cameraX = cX.normalize()*pixelsize;
	};

/**
 * Factory function that returns camera subclass based on camera specifications
 *
 * @param cameraSpecs camera specifications json object
 *
 * @return camera subclass instance
 *
 */
Camera* Camera::createCamera(Value& cameraSpecs){
	//check if cameratype is defined
	if (!cameraSpecs.HasMember("type")){
		std::cerr<<"Camera type not specified"<<std::endl;
		exit(-1);
	}
	std::string cameraType=cameraSpecs["type"].GetString();

	//return camera object based on camera specs
	if (cameraType.compare("pinhole")==0){

		Vec3f lookat = Vec3f(
				cameraSpecs["lookat"][0].GetFloat(),
				cameraSpecs["lookat"][1].GetFloat(),
				cameraSpecs["lookat"][2].GetFloat());

		Vec3f pos = Vec3f(
				cameraSpecs["position"][0].GetFloat(),
				cameraSpecs["position"][1].GetFloat(),
				cameraSpecs["position"][2].GetFloat());

		return new Pinhole(
				cameraSpecs["width"].GetInt(),
				cameraSpecs["height"].GetInt(),
				cameraSpecs["fov"].GetInt(),
				pos, lookat);

	}else if (cameraType.compare("thinlens")==0){
		return new ThinLens(0,0,0, Vec3f(), Vec3f());
	}

	return 0;

}



} //namespace rt
