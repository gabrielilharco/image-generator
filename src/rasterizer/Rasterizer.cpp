//
// Created by matheus on 8/28/16.
//

#include <rasterizer/geometry/BoundingBox.h>
#include <math.h>
#include <rasterizer/geometry/SphereToTrianglesGenerator.h>
#include <limits>
#include "rasterizer/Rasterizer.h"

Rasterizer::Rasterizer(const WorldScene &scene, const unsigned int imageWidth, const unsigned int imageHeight, const Camera camera)
    : scene(scene), imageWidth(imageWidth), imageHeight(imageHeight),
      camera(camera) {}

const Image Rasterizer::renderImage() {

    std::vector<Triangle> triangleList;

    for (int i = 0; i < scene.spheres().size(); i++) {
        std::vector<Triangle> sphereTriangles = SphereToTrianglesGenerator::createTriangles(
            scene.spheres()[i]->radius, scene.spheres()[i]->center, scene.spheres()[i]->color, 3);
        for (int j = 0; j < sphereTriangles.size(); j++) {
            triangleList.push_back(sphereTriangles[j]);
        }
    }

    for (int i = 0; i < scene.triangles().size(); i++) {
        triangleList.push_back(*scene.triangles()[i]);
    }

    std::vector<Triangle> trianglesWithCameraCoords =
        transformTrianglesToCameraCoords(triangleList, camera);
    std::vector<TriangleProjection> trianglesOnScreen =
        transformTrianglesToViewportCoords(trianglesWithCameraCoords, camera);
    Image renderedImage = fillPixelsOnFinalImage(trianglesOnScreen);
    return renderedImage;
}


std::vector<Triangle> Rasterizer::transformTrianglesToCameraCoords(const std::vector<Triangle> &triangles, const Camera &camera) {
    std::vector<Triangle> result;
    Vector3 aOnCameraCoords, bOnCameraCoords, cOnCameraCoords;
    for (int i = 0; i < triangles.size(); i++) {
        aOnCameraCoords = triangles[i].a * camera.worldToCamTransform;
        bOnCameraCoords = triangles[i].b * camera.worldToCamTransform;
        cOnCameraCoords = triangles[i].c * camera.worldToCamTransform;
        result.push_back(Triangle(aOnCameraCoords, bOnCameraCoords, cOnCameraCoords, triangles[i].color));
    }
    return result;
}

std::vector<TriangleProjection> Rasterizer::transformTrianglesToViewportCoords(const std::vector<Triangle> &triangles, const Camera &camera) {
    // Viewport coordinates are from -1 to 1
    std::vector<TriangleProjection> result;
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

        result.push_back(TriangleProjection(aOnViewport, bOnViewport, cOnViewport, triangles[i]));
    }

    return result;
}

Color Rasterizer::getColorAt(Triangle t) {
    Vector3 mid = t.a/3 + t.b/3 + t.c/3;
    Vector3 normal = t.getNormalAt(mid);

    std::vector<Light *> light = scene.lights();

    Color rgb = Color(t.color.r*255, t.color.g*255, t.color.b*255);
    HSL triangleHSL = rgb.toHSL();
    double maxLuminance = 0;

    for(int i = 0; i < light.size(); i++) {
        Vector3 dir = light[i]->directionAt(mid);
        dir = dir.normalize();

        double luminance = dir.dot(normal);
        if(luminance > maxLuminance) maxLuminance = luminance;
    }
    triangleHSL.setLuminance(triangleHSL.l*maxLuminance);

    Color colorTrick = triangleHSL.toRGB();
    colorTrick.r /= 255;
    colorTrick.g /= 255;
    colorTrick.b /= 255;
    return colorTrick;
}

Image Rasterizer::fillPixelsOnFinalImage(const std::vector<TriangleProjection> &triangles) {
    Image stub(imageWidth, imageHeight, 72);

    //Set zbuffer to infinity to all pixels
    zBuffer.resize(imageWidth);
    for(int i = 0; i < imageWidth; i++) {
        zBuffer[i].resize(imageHeight);
        zBuffer[i].assign(imageHeight, std::numeric_limits<double>::infinity());
    }

    for(int i = 0; i < triangles.size(); i++) {
        Vector2 aRaster, bRaster, cRaster;

        aRaster = Vector2((triangles[i].a.x + 1)/2 * imageWidth, (triangles[i].a.y + 1)/2 * imageHeight);
        bRaster = Vector2((triangles[i].b.x + 1)/2 * imageWidth, (triangles[i].b.y + 1)/2 * imageHeight);
        cRaster = Vector2((triangles[i].c.x + 1)/2 * imageWidth, (triangles[i].c.y + 1)/2 * imageHeight);

        TriangleProjection rasterTriangle(aRaster, bRaster, cRaster, triangles[i].correspondentTriangle);
        BoundingBox boundingBox(rasterTriangle);


        for(int x = std::max(0, (int)round(boundingBox.bl.x)); x <= std::min((int)imageWidth-1, (int)round(boundingBox.tr.x)); x++) {
            for(int y = std::max(0, (int)round(boundingBox.bl.y)); y <= std::min((int)imageHeight-1, (int)round(boundingBox.tr.y)); y++) {
                Vector2 pixel(x, y);

                if(!rasterTriangle.isInside(pixel)) continue;

                double z = -rasterTriangle.interpolateDepth(pixel);
                if(z > 0 && z < zBuffer[x][y]) {
                    stub.pixels[imageHeight - 1 - y][x] = getColorAt(rasterTriangle.correspondentTriangle);
                    zBuffer[x][y] = z;
                }
            }
        }
    }
    return stub;
}