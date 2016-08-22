#ifndef RAYTRACER_TRIANGE_H
#define RAYTRACER_TRIANGE_H

#include "Object.h"

class Triangle : public Object {
public:
    Vector3 getFirstIntersection (const Ray& ray) override;
    Vector3 getNormalAt(const Vector3 v) override;
};

#endif //RAYTRACER_TRIANGE_H
