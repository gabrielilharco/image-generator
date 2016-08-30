//
// Created by muzio on 8/22/16.
//

#include "raytracer/RayTracer.h"

#include <math.h>

Color RayTracer::traceRay(const Ray& ray, const WorldScene& ws) {

    Object *intercObj = NULL;
    double distToInter = ws.getFirstIntersection(ray, intercObj);
    Color color(0,0,0);

    if (distToInter < INF) {
        Vector3 intercPoint = ray.origin + ray.direction * distToInter;
        Vector3 norm = intercObj->getNormalAt(intercPoint);

        for (int i = 0; i < ws.lights().size(); i++) {

            Light * light =  ws.lights()[i];
            Vector3 lightDir = light->directionAt(intercPoint);
            Ray lightRay(intercPoint, lightDir*-1);

            double transmission = 1;
            for (int j = 0; j < ws.objects().size(); j++) {
                if (ws.objects()[j] == intercObj) continue;

                double dist = ws.objects()[j]->getFirstIntersection(lightRay);
                if (dist != INF) {
                    transmission = 0;
                    break;
                }
            }
            double cos = norm.dot(lightDir);
            if (cos < 0)
                color = color + light->colorAt(intercPoint) * intercObj->color * transmission * fabs(cos);
        }
    }
    return color;
}

void RayTracer::render(const WorldScene &ws, const Camera& camera, Image* image) {

    double pixelSizeX = (camera.calculateTopLeft()-camera.calculateTopRight()).abs()/image->width;
    double pixelSizeY = (camera.calculateTopLeft()-camera.calculateBottomLeft()).abs()/image->height;
    Vector3 cameraHorizontal = (camera.calculateTopRight()-camera.calculateTopLeft()).normalize();
    Vector3 cameraVertical = (camera.calculateBottomLeft()-camera.calculateTopLeft()).normalize();

    for (int h = 0; h < image->height; h++) {
        for (int w = 0; w < image->width; w++) {
            double xIncrement = pixelSizeX/(samplesSqrtPerPixel+1);
            double yIncrement = pixelSizeY/(samplesSqrtPerPixel+1);
            for (int i = 1; i <= samplesSqrtPerPixel; i++){
                for (int j = 1; j <= samplesSqrtPerPixel; j++) {
                    Vector3 currentPosition = camera.calculateTopLeft() + cameraHorizontal*((w+i*xIncrement)*pixelSizeX) + cameraVertical*((h+j*yIncrement)*pixelSizeY);
                    Ray ray(camera.calculateOrigin(), currentPosition - camera.calculateOrigin());
                    image->pixels[h][w] = image->pixels[h][w] + traceRay(ray, ws);
                }
            }
            image->pixels[h][w] = image->pixels[h][w]/(samplesSqrtPerPixel*samplesSqrtPerPixel);
        }
    }

    image->antiAlias();
    image->normalize();
    image->saveToFile("test.bmp", image->dpi);
}

