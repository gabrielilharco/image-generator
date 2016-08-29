#include <shared/math/Vector2.h>
#include "rasterizer/geometry/TriangleOnViewport.h"

TriangleOnViewport::TriangleOnViewport(const Vector2 a, const Vector2 b, const Vector2 c, const Triangle correspondentTriangle)
    : a(a), b(b), c(c), correspondentTriangle(correspondentTriangle) {}
