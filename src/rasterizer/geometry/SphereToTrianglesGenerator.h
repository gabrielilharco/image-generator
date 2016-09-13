//
// Created by matheus on 8/30/16.
//

#ifndef IMAGE_GENERATOR_SPHERETOTRIANGLESGENERATOR_H
#define IMAGE_GENERATOR_SPHERETOTRIANGLESGENERATOR_H

#include "shared/geometry/Triangle.h"

class SphereToTrianglesGenerator {
 public:
    static const std::vector<Triangle> createTriangles(const double radius, const Vector3 position, const Color color, const int refineSteps);

 private:
    static void generateUnitSphere(const int depth, const Color color, std::vector<Triangle>& triangleList);
    static void adjustRadius(const double radius, std::vector<Triangle>& triangleList);
    static void translate(const Vector3 vector3, std::vector<Triangle>& triangleList);
};


#endif //IMAGE_GENERATOR_SPHERETOTRIANGLESGENERATOR_H
