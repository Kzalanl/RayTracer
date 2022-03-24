/*
 * Shape.cpp
 *
 */
#include "Shape.h"
#include "shapes/Sphere.h"
#include "shapes/Triangle.h"

//using namespace rapidjson;

namespace rt{

    Shape* Shape::createShape(Value& shapeSpec)
    {
        std::string type = shapeSpec["type"].GetString();
        if( type.compare("sphere") == 0 )
        {
            Vec3f center = Vec3f(
                shapeSpec["center"][0].GetFloat(),
                shapeSpec["center"][1].GetFloat(),
                shapeSpec["center"][2].GetFloat());

            float radius = shapeSpec["radius"].GetFloat();
            
            return new Sphere(center, radius);
        }
        if( type.compare("triangle") == 0 )
        {
            Vec3f v0 = Vec3f(
                shapeSpec["v0"][0].GetFloat(),
                shapeSpec["v0"][1].GetFloat(),
                shapeSpec["v0"][2].GetFloat());

            Vec3f v1 = Vec3f(
                shapeSpec["v1"][0].GetFloat(),
                shapeSpec["v1"][1].GetFloat(),
                shapeSpec["v1"][2].GetFloat());

            Vec3f v2 = Vec3f(
                shapeSpec["v2"][0].GetFloat(),
                shapeSpec["v2"][1].GetFloat(),
                shapeSpec["v2"][2].GetFloat());
            
            return new Triangle(v0, v1, v2);
        }
        if( type.compare("plane") == 0 )
        {
            Vec3f v0 = Vec3f(
                shapeSpec["v0"][0].GetFloat(),
                shapeSpec["v0"][1].GetFloat(),
                shapeSpec["v0"][2].GetFloat());

            Vec3f v1 = Vec3f(
                shapeSpec["v1"][0].GetFloat(),
                shapeSpec["v1"][1].GetFloat(),
                shapeSpec["v1"][2].GetFloat());

            Vec3f v2 = Vec3f(
                shapeSpec["v2"][0].GetFloat(),
                shapeSpec["v2"][1].GetFloat(),
                shapeSpec["v2"][2].GetFloat());
            
            Vec3f v3 = Vec3f(
                shapeSpec["v3"][0].GetFloat(),
                shapeSpec["v3"][1].GetFloat(),
                shapeSpec["v3"][2].GetFloat());

            return new Quad(v0, v1, v2, v3);
        }

    return 0;
    }



} //namespace rt

