#ifndef RAYTRACER_SPHERE_H
#define RAYTRACER_SPHERE_H

#include "Object.h"

class Sphere : public Object {
public:
    Vector3 getFirstIntersection (Ray) override;
    Vector3 getNormalAt(Vector3) override;
};

#endif //RAYTRACER_SPHERE_H
