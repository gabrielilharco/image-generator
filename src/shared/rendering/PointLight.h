#ifndef IMAGE_GENERATOR_POINTLIGHT_H
#define IMAGE_GENERATOR_POINTLIGHT_H

#include "shared/rendering/Light.h"

class PointLight : public Light{
public:
    Vector3 position;
    Color color;
    virtual Vector3 directionAt (const Vector3& point) override;
    virtual Color colorAt(const Vector3& point) override;
    double distanceAt(const Vector3& point) override;

    PointLight(Color c, Vector3 pos);
};


#endif //IMAGE_GENERATOR_POINTLIGHT_H
