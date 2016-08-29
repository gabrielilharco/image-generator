#ifndef RAYTRACER_TRIANGLE_H
#define RAYTRACER_TRIANGLE_H

#include "shared/geometry/Object.h"

class Triangle : public Object {
public:
    Triangle(const Vector3 a, const Vector3 b, const Vector3 c);
    double getFirstIntersection (const Ray& ray) override;
    Vector3 getNormalAt(const Vector3 v) override;

    const Vector3 a;
    const Vector3 b;
    const Vector3 c;
};

#endif //RAYTRACER_TRIANGLE_H
