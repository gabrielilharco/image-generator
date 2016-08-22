//
// Created by muzio on 8/22/16.
//

#ifndef IMAGE_GENERATOR_WORLDSCENE_H
#define IMAGE_GENERATOR_WORLDSCENE_H

#include <vector>
#include "Object.h"

using namespace std;

class WorldScene {
public:
    void addObject(Object* obj);
    vector<Object *> worldObjects() {return listOfObjects;}
    bool getFirstIntersection(const Ray& ray, Object* obj);

private:
    vector<Object *> listOfObjects;
};


#endif //IMAGE_GENERATOR_WORLDSCENE_H
