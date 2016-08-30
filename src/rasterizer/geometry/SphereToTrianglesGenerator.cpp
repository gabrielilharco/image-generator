//
// Created by matheus on 8/30/16.
//

#include "shared/math/Vector3.h"
#include "SphereToTrianglesGenerator.h"
#include <cmath>

SphereToTrianglesGenerator::SphereToTrianglesGenerator(const int depth) {
    generateUnitSphere(depth);
}

void SphereToTrianglesGenerator::generateUnitSphere(const int depth) {

    /*
     * Reference: http://blog.andreaskahler.com/2009/06/creating-icosphere-mesh-in-code.html
     */

    std::vector<Vector3> icosphereVertices;
    double g = (1.0 + sqrt(5.0)) / 2.0;

    icosphereVertices.push_back(Vector3(-1, g, 0));
    icosphereVertices.push_back(Vector3( 1, g, 0));
    icosphereVertices.push_back(Vector3(-1,-g, 0));
    icosphereVertices.push_back(Vector3( 1,-g, 0));

    icosphereVertices.push_back(Vector3( 0,-1, g));
    icosphereVertices.push_back(Vector3( 0, 1, g));
    icosphereVertices.push_back(Vector3( 0,-1,-g));
    icosphereVertices.push_back(Vector3( 0, 1,-g));

    icosphereVertices.push_back(Vector3( g, 0,-1));
    icosphereVertices.push_back(Vector3( g, 0, 1));
    icosphereVertices.push_back(Vector3(-g, 0,-1));
    icosphereVertices.push_back(Vector3(-g, 0, 1));

    triangleList.push_back(Triangle(icosphereVertices[0],
                                    icosphereVertices[11],
                                    icosphereVertices[5]));
    triangleList.push_back(Triangle(icosphereVertices[0],
                                    icosphereVertices[5],
                                    icosphereVertices[1]));
    triangleList.push_back(Triangle(icosphereVertices[0],
                                    icosphereVertices[1],
                                    icosphereVertices[7]));
    triangleList.push_back(Triangle(icosphereVertices[0],
                                    icosphereVertices[7],
                                    icosphereVertices[10]));
    triangleList.push_back(Triangle(icosphereVertices[0],
                                    icosphereVertices[10],
                                    icosphereVertices[11]));

    triangleList.push_back(Triangle(icosphereVertices[1],
                                    icosphereVertices[5],
                                    icosphereVertices[9]));
    triangleList.push_back(Triangle(icosphereVertices[5],
                                    icosphereVertices[11],
                                    icosphereVertices[4]));
    triangleList.push_back(Triangle(icosphereVertices[11],
                                    icosphereVertices[10],
                                    icosphereVertices[2]));
    triangleList.push_back(Triangle(icosphereVertices[10],
                                    icosphereVertices[7],
                                    icosphereVertices[6]));
    triangleList.push_back(Triangle(icosphereVertices[7],
                                    icosphereVertices[1],
                                    icosphereVertices[8]));

    triangleList.push_back(Triangle(icosphereVertices[3],
                                    icosphereVertices[9],
                                    icosphereVertices[4]));
    triangleList.push_back(Triangle(icosphereVertices[3],
                                    icosphereVertices[4],
                                    icosphereVertices[2]));
    triangleList.push_back(Triangle(icosphereVertices[3],
                                    icosphereVertices[2],
                                    icosphereVertices[6]));
    triangleList.push_back(Triangle(icosphereVertices[3],
                                    icosphereVertices[6],
                                    icosphereVertices[8]));
    triangleList.push_back(Triangle(icosphereVertices[3],
                                    icosphereVertices[8],
                                    icosphereVertices[9]));

    triangleList.push_back(Triangle(icosphereVertices[4],
                                    icosphereVertices[9],
                                    icosphereVertices[5]));
    triangleList.push_back(Triangle(icosphereVertices[2],
                                    icosphereVertices[4],
                                    icosphereVertices[11]));
    triangleList.push_back(Triangle(icosphereVertices[6],
                                    icosphereVertices[2],
                                    icosphereVertices[10]));
    triangleList.push_back(Triangle(icosphereVertices[8],
                                    icosphereVertices[6],
                                    icosphereVertices[7]));
    triangleList.push_back(Triangle(icosphereVertices[9],
                                    icosphereVertices[8],
                                    icosphereVertices[1]));
}
const std::vector<Triangle> &SphereToTrianglesGenerator::getTriangleList() const {
    return triangleList;
}
