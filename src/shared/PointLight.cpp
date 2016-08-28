#include "PointLight.h"


Vector3 PointLight::directionAt (const Vector3& point) {
    return point-position;
}

Color PointLight::colorAt (const Vector3& point) {
    return color;
}

PointLight::PointLight (Color c, Vector3 pos) {
    position = pos;
    color = c;
};
