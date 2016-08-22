#include "Sphere.h"

Vector3 Sphere::getFirstIntersection (Ray ray) {
    return Vector3();
}
Vector3 Sphere::getNormalAt (Vector3 point) {
    // doesn't care if point is not at the sphere's surface
    return point - center;
}

Sphere::Sphere (double r) {
    radius = r;
    center = Vector3();
};

Sphere::Sphere (double r, Vector3 o) {
    radius = r;
    center = o;
};
