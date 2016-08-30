#include "shared/rendering/Image.h"
#include "shared/rendering/WorldScene.h"
#include "shared/rendering/DirectionalLight.h"
#include "rasterizer/Rasterizer.h"
#include "raytracer/RayTracer.h"
#include "shared/geometry/Triangle.h"
#include <math.h>
#include <chrono>


int rayTracer() {
    WorldScene scene;
    scene.addSphere(new Sphere(4, Vector3(0,0,10), Color(1,0,0)));
    scene.addSphere(new Sphere(1.5, Vector3(-2,0,5), Color(0,1,0)));
    //scene.addLight(new DirectionalLight(Color(1,1,1), Vector3(1,0,0)));
    scene.addLight(new DirectionalLight(Color(1,1,1), Vector3(1,1,1)));
    //camera
    unsigned int height = 480;
    unsigned int width = 640;
    Camera camera(Matrix44(std::vector<double> {-1, 0, 0, 0,
                                                 0, 1, 0, 0,
                                                 0, 0,-1, 0,
                                                 0, 0,-10,0}), 10, 20, 15);

    int dpi = 72;

    Image * image = new Image(width, height, dpi);
    RayTracer rayTracer(2);
    rayTracer.render(scene, camera, image);

    return 0;
};

int rasterization() {
    WorldScene scene;
    Triangle triangle(Vector3(-0.5, -0.5, -3),
                      Vector3(0.0, 0.5, -3),
                      Vector3(0.5, -0.5, -3));
    scene.addTriangle(&triangle);
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

    std::chrono::high_resolution_clock::time_point t1 =
        std::chrono::high_resolution_clock::now();
    if (rayTracerParameter.compare(argv[1]) == 0) {
        rayTracer();
    }
    else if (rasterizationParameter.compare(argv[1]) == 0) {
        rasterization();
    }
    else {
        std::cout << "Bad arguments" << std::endl;
        return 1;
    }
    std::chrono::high_resolution_clock::time_point t2 =
        std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();

    std::cout << "Execution time = " << duration * 1.0 / 1000000 << std::endl;
    return 0;
}
