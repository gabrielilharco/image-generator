//
// Created by muzio on 8/22/16.
//

#include "raytracer/RayTracer.h"
#include <shared/rendering/SphereLight.h>

double mix (double a, double b, double m) {
    return m * b + (1 - m)*a;
}

Color RayTracer::traceRay(const Ray& ray, const WorldScene& ws, const Camera& camera, int depth) {

    Object *intercObj = NULL;
    double distToInter = ws.getFirstIntersection(ray, intercObj, camera);
    Color color(0,0,0);

    if (distToInter < INF) {

        Vector3 intercPoint = ray.origin + ray.direction * distToInter;
        Vector3 norm = intercObj->getNormalAt(intercPoint);
        if ((intercObj->transparency > 0 || intercObj->reflection > 0) && depth < max_depth) {
            if (norm.dot(ray.direction) > 0)
                norm = norm*-1;
            double facingRatio = -norm.dot(ray.direction);
            double fresnelEffect = mix(pow(1 - facingRatio, 3), 1, 0.1);
            double bias = 1e-4;
            bool inside = norm.dot(ray.direction) < 0;
            Vector3 reflDir = ray.direction - norm * 2 * norm.dot(ray.direction);
            reflDir.normalize();
            Ray reflRay(intercPoint+norm*bias, reflDir);
            Color reflection = traceRay(reflRay, ws, camera, depth+1);

            Color refraction = Color(0,0,0);
            if (intercObj->transparency > 0) {
                double ior = 1.01, eta = (inside) ? ior : 1 / ior;
                double cosi = -norm.dot(ray.direction);
                double k = 1 - eta * eta * (1 - cosi * cosi);
                Vector3 refrDir = ray.direction * eta + norm * (eta *  cosi - sqrt(k));
                refrDir.normalize();
                Ray refRay(intercPoint - norm*bias, refrDir);
                refraction = traceRay(refRay, ws, camera, depth + 1);
                //cout << refraction.r << " " << refraction.g << " " << refraction.b << endl;
            }
            fresnelEffect = 0.8;
            color = (reflection * fresnelEffect + refraction * (1 - fresnelEffect) * intercObj->transparency) * intercObj->color;
        }
        else {
            for (int i = 0; i < ws.lights().size(); i++) {
                // TODO: refactor.
                SphereLight* light = (SphereLight*)ws.lights()[i];
                Vector3 lightDir = light->directionAt(intercPoint);
                double cos = norm.dot(lightDir.normalize());
                if (cos < 0)
                    color = color + light->colorAt(intercPoint, ws, camera) * intercObj->color * fabs(cos);
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

    for (int h = 0; h < image->height; h++) {
        for (int w = 0; w < image->width; w++) {
            double xIncrement = pixelSizeX/(samplesSqrtPerPixel+1);
            double yIncrement = pixelSizeY/(samplesSqrtPerPixel+1);
            for (int i = 1; i <= samplesSqrtPerPixel; i++){
                for (int j = 1; j <= samplesSqrtPerPixel; j++) {
                    Vector3 currentPosition = camera.calculateTopLeft() + cameraHorizontal*((w+i*xIncrement)*pixelSizeX) + cameraVertical*((h+j*yIncrement)*pixelSizeY);
                    Ray ray(camera.calculateOrigin(), currentPosition - camera.calculateOrigin());
                    image->pixels[h][w] = image->pixels[h][w] + traceRay(ray, ws, camera, 0);
                }
            }
            image->pixels[h][w] = image->pixels[h][w]/(samplesSqrtPerPixel*samplesSqrtPerPixel);

        }
    }

    image->antiAlias();
    //image->normalize();
    image->saveToFile("test.bmp", image->dpi);
}

