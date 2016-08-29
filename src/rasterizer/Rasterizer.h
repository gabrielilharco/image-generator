//
// Created by matheus on 8/28/16.
//

#ifndef IMAGE_GENERATOR_RASTERIZER_H
#define IMAGE_GENERATOR_RASTERIZER_H

#include <shared/rendering/CameraRasterization.h>
#include "rasterizer/geometry/TriangleOnViewport.h"
#include "shared/rendering/Image.h"
#include "shared/geometry/Triangle.h"
#include "shared/rendering/WorldScene.h"

class Rasterizer {
 public:
    Rasterizer(const WorldScene &scene, const unsigned int imageWidth,
               const unsigned int imageHeight);
    const Image renderImage();

 private:
    const double imageWidth;
    const double imageHeight;
    const WorldScene &scene;
    std::vector<std::vector<double>> zBuffer;
    Image* renderedImage;

    std::vector<Triangle> transformTrianglesToCameraCoords(const WorldScene &scene);
    std::vector<TriangleOnViewport> transformTrianglesToViewportCoords(const std::vector<Triangle> &triangles, const CameraRasterization &camera);
    Image fillPixelsOnFinalImage(const std::vector<TriangleOnViewport> &triangles);

    // Temporary!!!
    CameraRasterization camera;
};


#endif //IMAGE_GENERATOR_RASTERIZER_H
