//
// Created by matheus on 8/30/16.
//

#ifndef IMAGE_GENERATOR_SPHERETOTRIANGLESGENERATOR_H
#define IMAGE_GENERATOR_SPHERETOTRIANGLESGENERATOR_H

#include "shared/geometry/Triangle.h"

class SphereToTrianglesGenerator {
 public:
    SphereToTrianglesGenerator(const int depth);
    const std::vector<Triangle> &getTriangleList() const;

 private:
    void generateUnitSphere(const int depth);
    std::vector<Triangle> triangleList;
};


#endif //IMAGE_GENERATOR_SPHERETOTRIANGLESGENERATOR_H
