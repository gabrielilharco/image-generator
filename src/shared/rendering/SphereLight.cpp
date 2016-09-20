#include "shared/rendering/SphereLight.h"

Vector3 SphereLight::directionAt (const Vector3& point) {
    return point-sphere.center;
}

Color SphereLight::colorAt (const Vector3& point, const WorldScene& ws, const Camera& camera, bool isReflecting) {
    // generate rays from various points of the sphere and check
    int nPoints = 20;
    Object *intercObj = NULL;
    double countHits = 0;
    for (int i = 0; i < nPoints; i++) {
        Vector3 randDir = Vector3::generateRandom();
        Vector3 randPoint = sphere.center + randDir*sphere.radius;
        double distToInter = ws.getFirstIntersection(Ray(randPoint, point-randPoint), intercObj, camera, isReflecting);
        if (distToInter >= Vector3::distance(point, randPoint)-0.000001) {
            countHits++;
        }
    }
    return sphere.color*(countHits/nPoints);
}

SphereLight::SphereLight (Color c, Vector3 pos, double r) {
    sphere = Sphere(r, pos, c, 0,0);
};

double SphereLight::distanceAt(const Vector3& point) {
    return Vector3::distance(point, sphere.center);
}