#include "shared/Color.h"
#include "shared/Image.h"

int main (int argc, char *argv[]) {

	int dpi = 72;
	int width = 640;
	int height = 480;
	Image * image = new Image(width, height);
	
	image->saveToFile("test.bmp",dpi);
	
	return 0;
}