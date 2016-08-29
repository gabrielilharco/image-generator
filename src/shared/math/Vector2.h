#ifndef RAYTRACER_VECTOR2_H
#define RAYTRACER_VECTOR2_H


class Vector2 {
public:
    double x, y;

    Vector2 ();
    Vector2 (double, double);

    static double distance(const Vector2& v1, const Vector2& v2);
    static double distance2(const Vector2& v1, const Vector2& v2);
    static double abs2(const Vector2& v);
    Vector2 operator + (const Vector2&) const;
    Vector2 operator - (const Vector2&) const;
    Vector2 operator * (double) const;
    Vector2 operator * (const Vector2&) const;
    Vector2 normalize ();
    double dot(const Vector2&);
    double cross(const Vector2&);
    double abs();

};

#endif //RAYTRACER_VECTOR2_H
