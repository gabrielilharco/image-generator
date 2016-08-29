//
// Created by matheus on 8/28/16.
//

#ifndef IMAGE_GENERATOR_RASTERIZER_H
#define IMAGE_GENERATOR_RASTERIZER_H

#include "rasterizer/geometry/Triangle2.h"
#include "shared/rendering/Image.h"
#include "shared/geometry/Triangle.h"
#include "shared/rendering/WorldScene.h"

class Rasterizer {
 public:
    Rasterizer(const WorldScene &scene, const unsigned int imageWidth, const unsigned int imageHeight);
    const Image &renderImage();

 private:
    const double imageWidth;
    const double imageHeight;
    const WorldScene &scene;
    std::vector<Triangle> trianglesWithCameraCoords;
    std::vector<Triangle2> trianglesOnScreen;
    std::vector<std::vector<double>> zBuffer;
    Image* renderedImage;

};


#endif //IMAGE_GENERATOR_RASTERIZER_H
