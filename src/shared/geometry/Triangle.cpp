#include "shared/geometry/Triangle.h"

double Triangle::getFirstIntersection (const Ray& ray) {
    return 0;
}
Vector3 Triangle::getNormalAt (const Vector3 v) {
    // doesn't matter where the point is, normal is always the same vector
    Vector3 normal = ((b-a).cross(c-a)).normalize();
    return normal;
}
Triangle::Triangle(const Vector3 a, const Vector3 b, const Vector3 c)
        : a(a), b(b), c(c) {}

Triangle::Triangle(const Vector3 a, const Vector3 b, const Vector3 c, const Color color)
    : a(a), b(b), c(c) {
    this->color = color;
}
