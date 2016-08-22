//
// Created by muzio on 8/22/16.
//

#include "WorldScene.h"

void WorldScene::addObject(Object *obj) {
    listOfObjects.push_back(obj);
}

bool WorldScene::getFirstIntersection(const Ray &ray, Object *obj) {
    return false;
}
