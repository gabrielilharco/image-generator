#ifndef RAYTRACER_VECTOR3_H
#define RAYTRACER_VECTOR3_H


class Vector3 {
public:
    double x, y, z;

    Vector3 ();
    Vector3 (double, double, double);

    static double distance(const Vector3& v1, const Vector3& v2);
    static double distance2(const Vector3& v1, const Vector3& v2);
    Vector3 operator + (const Vector3&) const;
    Vector3 operator - (const Vector3&) const;
    Vector3 operator * (double) const;
    Vector3 operator * (const Vector3&) const;
    Vector3 normalize ();
    double dot(const Vector3&);
    Vector3 cross(const Vector3&);
    double abs();
};

#endif //RAYTRACER_VECTOR3_H
