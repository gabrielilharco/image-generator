#ifndef RAYTRACER_TRIANGLE2_H
#define RAYTRACER_TRIANGLE2_H

#include "shared/math/Vector2.h"

class Triangle2{
public:
    const Vector2 &a;
    const Vector2 &b;
    const Vector2 &c;

    Triangle2(const Vector2 &a, const Vector2 &b, const Vector2 &c);
};

#endif //RAYTRACER_TRIANGLE_H
