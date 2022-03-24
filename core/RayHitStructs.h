/*
 * RayHitStructs.h
 */

#ifndef CORE_RAYHITSTRUCTS_H_
#define CORE_RAYHITSTRUCTS_H_

#include "math/geometry.h"
#include "Material.h"
namespace rt{

/*
 * Ray structure definition
 */
enum RayType {PRIMARY, SECONDARY, SHADOW};

struct Ray{

	Ray():raytype(RayType::SHADOW), origin(Vec3f()), direction(Vec3f()){};
	Ray(RayType raytype, Vec3f origin, Vec3f direction): raytype(raytype), origin(origin), direction(direction){};

	RayType raytype;
	Vec3f origin;
	Vec3f direction;
};


struct Hit{

	Hit():point(Vec3f()), distance(0), surfacenorm(Vec3f()), unobstructed(true){};
	Hit(Vec3f point, float distance, Vec3f a, Material * material):point(point), distance(distance)
		, surfacenorm(a), color(material), unobstructed(true){};

	Vec3f point;
	float distance;
	Vec3f surfacenorm;
	Material * color;

	bool unobstructed;

};

}


#endif /* CORE_RAYHITSTRUCTS_H_ */
