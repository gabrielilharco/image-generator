#include "DirectionalLight.h"


Vector3 DirectionalLight::directionAt (const Vector3& point) {
    return direction.normalize();
}

Color DirectionalLight::colorAt (const Vector3& point) {
    return color;
}

DirectionalLight::DirectionalLight(Color c, Vector3 dir) {
    direction = dir.normalize();
    color = c;
}