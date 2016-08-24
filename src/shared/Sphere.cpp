#include "Sphere.h"
#include <math.h>

double Sphere::getFirstIntersection (const Ray& ray) {

    double a = 1;
    double b = 2*(ray.origin - center).dot(ray.direction);
    double c = Vector3::distance(ray.origin, center) - radius*radius;

    double discriminant = b*b - 4*c;

    if (discriminant > 0) {
        double root_1 = ((-1*b - sqrt(discriminant))/(2*a)) - 0.000001;

        if (root_1 > 0) {
            return root_1;
        }
        else {
            double root_2 = ((sqrt(discriminant) - b)/(2*a)) - 0.000001;
            return root_2;
        }
    }
    else {
        return -1;
    }
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
