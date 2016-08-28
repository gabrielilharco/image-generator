//
// Created by muzio on 8/22/16.
//

#ifndef IMAGE_GENERATOR_WORLDSCENE_H
#define IMAGE_GENERATOR_WORLDSCENE_H

#include <vector>
#include "Object.h"
#include "Light.h"

using namespace std;

class WorldScene {
public:
    void addObject(Object* obj);
    void addLight(Light* l);
    vector<Object *> objects() {return listOfObjects;}
    vector<Light *> lights() {return listOfLights;}
    double getFirstIntersection(const Ray& ray, Object* &obj);

private:
    vector<Object *> listOfObjects;
    vector<Light *> listOfLights;
};


#endif //IMAGE_GENERATOR_WORLDSCENE_H
