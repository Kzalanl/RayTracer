/*
 * Scene.h
 *
 */

#ifndef SCENE_H_
#define SCENE_H_

#include <vector>

#include "rapidjson/document.h"
#include "RayHitStructs.h"
#include "core/LightSource.h"
#include "core/Shape.h"


using namespace rapidjson;

namespace rt{

class Scene {
public:

	Scene(){};

	void createScene(Value& sceneSpecs);

	void printScene();

	~Scene();

	Hit shootRay(Ray ray);

	Vec3f getBackground() {return backgroundcolor;};

	Vec3f illumination(Hit hit, Ray ray);

private:

	std::vector<LightSource*> lightSources;
	std::vector<Shape*> shapes;
	Vec3f backgroundcolor;

};

} //namespace rt



#endif /* SCENE_H_ */
