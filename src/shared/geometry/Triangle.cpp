#include <iostream>
#include "shared/geometry/Triangle.h"

double Triangle::getFirstIntersection (const Ray& ray) {
    return 0;
}
Vector3 Triangle::getNormalAt (const Vector3 v) {
    return Vector3();
}
Triangle::Triangle(const Vector3 a, const Vector3 b, const Vector3 c)
        : a(a), b(b), c(c) {}

Triangle::Triangle(const Vector3 a, const Vector3 b, const Vector3 c, const Color color)
    : a(a), b(b), c(c) {
    this->color = color;
}
