//
// Created by muzio on 8/22/16.
//

#ifndef IMAGE_GENERATOR_RAYTRACER_H
#define IMAGE_GENERATOR_RAYTRACER_H

#include "shared/rendering/Image.h"
#include "shared/rendering/WorldScene.h"
#include "shared/rendering/Color.h"
#include "shared/geometry/Ray.h"

class RayTracer {
public:
    void render(const WorldScene& ws);
    const Image& getImage();

private:
    Image generatedImage;

    Color traceRay(const Ray& originalRay);
};


#endif //IMAGE_GENERATOR_RAYTRACER_H
