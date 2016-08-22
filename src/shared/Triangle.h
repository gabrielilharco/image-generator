#ifndef RAYTRACER_TRIANGE_H
#define RAYTRACER_TRIANGE_H

#include "Object.h"

class Triangle : public Object {
public:
    Vector3 getFirstIntersection (Ray) override;
    Vector3 getNormalAt(Vector3) override;
};

#endif //RAYTRACER_TRIANGE_H
