//
// Created by muzio on 8/22/16.
//

#ifndef IMAGE_GENERATOR_RAYTRACER_H
#define IMAGE_GENERATOR_RAYTRACER_H

#include "shared/Image.h"
#include "shared/WorldScene.h"
#include "shared/Color.h"
#include "shared/Ray.h"

class RayTracer {
public:
    void generateImage(const WorldScene& ws);
    const Image& getImage();

private:
    Color traceRay(const Ray& originalRay);
    Image generatedImage;
};


#endif //IMAGE_GENERATOR_RAYTRACER_H
