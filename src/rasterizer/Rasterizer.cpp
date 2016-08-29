//
// Created by matheus on 8/28/16.
//

#include "rasterizer/Rasterizer.h"

Rasterizer::Rasterizer(const WorldScene &scene, const unsigned int imageWidth, const unsigned int imageHeight)
    : scene(scene), imageWidth(imageWidth), imageHeight(imageHeight),
      camera (CameraRasterization(Matrix44::inverse(Matrix44(std::vector<double>{0, 1, 0, 0,
                                                                                 0, 0, 1, 0,
                                                                                 1, 0, 0, 0,
                                                                                 1, 2, 3, 1})),
                                                                                 1.0, 4.0, 3.0)) {}

const Image Rasterizer::renderImage() {
    // Mock triangle list with coords related to camera:
    Vector3 a(-0.5, -0.5, -3.0);
    Vector3 b(0.0, 0.5, -3.0);
    Vector3 c(0.5, -0.5, -3.0);
    Triangle t(a, b, c);
    std::vector<Triangle> mockTriangleList;
    mockTriangleList.push_back(t);

    std::vector<Triangle> trianglesWithCameraCoords =
        transformTrianglesToCameraCoords(mockTriangleList, camera);
    std::vector<TriangleOnViewport> trianglesOnScreen =
        transformTrianglesToViewportCoords(mockTriangleList, camera);
    Image renderedImage = fillPixelsOnFinalImage(trianglesOnScreen);
    return renderedImage;
}


std::vector<Triangle> Rasterizer::transformTrianglesToCameraCoords(const std::vector<Triangle> &triangles, const CameraRasterization &camera) {
    std::vector<Triangle> result;
    Vector3 aOnCameraCoords, bOnCameraCoords, cOnCameraCoords;
    for (int i = 0; i < triangles.size(); i++) {
        aOnCameraCoords = triangles[i].a * camera.transform;
        bOnCameraCoords = triangles[i].b * camera.transform;
        cOnCameraCoords = triangles[i].c * camera.transform;
        result.push_back(Triangle(aOnCameraCoords, bOnCameraCoords, cOnCameraCoords));
    }
    return result;
}

std::vector<TriangleOnViewport> Rasterizer::transformTrianglesToViewportCoords(const std::vector<Triangle> &triangles, const CameraRasterization &camera) {
    // Viewport coordinates are from -1 to 1
    std::vector<TriangleOnViewport> result;
    Vector2 aOnViewport, bOnViewport, cOnViewport;

    for (int i = 0; i < triangles.size(); i++) {
        // Finds x-y position on viewport
        aOnViewport.x = - (triangles[i].a.x * camera.distanceToViewport) / triangles[i].a.z;
        aOnViewport.y = - (triangles[i].a.y * camera.distanceToViewport) / triangles[i].a.z;
        bOnViewport.x = - (triangles[i].b.x * camera.distanceToViewport) / triangles[i].b.z;
        bOnViewport.y = - (triangles[i].b.y * camera.distanceToViewport) / triangles[i].b.z;
        cOnViewport.x = - (triangles[i].c.x * camera.distanceToViewport) / triangles[i].c.z;
        cOnViewport.y = - (triangles[i].c.y * camera.distanceToViewport) / triangles[i].c.z;

        // Normalizes these values to [-1, 1] (outside this interval means out of the viewport)
        aOnViewport.x /= (camera.width / 2);
        aOnViewport.y /= (camera.height / 2);
        bOnViewport.x /= (camera.width / 2);
        bOnViewport.y /= (camera.height / 2);
        cOnViewport.x /= (camera.width / 2);
        cOnViewport.y /= (camera.height / 2);

        result.push_back(TriangleOnViewport(aOnViewport, bOnViewport, cOnViewport, triangles[i]));
    }

    return result;
}

Image Rasterizer::fillPixelsOnFinalImage(const std::vector<TriangleOnViewport> &triangles) {
    Image stub(640, 480);
    return stub;
}