//
// Created by matheus on 8/30/16.
//

#include "shared/math/Vector3.h"
#include "SphereToTrianglesGenerator.h"
#include <cmath>

void SphereToTrianglesGenerator::generateUnitSphere(const int depth, std::vector<Triangle>& triangleList) {

    /*
     * Reference: http://blog.andreaskahler.com/2009/06/creating-icosphere-mesh-in-code.html
     */

    std::vector<Vector3> icosphereVertices;
    double g = (1.0 + sqrt(5.0)) / 2.0;

    icosphereVertices.push_back(Vector3(-1, g, 0).normalize());
    icosphereVertices.push_back(Vector3( 1, g, 0).normalize());
    icosphereVertices.push_back(Vector3(-1,-g, 0).normalize());
    icosphereVertices.push_back(Vector3( 1,-g, 0).normalize());

    icosphereVertices.push_back(Vector3( 0,-1, g).normalize());
    icosphereVertices.push_back(Vector3( 0, 1, g).normalize());
    icosphereVertices.push_back(Vector3( 0,-1,-g).normalize());
    icosphereVertices.push_back(Vector3( 0, 1,-g).normalize());

    icosphereVertices.push_back(Vector3( g, 0,-1).normalize());
    icosphereVertices.push_back(Vector3( g, 0, 1).normalize());
    icosphereVertices.push_back(Vector3(-g, 0,-1).normalize());
    icosphereVertices.push_back(Vector3(-g, 0, 1).normalize());

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

    for (int i = 0; i < depth; i++) {
        std::vector<Triangle> newTriangleList;
        for (int j = 0; j < triangleList.size(); j++) {
            Vector3 ab = Vector3::middlePoint(triangleList[j].a,
                                              triangleList[j].b).normalize();
            Vector3 ac = Vector3::middlePoint(triangleList[j].a,
                                              triangleList[j].c).normalize();
            Vector3 bc = Vector3::middlePoint(triangleList[j].b,
                                              triangleList[j].c).normalize();
            newTriangleList.push_back(Triangle(triangleList[j].a, ab, ac));
            newTriangleList.push_back(Triangle(triangleList[j].b, bc, ab));
            newTriangleList.push_back(Triangle(triangleList[j].c, ac, bc));
            newTriangleList.push_back(Triangle(ab, bc, ac));
        }
        triangleList = newTriangleList;
    }
}

void SphereToTrianglesGenerator::adjustRadius(const double radius, std::vector<Triangle>& triangleList) {
    for (int i = 0; i < triangleList.size(); i++) {
        triangleList[i].a.x *= radius;
        triangleList[i].a.y *= radius;
        triangleList[i].a.z *= radius;
        triangleList[i].b.x *= radius;
        triangleList[i].b.y *= radius;
        triangleList[i].b.z *= radius;
        triangleList[i].c.x *= radius;
        triangleList[i].c.y *= radius;
        triangleList[i].c.z *= radius;
    }
}

void SphereToTrianglesGenerator::translate(const Vector3 position, std::vector<Triangle>& triangleList) {
    std::vector<double> teste{1, 0, 0, 0,
                              0, 1, 0, 0,
                              0, 0, 1, 0,
                              position.x, position.y, position.z, 1};
    Matrix44 transform(teste);
    for (int i = 0; i < triangleList.size(); i++) {
        triangleList[i].a = triangleList[i].a * transform;
        triangleList[i].b = triangleList[i].b * transform;
        triangleList[i].c = triangleList[i].c * transform;
    }

}
const std::vector<Triangle> SphereToTrianglesGenerator::createTriangles(const double radius, const Vector3 position, const int refineSteps) {
    std::vector<Triangle> triangleList;
    generateUnitSphere(refineSteps, triangleList);
    adjustRadius(radius, triangleList);
    translate(position, triangleList);
    return triangleList;
}

