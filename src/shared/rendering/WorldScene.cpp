//
// Created by muzio on 8/22/16.
//

#include "shared/rendering/WorldScene.h"

void WorldScene::addTriangle(Triangle *triangle) {
    listOfTriangles.push_back(triangle);
    listOfObjects.push_back(triangle);
}

void WorldScene::addSphere(Sphere *sphere) {
    listOfSpheres.push_back(sphere);
    listOfObjects.push_back(sphere);
}

void WorldScene::addLight(Light *light) {
    listOfLights.push_back(light);
}

const std::vector<Object*> &WorldScene::objects() const {
    return listOfObjects;
}

const std::vector<Sphere*> &WorldScene::spheres() const {
    return listOfSpheres;
}

const std::vector<Triangle*> &WorldScene::triangles() const {
    return listOfTriangles;
}

const std::vector<Light*> &WorldScene::lights() const {
    return listOfLights;
}

double WorldScene::getFirstIntersection(const Ray &ray, Object* &obj, const Camera &cam, bool isReflecting) const {
    double distanceToFirst = INF;
    double currentDistance;
    Vector3 cameraHorizontal = (cam.calculateTopRight()-cam.calculateTopLeft()).normalize();
    Vector3 cameraVertical = (cam.calculateBottomLeft()-cam.calculateTopLeft()).normalize();
    Vector3 normCam = cameraHorizontal.cross(cameraVertical);
    for (int i = 0; i < listOfObjects.size(); i++) {
        currentDistance = listOfObjects[i]->getFirstIntersection(ray);
        Vector3 intercPoint = ray.origin + ray.direction * currentDistance;
        if (currentDistance < distanceToFirst && (isReflecting || normCam.dot(cam.calculateTopLeft()-intercPoint) < 0)){
            distanceToFirst = currentDistance;
            obj = listOfObjects[i];
        }
    }
    return distanceToFirst;
}