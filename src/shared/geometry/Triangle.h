#ifndef RAYTRACER_TRIANGLE_H
#define RAYTRACER_TRIANGLE_H

#include "shared/geometry/Object.h"

class Triangle : public Object {
public:
    Triangle(const Vector3 a, const Vector3 b, const Vector3 c);
    Triangle(const Vector3 a, const Vector3 b, const Vector3 c, const Color color);
    double getFirstIntersection (const Ray& ray) override;
    Vector3 getNormalAt(const Vector3 v) override;

    Vector3 a;
    Vector3 b;
    Vector3 c;
};

#endif //RAYTRACER_TRIANGLE_H
