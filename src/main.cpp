#include "shared/rendering/Image.h"
#include "shared/rendering/WorldScene.h"
#include "shared/geometry/Sphere.h"
#include "shared/rendering/Camera.h"
#include "shared/rendering/DirectionalLight.h"
#include "rasterizer/Rasterizer.h"
#include "shared/geometry/Triangle.h"
#include <math.h>

int rayTracer() {
    WorldScene scene;
    Sphere * s = new Sphere(4, Vector3(0,0,10));
    s->color = Color(1,0,0);
    scene.addObject(s);
    Light * l = new DirectionalLight(Color(1,1,1), Vector3(1,1,1));
    scene.addLight(l);


    //camera
    int height = 480;
    int width = 640;
    Camera camera(width, height);

    int dpi = 72;

    Image * image = new Image(width, height);
    double pixelSizeX = (camera.top_left-camera.top_right).abs()/width;
    double pixelSizeY = (camera.top_left-camera.bot_left).abs()/height;
    Vector3 cameraHorizontal = (camera.top_right-camera.top_left).normalize();
    Vector3 cameraVertical = (camera.bot_left-camera.top_left).normalize();

    for (int h = 0; h < height; h++) {
        for (int w = 0; w < width; w++) {

            Vector3 currentPixelPosition = camera.top_left + cameraHorizontal*((w+0.5)*pixelSizeX) + cameraVertical*((h+0.5)*pixelSizeY);
            Ray ray(camera.origin, currentPixelPosition - camera.origin);

            Object *intercObj = NULL;
            double distToInter = scene.getFirstIntersection(ray, intercObj);


            if (distToInter < INF) {
                Vector3 intercPoint = ray.origin + ray.direction * distToInter;
                Vector3 norm = intercObj->getNormalAt(intercPoint);

                for (int i = 0; i < scene.lights().size(); i++) {

                    Light * light =  scene.lights()[i];
                    Vector3 lightDir = light->directionAt(intercPoint);

                    Color transmission(1,1,1);
                    for (int j = 0; j < scene.objects().size(); j++) {
                        if (scene.objects()[j] == intercObj) continue;

                        Ray lightRay(intercPoint, lightDir);
                        double dist = scene.objects()[j]->getFirstIntersection(lightRay);

                        //if intersects
                        if (dist >= 0) {
                            transmission = Color(0,0,0);
                            break;
                        }
                    }
                    double cos = norm.dot(lightDir);
                    if (cos < 0)
                        image->pixels[h][w] = image->pixels[h][w] + light->colorAt(intercPoint) * intercObj->color * transmission * fabs(cos);
                }

                image->pixels[h][w] = (image->pixels[h][w])*255;
            }
        }
    }

    image->saveToFile("test.bmp",dpi);

    return 0;
};

int rasterization() {
    WorldScene scene;
    Triangle triangle(Vector3(-0.5, -0.5, -3),
                      Vector3(0.0, 0.5, -3),
                      Vector3(0.5, -0.5, -3));
    scene.addObject(&triangle);
    Rasterizer rasterizer(scene, 640, 480);
    rasterizer.renderImage().saveToFile("testRasterization.bmp", 72);
    return 0;
}


int main (int argc, char *argv[]) {
    if (argc != 2) {
        std::cout << "Bad arguments" << std::endl;
        return 1;
    }
    std::string rayTracerParameter = "-raytracer";
    std::string rasterizationParameter = "-rasterization";
    if (rayTracerParameter.compare(argv[1]) == 0) {
        return rayTracer();
    }
    else if (rasterizationParameter.compare(argv[1]) == 0) {
        return rasterization();
    }
    else {
        std::cout << "Bad arguments" << std::endl;
        return 1;
    }
}
