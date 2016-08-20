#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include "Color.h"

using namespace std;

class Image {
	public:
		vector<vector<Color> > pixels;

		Image (int, int);
		Image (vector<vector<Color> >);

		void saveToFile(const char * , int);
};

void Image::saveToFile (const char * filename, int dpi) {
	FILE *f;
	int height = pixels.size();
	int width = pixels[0].size();
	int size = 4*width*height;
	int filesize = 54 + size;
	
	int ppm = dpi*static_cast<int>(39.375);
	
	unsigned char bmpfileheader[14] = {'B','M', 0,0,0,0, 0,0,0,0, 54,0,0,0};
	unsigned char bmpinfoheader[40] = {40,0,0,0, 0,0,0,0, 0,0,0,0, 1,0,24,0};
	
	bmpfileheader[ 2] = (unsigned char)(filesize);
	bmpfileheader[ 3] = (unsigned char)(filesize>>8);
	bmpfileheader[ 4] = (unsigned char)(filesize>>16);
	bmpfileheader[ 5] = (unsigned char)(filesize>>24);
	
	bmpinfoheader[ 4] = (unsigned char)(width);
	bmpinfoheader[ 5] = (unsigned char)(width>>8);
	bmpinfoheader[ 6] = (unsigned char)(width>>16);
	bmpinfoheader[ 7] = (unsigned char)(width>>24);
	
	bmpinfoheader[ 8] = (unsigned char)(height);
	bmpinfoheader[ 9] = (unsigned char)(height>>8);
	bmpinfoheader[10] = (unsigned char)(height>>16);
	bmpinfoheader[11] = (unsigned char)(height>>24);
	
	bmpinfoheader[21] = (unsigned char)(size);
	bmpinfoheader[22] = (unsigned char)(size>>8);
	bmpinfoheader[23] = (unsigned char)(size>>16);
	bmpinfoheader[24] = (unsigned char)(size>>24);
	
	bmpinfoheader[25] = (unsigned char)(ppm);
	bmpinfoheader[26] = (unsigned char)(ppm>>8);
	bmpinfoheader[27] = (unsigned char)(ppm>>16);
	bmpinfoheader[28] = (unsigned char)(ppm>>24);
	
	bmpinfoheader[29] = (unsigned char)(ppm);
	bmpinfoheader[30] = (unsigned char)(ppm>>8);
	bmpinfoheader[31] = (unsigned char)(ppm>>16);
	bmpinfoheader[32] = (unsigned char)(ppm>>24);
	
	f = fopen(filename,"wb");
	
	fwrite(bmpfileheader,1,14,f);
	fwrite(bmpinfoheader,1,40,f);
	
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			unsigned char color[3] = {pixels[i][j].b, pixels[i][j].g, pixels[i][j].r};
			fwrite(color,1,3,f);
		}
	}
	
	fclose(f);
}


Image::Image (int width, int height) {
	vector<vector<Color> > p(height, vector<Color>(width));
	pixels = p;
}

Image::Image (vector<vector<Color> > p) {
	pixels = p;
}