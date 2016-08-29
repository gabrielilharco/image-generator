#ifndef RAYTRACER_TRIANGLE_H
#define RAYTRACER_TRIANGLE_H

#include "shared/geometry/Object.h"

class Triangle : public Object {
public:
    double getFirstIntersection (const Ray& ray) override;
    Vector3 getNormalAt(const Vector3 v) override;
};

#endif //RAYTRACER_TRIANGLE_H
