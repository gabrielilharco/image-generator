#include "shared/rendering/Image.h"
#include "shared/rendering/WorldScene.h"
#include "shared/geometry/Sphere.h"
#include "shared/rendering/Camera.h"
#include "shared/rendering/DirectionalLight.h"
#include "rasterizer/Rasterizer.h"
#include "raytracer/RayTracer.h"

#include "shared/geometry/Triangle.h"


int rayTracer() {
    WorldScene scene;
    scene.addObject(new Sphere(4, Vector3(0,0,10), Color(1,0,0)));
    scene.addObject(new Sphere(1.5, Vector3(-2,0,5), Color(0,1,0)));
    //scene.addLight(new DirectionalLight(Color(1,1,1), Vector3(1,0,0)));
    scene.addLight(new DirectionalLight(Color(1,1,1), Vector3(1,1,1)));
    //camera
    int height = 4800;
    int width = 6400;
    Camera camera(width, height);

    int dpi = 72;

    Image * image = new Image(width, height, dpi);
    RayTracer rayTracer;
    rayTracer.render(scene, camera, image);

    return 0;
};

int rasterization() {
    WorldScene scene;
    Triangle triangle(Vector3(-0.5, -0.5, -3),
                      Vector3(0.0, 0.5, -3),
                      Vector3(0.5, -0.5, -3));
    scene.addObject(&triangle);
    Rasterizer rasterizer(scene, 640, 480);
    (rasterizer.renderImage()).saveToFile("testRasterization.bmp", 72);
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
