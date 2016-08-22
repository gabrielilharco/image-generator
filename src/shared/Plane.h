#ifndef RAYTRACER_PLANE_H
#define RAYTRACER_PLANE_H

#include "Object.h"

class Plane : public Object {
public:
    Vector3 getFirstIntersection (Ray) override;
    Vector3 getNormalAt(Vector3) override;
};


#endif //RAYTRACER_PLANE_H
