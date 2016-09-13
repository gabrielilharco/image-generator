//
// Created by matheus on 8/30/16.
//

#ifndef IMAGE_GENERATOR_SPHERETOTRIANGLESGENERATOR_H
#define IMAGE_GENERATOR_SPHERETOTRIANGLESGENERATOR_H

#include "shared/geometry/Triangle.h"

class SphereToTrianglesGenerator {
 public:
    SphereToTrianglesGenerator(const double radius, const Vector3 position, const int depth);
    const std::vector<Triangle> &getTriangleList() const;

 private:
    void generateUnitSphere(const int depth);
    std::vector<Triangle> triangleList;
    void adjustRadius(const double radius);
    void translate(const Vector3 vector3);
};


#endif //IMAGE_GENERATOR_SPHERETOTRIANGLESGENERATOR_H
