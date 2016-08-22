#ifndef RAYTRACER_SPHERE_H
#define RAYTRACER_SPHERE_H

#include "Object.h"

class Sphere : public Object {
public:
    double radius;
    Vector3 center;

    Vector3 getFirstIntersection (Ray) override;
    Vector3 getNormalAt(Vector3) override;

    Sphere(double, Vector3);
    Sphere(double);
};

#endif //RAYTRACER_SPHERE_H
