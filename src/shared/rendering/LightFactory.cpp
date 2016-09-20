//
// Created by leao on 20/09/16.
//

#include <cstdio>
#include "LightFactory.h"

Light* LightFactory::getDirectionalLight(const Color color, const Vector3 pos) {
    DirectionalLight* directionalLight = new DirectionalLight(color, pos);
    directionalLight->typeId = 0;
    return directionalLight;
}

Light* LightFactory::getPointLight(const Color color, const Vector3 pos) {
    PointLight* pointLight = new PointLight(color, pos);
    pointLight->typeId = 1;
    return pointLight;
}

Light* LightFactory::getLight(const Light* reference, const Color color, const Vector3 pos) {
    if(reference->typeId == 0) {
        return getDirectionalLight(color, pos);
    }
    else getPointLight(color, pos);
}
