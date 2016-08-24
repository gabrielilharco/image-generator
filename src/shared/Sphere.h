#ifndef RAYTRACER_SPHERE_H
#define RAYTRACER_SPHERE_H

#include "Object.h"

class Sphere : public Object {
public:
    double radius;
    Vector3 center;

    double getFirstIntersection (const Ray& ray) override;
    Vector3 getNormalAt(Vector3 v) override;

    Sphere(double, Vector3);
    Sphere(double);
};

#endif //RAYTRACER_SPHERE_H
