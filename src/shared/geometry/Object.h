#ifndef RAYTRACER_OBJECT_H
#define RAYTRACER_OBJECT_H

#include "shared/math/Vector3.h"
#include "shared/geometry/Ray.h"
#include "shared/rendering/Color.h"

#define INF 1e80

enum Material {
    OPA,
    SPEC,
    REFR
};

class Object {
public:
    Material material;
    Color color;

    virtual double getFirstIntersection (const Ray& ray) = 0;
    virtual Vector3 getNormalAt(const Vector3 v) = 0;
};

#endif //RAYTRACER_OBJECT_H
