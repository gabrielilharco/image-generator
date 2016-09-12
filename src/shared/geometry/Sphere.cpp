#include "shared/geometry/Sphere.h"
#include <math.h>

double Sphere::getFirstIntersection (const Ray& ray) {

    double a = Vector3::abs2(ray.direction);
    double b = 2*(ray.origin - center).dot(ray.direction);
    double c = Vector3::abs2(ray.origin - center) - radius*radius;

    double delta = b*b - 4*c;

    if (delta > 0) {
        double root_1 = (-1*b - sqrt(delta))/(2*a);
        double root_2 = (-1*b + sqrt(delta))/(2*a);
        if (root_1 > 0) return root_1;
        if (root_2 > 0) return root_2;
    }
    else if (delta == 0) {
        double root = -b / (2 * a);
        if (root > 0) return root;
    }
    return INF;
}

Vector3 Sphere::getNormalAt (Vector3 point) {
    // doesn't care if point is not at the sphere's surface
    return (point - center).normalize();
}

Sphere::Sphere (double r) {
    radius = r;
    center = Vector3();
};

Sphere::Sphere (double r, Vector3 o) {
    radius = r;
    center = o;
};

Sphere::Sphere (double r, Vector3 o, Color c, double ref, double trans) {
    radius = r;
    center = o;
    color = c;
    reflection = ref;
    transparency = trans;
};


