//
// Created by matheus on 8/28/16.
//

#include "rasterizer/Rasterizer.h"

Rasterizer::Rasterizer(const WorldScene &scene, const unsigned int imageWidth, const unsigned int imageHeight)
    : scene(scene), imageWidth(imageWidth), imageHeight(imageHeight),
      camera (CameraRasterization(Matrix44(std::vector<double>{1, 0, 0, 0,
                                                               0, 1, 0, 0,
                                                               0, 0, 1, 0,
                                                               0, 0, 0, 1}), 1.0, 4.0, 3.0)) {
}

const Image Rasterizer::renderImage() {
    std::vector<Triangle> trianglesWithCameraCoords = transformTrianglesToCameraCoords(scene);
    std::vector<TriangleOnViewport> trianglesOnScreen =
        transformTrianglesToViewportCoords(trianglesWithCameraCoords, camera);
    Image renderedImage = fillPixelsOnFinalImage(trianglesOnScreen);
    return renderedImage;
}


std::vector<Triangle> Rasterizer::transformTrianglesToCameraCoords(const WorldScene &scene) {
    // Returns mock list for now
    std::vector<Triangle> stub;
    return stub;
}

std::vector<TriangleOnViewport> Rasterizer::transformTrianglesToViewportCoords(const std::vector<Triangle> &triangles, const CameraRasterization &camera) {
    // Viewport coordinates are from -1 to 1
    std::vector<TriangleOnViewport> stub;
    return stub;
}

Image Rasterizer::fillPixelsOnFinalImage(const std::vector<TriangleOnViewport> &triangles) {
    Image stub(640, 480);
    return stub;
}