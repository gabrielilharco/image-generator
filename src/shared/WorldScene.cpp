//
// Created by muzio on 8/22/16.
//

#include "WorldScene.h"

void WorldScene::addObject(Object *obj) {
    listOfObjects.push_back(obj);
}

double WorldScene::getFirstIntersection(const Ray &ray, Object* obj) {
    double distanceToFirst = -1;
    double currentDistance;
    for (int i = 0; i < listOfObjects.size(); i++) {
        currentDistance = listOfObjects[i]->getFirstIntersection(ray);
        if (distanceToFirst == -1 || currentDistance < distanceToFirst) {
            distanceToFirst = currentDistance;
            obj = listOfObjects[i];
        }
    }
    return distanceToFirst;
}