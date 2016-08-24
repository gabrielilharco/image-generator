#include "shared/Image.h"
#include "shared/WorldScene.h"
#include "shared/Sphere.h"

int main (int argc, char *argv[]) {

    WorldScene scene;
    scene.addObject(new Sphere(5.0, Vector3(0,0,0)));

    //camera
    Vector3 cam(0,0, -10);

	int dpi = 72;
	unsigned long width = 640;
	unsigned long height = 480;

    double pixelSize = 0.1;
    Image * image = new Image(width, height);
    double pixelDist = 5.0;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {

            Vector3 pixelPos(i * pixelSize - width / 2.0, j * pixelSize - height / 2.0, -pixelDist);

            Ray ray(cam, pixelPos);

            Object *intercObj = NULL;
            scene.getFirstIntersection(ray, intercObj);

            if (intercObj != NULL) {
                double distToInter = intercObj->getFirstIntersection(ray);
                image->pixels[i][j] = intercObj->color;


            }
        }
    }



	image->saveToFile("test.bmp",dpi);
	
	return 0;
}