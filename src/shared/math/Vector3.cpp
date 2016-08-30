#include "shared/math/Vector3.h"
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

double Vector3::distance2 (const Vector3& v1, const Vector3& v2) {
    return (v1.x-v2.x)*(v1.x-v2.x) + (v1.y-v2.y)*(v1.y-v2.y) + (v1.z-v2.z)*(v1.z-v2.z);
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

Vector3 Vector3::operator*(const Vector3 & v) const {
    return Vector3(x * v.x, y * v.y, z * v.z);
}

Vector3 Vector3::operator * (const Matrix44& mat) const {
    std::vector<double> m = mat.getRowsAsVector();
    return Vector3(x*m[0] + y*m[1*4+0] + z*m[2*4+0] + m[3*4+0],
                   x*m[1] + y*m[1*4+1] + z*m[2*4+1] + m[3*4+1],
                   x*m[2] + y*m[1*4+2] + z*m[2*4+2] + m[3*4+2]);
}

Vector3 Vector3::normalize () {
    double m = sqrt(x*x + y*y + z*z);
    if (m == 0) return Vector3(1,0,0);
    return Vector3(x/m, y/m, z/m);
}

double Vector3::dot(const Vector3& v) {
    return x*v.x + y*v.y + z*v.z;
}

Vector3 Vector3::cross(const Vector3& v){
    return Vector3(y*v.z-z*v.y, z*v.x-x*v.z, x*v.y-y*v.x);
}

double Vector3::abs() {
    return sqrt(x*x+y*y+z*z);
}

double Vector3::abs2(const Vector3& v) {
    return v.x*v.x+v.y*v.y+v.z*v.z;
}
