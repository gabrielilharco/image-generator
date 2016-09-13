//
// Created by muzio on 8/22/16.
//

#include "raytracer/RayTracer.h"

#include <math.h>

double mix (double a, double b, double m) {
    return m * b + (1 - m)*a;
}

Color RayTracer::traceRay(const Ray& ray, const WorldScene& ws, int depth) {

    Object *intercObj = NULL;
    double distToInter = ws.getFirstIntersection(ray, intercObj);
    Color color(0,0,0);

    if (distToInter < INF) {

        Vector3 intercPoint = ray.origin + ray.direction * distToInter;
        Vector3 norm = intercObj->getNormalAt(intercPoint);
        if ((intercObj->transparency > 0 || intercObj->reflection > 0) && depth < max_depth) {
            double facingRatio = -norm.dot(ray.direction);
            double fresnelEffect = mix(pow(1 - facingRatio, 3), 1, 0.1);
            double bias = 1e-4;
            bool inside = false;
            if (norm.dot(ray.direction) > 0) {
                norm = norm*-1;
                inside = true;
            }
            Vector3 reflDir = ray.direction - norm * 2 * norm.dot(ray.direction);
            reflDir.normalize();
            Ray reflRay(intercPoint+norm*bias, reflDir);
            Color reflection = traceRay(reflRay, ws, depth+1);
           // cout << reflection.r << " " << reflection.g << " " << reflection.b << endl;
            Color refraction = Color(0,0,0);
            if (intercObj->transparency > 0) {
                double ior = 1.1, eta = (inside) ? ior : 1 / ior;
                double cosi = -norm.dot(ray.direction);
                double k = 1 - eta * eta * (1 - cosi * cosi);
                Vector3 refrDir = ray.direction * eta + norm * (eta *  cosi - sqrt(k));
                refrDir.normalize();
                Ray newRay(intercPoint - norm*bias, refrDir);
                refraction = traceRay(newRay, ws, depth + 1);
            }
            fresnelEffect = 1;
            color = (reflection * fresnelEffect + refraction * (1 - fresnelEffect) * intercObj->transparency) * intercObj->color;
        }
        else {
            for (int i = 0; i < ws.lights().size(); i++) {

                Light *light = ws.lights()[i];
                Vector3 lightDir = light->directionAt(intercPoint);
                Ray lightRay(intercPoint, lightDir * -1);

                double transmission = 1;
                for (int j = 0; j < ws.objects().size(); j++) {
                    if (ws.objects()[j] == intercObj) continue;

                    double dist = ws.objects()[j]->getFirstIntersection(lightRay);
                    //@fixme
                    if (dist != INF && dist < light->distanceAt(intercPoint)) {
                        transmission = 0;
                        break;
                    }
                }
                double cos = norm.dot(lightDir);
                if (cos < 0)
                    color = color + light->colorAt(intercPoint) * intercObj->color * transmission * fabs(cos);
            }
        }
    }
    return color;
}

void RayTracer::render(const WorldScene &ws, const Camera& camera, Image* image) {

    double pixelSizeX = (camera.calculateTopLeft()-camera.calculateTopRight()).abs()/image->width;
    double pixelSizeY = (camera.calculateTopLeft()-camera.calculateBottomLeft()).abs()/image->height;
    Vector3 cameraHorizontal = (camera.calculateTopRight()-camera.calculateTopLeft()).normalize();
    Vector3 cameraVertical = (camera.calculateBottomLeft()-camera.calculateTopLeft()).normalize();

    auto i = camera.calculateTopLeft();
    auto t = camera.calculateTopRight();
    auto k = camera.calculateBottomLeft();
    auto x = camera.calculateBottomRight();


    for (int h = 0; h < image->height; h++) {
        for (int w = 0; w < image->width; w++) {
            double xIncrement = pixelSizeX/(samplesSqrtPerPixel+1);
            double yIncrement = pixelSizeY/(samplesSqrtPerPixel+1);
            for (int i = 1; i <= samplesSqrtPerPixel; i++){
                for (int j = 1; j <= samplesSqrtPerPixel; j++) {
                    Vector3 currentPosition = camera.calculateTopLeft() + cameraHorizontal*((w+i*xIncrement)*pixelSizeX) + cameraVertical*((h+j*yIncrement)*pixelSizeY);
                    Ray ray(camera.calculateOrigin(), currentPosition - camera.calculateOrigin());
                    image->pixels[h][w] = image->pixels[h][w] + traceRay(ray, ws, 0);
                }
            }
            image->pixels[h][w] = image->pixels[h][w]/(samplesSqrtPerPixel*samplesSqrtPerPixel);

        }
    }

    //image->antiAlias();
    //image->normalize();
    image->saveToFile("test.bmp", image->dpi);
}

