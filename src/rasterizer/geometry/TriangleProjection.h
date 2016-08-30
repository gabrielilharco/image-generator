#ifndef RAYTRACER_TRIANGLEONVIEWPORT_H
#define RAYTRACER_TRIANGLEONVIEWPORT_H

#include "shared/geometry/Triangle.h"
#include "shared/math/Vector2.h"

class TriangleProjection{
public:
    const Vector2 a;
    const Vector2 b;
    const Vector2 c;
    const Triangle correspondentTriangle;

    TriangleProjection(const Vector2 a, const Vector2 b, const Vector2 c, const Triangle correspondentTriangle);
    bool isInside(Vector2);
    double interpolateDepth(Vector2);
};

#endif //RAYTRACER_TRIANGLEONVIEWPORT_H
