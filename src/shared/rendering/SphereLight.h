#ifndef IMAGE_GENERATOR_POINTLIGHT_H
#define IMAGE_GENERATOR_POINTLIGHT_H

#include "shared/rendering/Light.h"
#include "WorldScene.h"

class SphereLight : public Light{
public:
    Sphere sphere = Sphere(0, Vector3(), Color(), 0, 0);
    virtual Vector3 directionAt (const Vector3& point) override;
    Color colorAt(const Vector3& point, const WorldScene& ws, const Camera& camera);
    double distanceAt(const Vector3& point) override;

    SphereLight(Color c, Vector3 pos, double r);
};


#endif //IMAGE_GENERATOR_POINTLIGHT_H
