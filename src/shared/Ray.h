#ifndef RAYTRACER_RAY_H
#define RAYTRACER_RAY_H

#include "Vector3.h"

class Ray {
public:
    Vector3 dir;
    Vector3 ori;

    Ray(Vector3 dir, Vector3 ori);
};



#endif //RAYTRACER_RAY_H
