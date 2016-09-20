#ifndef IMAGE_GENERATOR_POINTLIGHT_H
#define IMAGE_GENERATOR_POINTLIGHT_H

#include "shared/rendering/Light.h"

class PointLight : public Light{
public:
    virtual Vector3 directionAt (const Vector3& point) override;
    Color colorAt(const Vector3& point);
    double distanceAt(const Vector3& point);

    PointLight(Color c, Vector3 pos);
};


#endif //IMAGE_GENERATOR_POINTLIGHT_H
