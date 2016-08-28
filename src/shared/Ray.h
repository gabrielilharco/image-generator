#ifndef RAYTRACER_RAY_H
#define RAYTRACER_RAY_H

#include "Vector3.h"

class Ray {
public:
    Vector3 direction;
    Vector3 origin;

    Ray(Vector3 origin, Vector3 direction);
};



#endif //RAYTRACER_RAY_H
