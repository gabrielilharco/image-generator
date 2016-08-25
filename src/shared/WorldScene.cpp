//
// Created by muzio on 8/22/16.
//

#include "WorldScene.h"

#include <math.h>
void WorldScene::addObject(Object *obj) {
    listOfObjects.push_back(obj);
}

double WorldScene::getFirstIntersection(const Ray &ray, Object* &obj) {
    double distanceToFirst = 9999999;
    double currentDistance;
    for (int i = 0; i < listOfObjects.size(); i++) {
        currentDistance = listOfObjects[i]->getFirstIntersection(ray);
        if (currentDistance < distanceToFirst && currentDistance > 0.0) {
            distanceToFirst = currentDistance;
            obj = listOfObjects[i];
        }
    }

    if (distanceToFirst == 9999999)
        return -1;

    return distanceToFirst;
}