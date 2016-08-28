#ifndef IMAGE_GENERATOR_LIGHT_H
#define IMAGE_GENERATOR_LIGHT_H

#include "Vector3.h"
#include "Color.h"

class Light {
public:
    Color color;
    virtual Vector3 directionAt (const Vector3& position) = 0;
    virtual Color colorAt(const Vector3& position) = 0;
};


#endif //IMAGE_GENERATOR_LIGHT_H
