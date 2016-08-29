#include "shared/math/Vector2.h"
#include <math.h>

Vector2::Vector2 () {
    x = 0;
    y = 0;
}

Vector2::Vector2 (double xpos, double ypos) {
    x = xpos;
    y = ypos;
}

double Vector2::distance (const Vector2& v1, const Vector2& v2) {
    return sqrt((v1.x-v2.x)*(v1.x-v2.x) + (v1.y-v2.y)*(v1.y-v2.y));
}

double Vector2::distance2 (const Vector2& v1, const Vector2& v2) {
    return (v1.x-v2.x)*(v1.x-v2.x) + (v1.y-v2.y)*(v1.y-v2.y);
}

Vector2 Vector2::operator + (const Vector2& b) const {
    return Vector2(x+b.x, y+b.y);
}

Vector2 Vector2::operator - (const Vector2& b) const {
    return Vector2(x-b.x, y-b.y);
}

Vector2 Vector2::operator * (double b) const {
    return Vector2(x*b, y*b);
}

Vector2 Vector2::operator*(const Vector2 & v) const {
    return Vector2(x * v.x, y * v.y);
}

Vector2 Vector2::normalize () {
    double m = sqrt(x*x + y*y);
    if (m == 0) return Vector2(1,0);
    return Vector2(x/m, y/m);
}

double Vector2::dot(const Vector2& v) {
    return x*v.x + y*v.y;
}

double Vector2::cross(const Vector2& v){
    return x*v.y-y*v.x;
}

double Vector2::abs() {
    return sqrt(x*x+y*y);
}

double Vector2::abs2(const Vector2& v) {
    return v.x*v.x+v.y*v.y;
}
