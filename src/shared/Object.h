#ifndef RAYTRACER_OBJECT_H
#define RAYTRACER_OBJECT_H

#include "Vector3.h"
#include "Ray.h"

class Object {
public:
    virtual Vector3 getFirstIntersection (const Ray& ray) = 0;
    virtual Vector3 getNormalAt(const Vector3 v) = 0;
};

#endif //RAYTRACER_OBJECT_H
