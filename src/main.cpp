#include "shared/Image.h"
#include "shared/WorldScene.h"
#include "shared/Sphere.h"
#include "shared/Camera.h"
#include <stdio.h>


int main (int argc, char *argv[]) {

    WorldScene scene;
    Sphere * s = new Sphere(1.5, Vector3(0,5,5));
    s->color = Color(1,0,0);
    s->emissionColor = Color(0,0,0);
//    scene.addObject(s);
    Sphere * lightSource = new Sphere(0.1, Vector3(0,0,4));
    lightSource->color = Color(0,1,0);
    lightSource->emissionColor = Color(1,0,0);
    scene.addObject(lightSource);
//    Sphere * lightSource2 = new Sphere(1, Vector3(3,-2,5));
//    lightSource2->color = Color(1,1,1);
//    lightSource2->emissionColor = Color(1,1,1);
//    scene.addObject(lightSource2);

    //camera
    //Vector3 cam(0,0, -10);
    int height = 2000;
    int width = 2000;
    Camera camera(width, height);

	int dpi = 72;
//	unsigned long width = 640;
//	unsigned long height = 480;

//    double pixelSize = 0.05;
    Image * image = new Image(width, height);
    double pixelSizeX = (camera.top_left-camera.top_right).abs()/width;
    double pixelSizeY = (camera.top_left-camera.bot_left).abs()/height;
    Vector3 cameraHorizontal = (camera.top_left-camera.top_right).normalize();
    Vector3 cameraVertical = (camera.top_left-camera.bot_left).normalize();

    for (int h = 0; h < height; h++) {
        for (int w = 0; w < width; w++) {

            Vector3 currentPixelPosition = camera.top_left + cameraHorizontal*((w+0.5)*pixelSizeX) + cameraVertical*((h+0.5)*pixelSizeY);

            Ray ray(camera.origin, currentPixelPosition - camera.origin);

            Object *intercObj = NULL;
            double distToInter = scene.getFirstIntersection(ray, intercObj);

            //if (intercObj != NULL)
            //    printf("Obj not null!! - %lf\n", distToInter);

            if (distToInter >= 0) {
                Vector3 intercPoint = ray.origin + ray.direction.normalize() * distToInter;
                Vector3 norm = intercObj->getNormalAt(intercPoint);

//                printf("batataaaaaaaaa");
                for (int i = 0; i < scene.worldObjects().size(); i++) {
                    // FIXME
                    if (scene.worldObjects()[i]->emissionColor.r <= 0.0) continue;

                    Sphere* lightSrc = (Sphere*) scene.worldObjects()[i];
                    Vector3 lightDir = (lightSrc->center - intercPoint).normalize();

                    Color transmission(1,1,1);
                    for (int j = 0; j < scene.worldObjects().size(); j++) {
                        if (i == j || scene.worldObjects()[j] == intercObj) continue;

                        Ray lightRay(intercPoint, lightDir);
                        double dist = scene.worldObjects()[j]->getFirstIntersection(lightRay);

                        //if intersects
                        if (dist >= 0) {
                            transmission = Color(0,0,0);
                            break;
                        }
                    }

                    image->pixels[h][w] = image->pixels[h][w] +
                            lightSrc->emissionColor * intercObj->color * transmission *
                            max(0.0, norm.dot(lightDir));
//                    cout << "n: " << norm.dot(lightDir) <<" t:" << transmission.b << endl;
                }
//                cout << (image->pixels[h][w]).r <<  " " << (image->pixels[h][w]).g
//                     << " " << (image->pixels[h][w]).b << endl;
                image->pixels[h][w] = (image->pixels[h][w] + intercObj->emissionColor)*255;
            }
        }
    }

    image->saveToFile("test.bmp",dpi);
	
	return 0;
}