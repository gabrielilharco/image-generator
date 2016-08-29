//
// Created by leao on 29/08/16.
//
#include "BoundingBox.h"
#include <algorithm>

BoundingBox::BoundingBox(const TriangleProjection& triangle) :
        tl(Vector2(std::min(triangle.a.x, std::min(triangle.b.x, triangle.c.x)),
                 std::max(triangle.a.y, std::max(triangle.b.y, triangle.c.y)))),
        tr(Vector2(std::max(triangle.a.x, std::max(triangle.b.x, triangle.c.x)),
                   std::max(triangle.a.y, std::max(triangle.b.y, triangle.c.y)))),
        bl(Vector2(std::min(triangle.a.x, std::min(triangle.b.x, triangle.c.x)),
                   std::min(triangle.a.y, std::min(triangle.b.y, triangle.c.y)))),
        br(Vector2(std::max(triangle.a.x, std::max(triangle.b.x, triangle.c.x)),
                   std::min(triangle.a.y, std::min(triangle.b.y, triangle.c.y)))) {}
