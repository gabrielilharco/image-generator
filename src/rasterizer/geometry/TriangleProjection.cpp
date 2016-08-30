#include <shared/math/Vector2.h>
#include "rasterizer/geometry/TriangleProjection.h"
#include <math.h>

TriangleProjection::TriangleProjection(const Vector2 a, const Vector2 b, const Vector2 c, const Triangle correspondentTriangle)
    : a(a), b(b), c(c), correspondentTriangle(correspondentTriangle) {}

bool TriangleProjection::isInside(Vector2 point) {
    double l1 = (point-a).cross(b-a);
    double l2 = (point-b).cross(c-b);
    double l3 = (point-c).cross(a-c);

    if(l1 >= 0 && l2 >= 0 && l3 >= 0) return true;
    if(l1 < 0 && l2 < 0 && l3 < 0) return true;
    return false;
}
