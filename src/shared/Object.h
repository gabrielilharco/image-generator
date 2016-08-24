#ifndef RAYTRACER_OBJECT_H
#define RAYTRACER_OBJECT_H

#include "Vector3.h"
#include "Ray.h"
#include "Color.h"

enum Material {
    OPA,
    SPEC,
    REFR
};

class Object {
public:
    Material material;
    Color color;
    Color emissionColor;

    virtual double getFirstIntersection (const Ray& ray) = 0;
    virtual Vector3 getNormalAt(const Vector3 v) = 0;
};

#endif //RAYTRACER_OBJECT_H
