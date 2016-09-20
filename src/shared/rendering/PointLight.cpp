#include "shared/rendering/PointLight.h"


Vector3 PointLight::directionAt (const Vector3& point) {
    return (position-point).normalize();
}

Color PointLight::colorAt (const Vector3& point) {
    return color;
}

PointLight::PointLight (Color c, Vector3 pos) {
    position = pos;
    color = c;
};

double PointLight::distanceAt(const Vector3& point) {
    return Vector3::distance(point, position);
}
