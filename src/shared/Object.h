#ifndef RAYTRACER_OBJECT_H
#define RAYTRACER_OBJECT_H

#include "Vector3.h"
#include "Ray.h"

class Object {
public:
    virtual Vector3 getFirstIntersection (Ray) = 0;
    virtual Vector3 getNormalAt(Vector3) = 0;
};

#endif //RAYTRACER_OBJECT_H
