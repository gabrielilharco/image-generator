#include "shared/rendering/DirectionalLight.h"


Vector3 DirectionalLight::directionAt (const Vector3& point) {
    return position.normalize();
}

Color DirectionalLight::colorAt (const Vector3& point) {
    return color;
}

DirectionalLight::DirectionalLight(Color c, Vector3 dir) {
    position = dir.normalize();
    color = c;
}

double DirectionalLight::distanceAt(const Vector3& point) {
    return 1e80;
}
