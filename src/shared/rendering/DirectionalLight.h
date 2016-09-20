#ifndef IMAGE_GENERATOR_DIRECTIONALLIGHT_H
#define IMAGE_GENERATOR_DIRECTIONALLIGHT_H

#include "shared/rendering/Light.h"

class DirectionalLight : public Light{
public:
    virtual Vector3 directionAt (const Vector3& point) override;
    Color colorAt(const Vector3& point);
    double distanceAt(const Vector3& point);

    DirectionalLight(Color c, Vector3 dir);
};


#endif //IMAGE_GENERATOR_DIRECTIONALLIGHT_H
