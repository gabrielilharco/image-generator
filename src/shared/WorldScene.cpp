//
// Created by muzio on 8/22/16.
//

#include "WorldScene.h"

#include <math.h>

void WorldScene::addObject(Object *obj) {
    listOfObjects.push_back(obj);
}

void WorldScene::addLight(Light *l) {
    listOfLights.push_back(l);
}

double WorldScene::getFirstIntersection(const Ray &ray, Object* &obj) {
    double distanceToFirst = INF;
    double currentDistance;
    for (int i = 0; i < listOfObjects.size(); i++) {
        currentDistance = listOfObjects[i]->getFirstIntersection(ray);
        if (currentDistance < distanceToFirst) {
            distanceToFirst = currentDistance;
            obj = listOfObjects[i];
        }
    }
    return distanceToFirst;
}