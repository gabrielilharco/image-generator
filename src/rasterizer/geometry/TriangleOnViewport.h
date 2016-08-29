#ifndef RAYTRACER_TRIANGLEONVIEWPORT_H
#define RAYTRACER_TRIANGLEONVIEWPORT_H

#include "shared/geometry/Triangle.h"
#include "shared/math/Vector2.h"

class TriangleOnViewport{
public:
    const Vector2 a;
    const Vector2 b;
    const Vector2 c;
    const Triangle correspondentTriangle;

    TriangleOnViewport(const Vector2 a, const Vector2 b, const Vector2 c, const Triangle correspondentTriangle);
};

#endif //RAYTRACER_TRIANGLEONVIEWPORT_H
