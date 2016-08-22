#include "Vector3.h"
#include <math.h>

Vector3::Vector3 () {
    x = 0;
    y = 0;
    z = 0;
}

Vector3::Vector3 (double xpos, double ypos, double zpos) {
    x = xpos;
    y = ypos;
    z = zpos;
}

double Vector3::distance (const Vector3& v1, const Vector3& v2) {
    return sqrt((v1.x-v2.x)*(v1.x-v2.x) + (v1.y-v2.y)*(v1.y-v2.y) + (v1.z-v2.z)*(v1.z-v2.z));
}

Vector3 Vector3::operator + (const Vector3& b) const {
    return Vector3(x+b.x, y+b.y, z+b.z);
}

Vector3 Vector3::operator - (const Vector3& b) const {
    return Vector3(x-b.x, y-b.y, z-b.z);
}

Vector3 Vector3::operator * (double b) const {
    return Vector3(x*b, y*b, z*b);
}