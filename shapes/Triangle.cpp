/*
 * Triangle.cpp
 *
 *
 */
#include "Triangle.h"
#include <iostream>


namespace rt{

    Triangle::Triangle(Vec3f v0, Vec3f v1, Vec3f v2):v0(v0), v1(v1), v2(v2)
    {
        planenormal = (v1-v0).crossProduct(v2-v0).normalize();
    };

    Triangle::~Triangle()
    {
        std::cout<<"Triangle is destroyed :("<<std::endl;
    }


    //
    //Object intersection
    //
    Hit Triangle::intersect(Ray ray)
    {
        
        //Triangle intersection adapted from: https://www.scratchapixel.com/lessons/3d-basic-rendering/ray-tracing-rendering-a-triangle/ray-triangle-intersection-geometric-solution   
        Vec3f N = (v1-v0).crossProduct(v2-v0);
        float parallelism = (v0-ray.origin).dotProduct(ray.direction);
        
        float factor = 1.0;
        if( parallelism > 0 )
        {
            factor = -1.0;
        }
        if( ray.raytype == RayType::SHADOW )
        {
            return Hit();
        }
        /*
        if ( -0.001 < parallelism && parallelism < 0.001 )
        {
            return Hit();
        }
        */

        float planedistance = N.dotProduct(v0);
        float scalar = factor*(N.dotProduct(ray.origin) - planedistance) / 
                    N.dotProduct(ray.direction);
        
        //Plane is behind origin point of ray
        if( scalar < 0.001 )
            return Hit();


        //Inside test
        Vec3f ipoint = ray.origin+scalar*ray.direction;
        Vec3f edge0 = v1 -v0;
        Vec3f edge1 = v2 -v1;
        Vec3f edge2 = v0 -v2;
        Vec3f C0 = ipoint - v0;
        Vec3f C1 = ipoint - v1;
        Vec3f C2 = ipoint - v2;
        if (!(N.dotProduct(edge0.crossProduct(C0)) > 0 && 
              N.dotProduct(edge1.crossProduct(C1)) > 0 && 
              N.dotProduct(edge2.crossProduct(C2)) > 0))
        {
            return Hit();
        }
        Hit h = Hit(ipoint, scalar, N.normalize(), material);
        h.unobstructed = false;

        

        return h;
    };


    void Triangle::setMaterial(Material * material)
    {
        this->material = material;
    };


    void Triangle::printShape()
    {
		std::cout<<"I am a Triangle!"<<std::endl;
		std::cout<<"Vertices: "<<v0<<v1<<v2<<std::endl;
    };

/***********************************************************/
/*********************CLASS*QUAD****************************/
    Quad::Quad(Vec3f v0, Vec3f v1, Vec3f v2, Vec3f v3):
        t1(Triangle(v0, v1, v2)), t2(Triangle(v2, v3, v0))
    {
        t1.setMaterial(material);
        t2.setMaterial(material);
    };

    Quad::~Quad()
    {

        std::cout<<"Quad is destroyed, soon my childern will fall!"<<std::endl;
    };

    Hit Quad::intersect(Ray ray)
    {
        Hit h1 = t1.intersect(ray);
        if( h1.unobstructed )
            {
                Hit h2 = t2.intersect(ray);
                h2.surfacenorm *= -1;
                return h2;
            }
        h1.surfacenorm *= -1;
        return h1;
    };

    void Quad::printShape()
    {
        std::cout<<"My triangles are: "<<std::endl;
        t1.printShape();
        t2.printShape();
        std::cout<<"*************"<<std::endl;
    };


} //namespace rt
