#include "shared/Image.h"
#include "shared/WorldScene.h"
#include "shared/Sphere.h"

#include <stdio.h>


int main (int argc, char *argv[]) {

    WorldScene scene;
    Sphere * s = new Sphere(1.5, Vector3(0,5,5));
    s->color = Color(1,0,0);
    s->emissionColor = Color(0,0,0);
    scene.addObject(s);
    Sphere * lightSource = new Sphere(2, Vector3(3,-2,5));
    lightSource->color = Color(1,1,1);
    lightSource->emissionColor = Color(1,1,1);
    scene.addObject(lightSource);

    //camera
    Vector3 cam(0,0, -10);

	int dpi = 72;
	unsigned long width = 640;
	unsigned long height = 480;

    double pixelSize = 0.05;
    Image * image = new Image(width, height);
    double pixelDist = 5.0;

    for (int h = 0; h < height; h++) {
        for (int w = 0; w < width; w++) {

            Vector3 pixelPos((w  - width / 2.0) * pixelSize, (h - height / 2.0) * pixelSize, -pixelDist);

            //check
            Ray ray(cam, pixelPos - cam);

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
                            lightSrc->emissionColor * (intercObj->color * transmission *
                            max(0.0, norm.dot(lightDir)));
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