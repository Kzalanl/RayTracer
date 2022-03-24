/*
 * Scene.cpp
 *
 */
#include "Scene.h"
#include <iostream>


namespace rt{


/**
 * Parses json scene object to generate scene to render
 *
 * @param scenespecs the json scene specificatioon
 */
void Scene::createScene(Value& sceneSpecs){
	
	//----------parse json object to populate scene-----------
	float R = sceneSpecs["backgroundcolor"][0].GetFloat();
	float G = sceneSpecs["backgroundcolor"][1].GetFloat();
	float B = sceneSpecs["backgroundcolor"][2].GetFloat();
	backgroundcolor = Vec3f(R, G, B);

	Value& lights = sceneSpecs["lightsources"];
	
	for (SizeType i = 0; i < lights.Size(); i++)
	{
		lightSources.push_back(
			LightSource::createLightSource(lights[i])
		);
	}
	
	Value& shapeSpecs = sceneSpecs["shapes"];
	
	for (SizeType i = 0; i < shapeSpecs.Size(); i++)
	{
		//For now only creates a sphere
		std::string shapeType = shapeSpecs[i]["type"].GetString();
        
		if(shapeType.compare("sphere") == 0)
			shapes.push_back(
				Shape::createShape(shapeSpecs[i])
			);
		
		if(shapeType.compare("triangle") == 0)
			shapes.push_back(
				Shape::createShape(shapeSpecs[i])
			);
		
		
		if(shapeType.compare("plane") == 0 )
		{
			shapes.push_back(
				Shape::createShape(shapeSpecs[i])
			);
		}
		
		
		if (shapeSpecs[i].HasMember("material")){
			shapes[i]->attachMaterial(shapeSpecs[i]["material"]);
		}
	}

}

Scene::~Scene()
{
	std::cout<<"Scene is destroyed :("<<std::endl;
	for(int i=0; i < lightSources.size(); i++)
	delete lightSources[i];
	for(int i=0; i < shapes.size(); i++)
	delete shapes[i];
}
void Scene::printScene(){
	std::cout<<"Printing the scene:"<<std::endl;
	for(int i=0; i < lightSources.size(); i++)
	lightSources[i]->printLightSource();
	for(int i=0; i < shapes.size(); i++)
	shapes[i]->printShape();
	std::cout<<"-----Printing finished-------"<<std::endl;
}

Hit Scene::shootRay(Ray ray)
{
	/*Intersection with scene*/
	Hit besthit = Hit();
	for(int i=0; i < shapes.size(); i++)
	{
		Hit hit = shapes[i]->intersect(ray);
		if( besthit.unobstructed && !hit.unobstructed )
		{
			besthit = hit;
		}
		if ( !hit.unobstructed && (hit.distance < besthit.distance) )
		{
			besthit = hit;
		}
	}
	return besthit;
}

Vec3f Scene::illumination(Hit isect, Ray ray)
{
	Vec3f color = backgroundcolor;
	for(int i=0; i < lightSources.size(); i++)
	{
		Ray directLight = lightSources[i]->pathToLight(isect);
		Hit visibility = shootRay(directLight);
		if( visibility.unobstructed )
		/*True if no obstruction in path*/
		{
			Lighting lighting = lightSources[i]->sampleLi(isect.point);
			color = color + isect.color->paint(isect.surfacenorm, ray.direction, directLight.direction, lighting);
		}
	}
	color=color.clip( 0, 100 ) * 0.01;
	return color;
}



} //namespace rt
