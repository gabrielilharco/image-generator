#include "shared/rendering/Image.h"
#include "shared/rendering/WorldScene.h"
#include "shared/rendering/DirectionalLight.h"
#include "rasterizer/Rasterizer.h"
#include "raytracer/RayTracer.h"
#include <chrono>
#include <shared/rendering/PointLight.h>
#include <shared/rendering/SphereLight.h>

int rayTracer(WorldScene scene2, Camera camera2, unsigned int width2, unsigned int height2) {

    WorldScene scene;
    //scene.addSphere(new Sphere(2, Vector3(2,-8,0), Color(1,1,1), 1, 0));
    //scene.addSphere(new Sphere(3, Vector3(-4,-7,-10), Color(1,1,1), 1, 0));
    scene.addSphere(new Sphere(3.4, Vector3(-3,-6,-4), Color(1,1,1), 1, 0));
    //scene.addSphere(new Sphere(4, Vector3(0,12,-2), Color(1,1,1), 0, 0));

    scene.addSphere((new Sphere(1e5, Vector3(1e5+10,0,0), Color(.25,.25,.75),0,0)));
    scene.addSphere((new Sphere(1e5, Vector3(-1e5-10,0, 0), Color(.75,.25,.25),0,0)));
    scene.addSphere((new Sphere(1e5, Vector3(0,0, -1e5-20), Color(.25,.25,.25),0,0)));
    scene.addSphere((new Sphere(1e5, Vector3(0,1e5+10,0), Color(.75,.75,.75),0,0)));
    scene.addSphere((new Sphere(1e5, Vector3(0,-1e5-10,0), Color(.75,.75,.75),0,0)));
    scene.addSphere((new Sphere(1e5, Vector3(0,0,1e5+22), Color(0,0,0),0,0)));

    //scene.addSphere((new Sphere(100, Vector3(0,99,10), Color(1,1,1),0,0)));
    //scene.addSphere((new Sphere(10, Vector3(0,0, -10-20), Color(.25,.25,.25),0,0)));
    //scene.addLight(new PointLight(Color(0.05,0.05,0.05), Vector3(0,9,4)));
    scene.addLight(new SphereLight(Color(0.7,0.7,0.7), Vector3(0,9,2), 0.1));

    //camera

    unsigned int height = 480*1.0;
    unsigned int width = 480*1.0;

    Camera camera(Matrix44(std::vector<double> { 1, 0, 0, 0,
                                                 0, 1, 0, 0,
                                                 0, 0, 1, 0,
                                                 0, 0, 65,0}), 45, 15, 15);

    int dpi = 72;

    Image * image = new Image(width, height, dpi);
    RayTracer rayTracer(1, 2);
    rayTracer.render(scene, camera, image);
    return 0;
};

int rasterization(WorldScene scene, Camera camera, unsigned int width, unsigned int height) {
    unsigned int dpi = 72;
    Rasterizer rasterizer(scene, width, height, camera);
    rasterizer.renderImage().saveToFile("testRasterization.bmp", dpi);
    return 0;
}


int main (int argc, char *argv[]) {
    if (argc != 2) {
        std::cout << "Bad arguments" << std::endl;
        return 1;
    }
    std::string rayTracerParameter = "-raytracer";
    std::string rasterizationParameter = "-rasterization";

    unsigned int width = 640;
    unsigned int height = 480;

//    WorldScene scene;
//    scene.addSphere(new Sphere(4, Vector3(0,0,0), Color(1,0,0), 0, 1));
//    scene.addSphere(new Sphere(1.5, Vector3(6,0,0), Color(1,0,0), 0, 1));
//    scene.addLight(new DirectionalLight(Color(1,1,1), Vector3(1,1,1)));
//    Camera camera(Matrix44(std::vector<double> {1, 0, 0, 0,
//                                                0, 1, 0, 0,
//                                                0, 0, 1, 0,
//                                                0, 0,20,1}), 10, 20, 15);

    WorldScene scene;
    scene.addSphere(new Sphere(1.5, Vector3(1,-3,0), Color(0,1,0), 0, 0));
    scene.addSphere(new Sphere(4, Vector3(-2,0,-5), Color(1,1,1), 1, 0));

//    scene.addSphere((new Sphere(1e5, Vector3(1e5+10,0,0), Color(.25,.25,.75),0,0)));
    scene.addTriangle(new Triangle(Vector3(10, -15, -25), Vector3(10, -15, 25), Vector3(10, 15, -25), Color(.25,.25,.75)));
    scene.addTriangle(new Triangle(Vector3(10, 15, 25), Vector3(10, 15, -25), Vector3(10, -15, 25), Color(.25,.25,.75)));
//    scene.addSphere((new Sphere(1e5, Vector3(-1e5-10,0, 0), Color(.75,.25,.25),0,0)));
    scene.addTriangle(new Triangle(Vector3(-10, -15, -25), Vector3(-10, 15, -25), Vector3(-10, -15, 25), Color(.75,.25,.25)));
    scene.addTriangle(new Triangle(Vector3(-10, 15, 25), Vector3(-10, -15, 25), Vector3(-10, 15, -25), Color(.75,.25,.25)));
//    scene.addSphere((new Sphere(1e5, Vector3(0,0, -1e5-20), Color(1,0,0),0,0)));
    scene.addTriangle(new Triangle(Vector3(-15, -15, -20), Vector3(15, -15, -20), Vector3(-15, 15, -20), Color(.25,.25,.25)));
    scene.addTriangle(new Triangle(Vector3(15, 15, -20), Vector3(-15, 15, -20), Vector3(15, -15, -20), Color(.25,.25,.25)));
    //scene.addSphere((new Sphere(1e5, Vector3(0,1e5+10,0), Color(0,0,1),0,0)));
    scene.addTriangle(new Triangle(Vector3(-15, 10, -25), Vector3(-15, 10, 25), Vector3(15, 10, -25), Color(.75,.75,.75)));
    scene.addTriangle(new Triangle(Vector3(15, 10, 25), Vector3(15, 10, -25), Vector3(-15, 10, 25), Color(.75,.75,.75)));
//    scene.addSphere((new Sphere(1e5, Vector3(0,-1e5-10,0), Color(.75,.75,.75),0,0)));
    scene.addTriangle(new Triangle(Vector3(-15, -10, -25), Vector3(15, -10, -25), Vector3(-15, -10, 25), Color(.75,.75,.75)));
    scene.addTriangle(new Triangle(Vector3(15, -10, 25), Vector3(-15, -10, 25), Vector3(15, -10, -25), Color(.75,.75,.75)));
//    scene.addSphere((new Sphere(1e5, Vector3(0,0,1e5+22), Color(0,0,0),0,0)));

    scene.addLight(new DirectionalLight(Color(0.051,0.051,0.051), Vector3(2,2,2)));
    scene.addLight(new DirectionalLight(Color(0.051,0.051,0.051), Vector3(-2,2,2)));

    Camera camera(Matrix44(std::vector<double> { 1, 0, 0, 0,
                                                 0, 1, 0, 0,
                                                 0, 0, 1, 0,
                                                 0, 0, 65,1}), 45, 20, 15);

    std::chrono::high_resolution_clock::time_point t1 =
        std::chrono::high_resolution_clock::now();
    if (rayTracerParameter.compare(argv[1]) == 0) {
        rayTracer(scene, camera, width, height);
    }
    else if (rasterizationParameter.compare(argv[1]) == 0) {
        rasterization(scene, camera, width, height);
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
