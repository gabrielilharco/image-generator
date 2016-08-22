#include "shared/Image.h"

int main (int argc, char *argv[]) {

	int dpi = 72;
	unsigned long width = 640;
	unsigned long height = 480;
	Image * image = new Image(width, height);
	
	image->saveToFile("test.bmp",dpi);
	
	return 0;
}