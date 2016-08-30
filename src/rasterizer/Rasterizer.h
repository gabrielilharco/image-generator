//
// Created by matheus on 8/28/16.
//

#ifndef IMAGE_GENERATOR_RASTERIZER_H
#define IMAGE_GENERATOR_RASTERIZER_H

#include "shared/rendering/Camera.h"
#include "rasterizer/geometry/TriangleProjection.h"
#include "shared/rendering/Image.h"
#include "shared/geometry/Triangle.h"
#include "shared/rendering/WorldScene.h"

class Rasterizer {
 public:
    Rasterizer(const WorldScene &scene, const unsigned int imageWidth,
               const unsigned int imageHeight);
    const Image renderImage();

 private:
    const unsigned int imageWidth;
    const unsigned int imageHeight;
    const WorldScene &scene;
    std::vector<std::vector<double>> zBuffer;
    Image* renderedImage;

    std::vector<Triangle> transformTrianglesToCameraCoords(
        const std::vector<Triangle> &triangles, const Camera &camera);
    std::vector<TriangleProjection> transformTrianglesToViewportCoords(
        const std::vector<Triangle> &triangles, const Camera &camera);
    Image fillPixelsOnFinalImage(const std::vector<TriangleProjection> &triangles);

    // Temporary!!!
    Camera camera;
};


#endif //IMAGE_GENERATOR_RASTERIZER_H
