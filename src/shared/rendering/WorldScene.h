//
// Created by muzio on 8/22/16.
//

#ifndef IMAGE_GENERATOR_WORLDSCENE_H
#define IMAGE_GENERATOR_WORLDSCENE_H

#include <vector>
#include "shared/geometry/Sphere.h"
#include "shared/geometry/Triangle.h"
#include "shared/geometry/Object.h"
#include "shared/rendering/Light.h"

class WorldScene {
public:
    void addTriangle(Triangle *triangle);
    void addSphere(Sphere *sphere);
    void addLight(Light *light);
    const std::vector<Object*> &objects() const;
    const std::vector<Sphere*> &spheres() const;
    const std::vector<Triangle*> &triangles() const;
    const std::vector<Light*> &lights() const;
    double getFirstIntersection(const Ray &ray, Object* &obj) const;

private:
    std::vector<Object*> listOfObjects;
    std::vector<Sphere*> listOfSpheres;
    std::vector<Triangle*> listOfTriangles;
    std::vector<Light*> listOfLights;
};


#endif //IMAGE_GENERATOR_WORLDSCENE_H
