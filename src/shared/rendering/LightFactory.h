//
// Created by leao on 20/09/16.
//

#ifndef IMAGE_GENERATOR_LIGHTFACTORY_H
#define IMAGE_GENERATOR_LIGHTFACTORY_H
#include "Light.h"
#include "PointLight.h"
#include "DirectionalLight.h"

class LightFactory {
public:
    static Light* getLight(const Light* reference, const Color color, const Vector3 pos);

    static Light* getDirectionalLight(const Color color, const Vector3 pos);
    static Light* getPointLight(const Color color, const Vector3 pos);
};
#endif //IMAGE_GENERATOR_LIGHTFACTORY_H
