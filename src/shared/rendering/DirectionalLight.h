#ifndef IMAGE_GENERATOR_DIRECTIONALLIGHT_H
#define IMAGE_GENERATOR_DIRECTIONALLIGHT_H

#include "shared/rendering/Light.h"

class DirectionalLight : public Light{
public:
    Vector3 direction;
    Color color;

    virtual Vector3 directionAt (const Vector3& point) override;
    virtual Color colorAt(const Vector3& point) override;

    DirectionalLight(Color c, Vector3 dir);
};


#endif //IMAGE_GENERATOR_DIRECTIONALLIGHT_H
