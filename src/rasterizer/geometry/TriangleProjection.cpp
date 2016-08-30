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

double TriangleProjection::interpolateDepth(Vector2 point) {
    //Compute barycentric coordinates
    double l0, l1, l2;

    double area = fabs((b-a).cross(c-a));
    l0 = fabs((point-a).cross(b-a)/area);
    l1 = fabs((point-b).cross(c-b)/area);
    l2 = fabs((point-c).cross(a-c)/area);

    return 1.0/(l0/correspondentTriangle.c.z + l1/correspondentTriangle.a.z + l2/correspondentTriangle.b.z);

}

