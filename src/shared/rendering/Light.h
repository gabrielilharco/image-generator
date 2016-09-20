#ifndef IMAGE_GENERATOR_LIGHT_H
#define IMAGE_GENERATOR_LIGHT_H

#include "shared/math/Vector3.h"
#include "shared/rendering/Color.h"

class Light {
public:
    Color color;
    Vector3 position;
    int typeId;

    virtual Vector3 directionAt (const Vector3& position) = 0;
};


#endif //IMAGE_GENERATOR_LIGHT_H
