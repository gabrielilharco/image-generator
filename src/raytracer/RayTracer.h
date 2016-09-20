//
// Created by muzio on 8/22/16.
//

#ifndef IMAGE_GENERATOR_RAYTRACER_H
#define IMAGE_GENERATOR_RAYTRACER_H

#include "shared/rendering/Camera.h"
#include "shared/rendering/Image.h"
#include "shared/rendering/WorldScene.h"
#include "shared/rendering/Color.h"
#include "shared/geometry/Ray.h"

class RayTracer {
public:
    RayTracer(int sspp = 1, int max_depth = 1) { samplesSqrtPerPixel = sspp; this->max_depth=max_depth;}

    void render(const WorldScene& ws, const Camera& camera, Image* image, string filename);

private:
    int max_depth;
    int samplesSqrtPerPixel;
    Color traceRay(const Ray& originalRay, const WorldScene& ws, const Camera& camera, int depth, bool isReflecting);
};


#endif //IMAGE_GENERATOR_RAYTRACER_H
