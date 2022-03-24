/*
 * Triangle.h
 *
 *
 */

#ifndef TRIANGLE_H_
#define TRIANGLE_H_

#include "core/Shape.h"

namespace rt{

class Triangle: public Shape{
public:
    Triangle(): v0(Vec3f()), v1(Vec3f()), v2(Vec3f()){};

    Triangle(Vec3f v0, Vec3f v1, Vec3f v2);

    ~Triangle();

    Hit intersect(Ray ray);

    void printShape() override;

    Vec3f getSurface()
    {
        return planenormal;
    };

    void setMaterial(Material * material);

private:
    Vec3f v0;
    Vec3f v1;
    Vec3f v2;
    Vec3f planenormal;
};

/********************************************************/
//Plane quad consisting of two triangles with common edge
class Quad:public Shape{
public:
    Quad():t1(Triangle()), t2(Triangle()){};

    Quad(Vec3f v0, Vec3f v1, Vec3f v2, Vec3f v3);

    ~Quad();

    Hit intersect(Ray ray);

    void printShape() override;

private:
   Triangle t1;
   Triangle t2; 
};



} //namespace rt




#endif /* TRIANGLE_H_ */
