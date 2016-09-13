#include "Image.h"
#include <math.h>

Image::Image (unsigned long  width, unsigned long  height, unsigned int dpi) :
    width(width), height(height), dpi(dpi) {

    vector<vector<Color> > p(height, vector<Color>(width));
    pixels = p;
}

Image::Image (vector<vector<Color>> p) {
    pixels = p;
}

void Image::normalize () {
    unsigned long  height = pixels.size();
    unsigned long  width = pixels[0].size();
    double mx = 0;
    for (unsigned long  i = 0; i < height; i++) {
        for (unsigned long j = 0; j < width; j++) {
            mx = max(max(mx, pixels[i][j].r), max(pixels[i][j].g, pixels[i][j].b));
        }
    }
    if (mx != 0) {
        for (unsigned long  i = 0; i < height; i++) {
            for (unsigned long j = 0; j < width; j++) {
                pixels[i][j].r = (int)(pixels[i][j].r*(255.0/mx));
                pixels[i][j].g = (int)(pixels[i][j].g*(255.0/mx));
                pixels[i][j].b = (int)(pixels[i][j].b*(255.0/mx));
            }
        }
    }
}

void Image::antiAlias() {
    Image auxiliarImage(pixels[0].size(), pixels.size(), dpi);
    // TODO: refactor
    int x_inc[] = { 1,-1, 0, 0, 1, 1,-1,-1, 2, 0,-2, 0, 2, 1, 2,-1,-2, 1,-2,-1, 2,-2, 2,-2};
    int y_inc[] = { 0, 0, 1,-1, 1,-1, 1,-1, 0, 2, 0,-2, 1, 2,-1, 2, 1,-2,-1,-2, 2,-2,-2, 2};

    double weight;
    for (unsigned long  i = 2; i < height-2; i++) {
        for (unsigned long j = 2; j < width-2; j++) {
            double weight_sum = 0;
            auxiliarImage.pixels[i][j] = Color(0,0,0);
            for (int k = 0; k < 24; k++) {
                weight = 1; //1.0/sqrt(x_inc[k]*x_inc[k] + y_inc[k]*y_inc[k]);
                auxiliarImage.pixels[i][j] =
                        auxiliarImage.pixels[i][j] + pixels[i + x_inc[k]][j + y_inc[k]] * weight;
                weight_sum += weight;
            }
            auxiliarImage.pixels[i][j] = auxiliarImage.pixels[i][j]/weight_sum;
        }
    }
    for (unsigned long  i = 0; i < height; i++) {
        for (unsigned long j = 0; j < width; j++) {
            pixels[i][j] = auxiliarImage.pixels[i][j];
        }
    }
}

void Image::saveToFile (const char * filename, int dpi) const{
    FILE *f;
    unsigned long  height = pixels.size();
    unsigned long  width = pixels[0].size();
    unsigned long  size = 4*width*height;
    unsigned long  filesize = 54 + size;

    int ppm = dpi*static_cast<int>(39.375);

    unsigned char bmpFileHeader[14] = {'B','M', 0,0,0,0, 0,0,0,0, 54,0,0,0};
    unsigned char bmpInfoHeader[40] = {40,0,0,0, 0,0,0,0, 0,0,0,0, 1,0,24,0};

    bmpFileHeader[ 2] = (unsigned char)(filesize);
    bmpFileHeader[ 3] = (unsigned char)(filesize>>8);
    bmpFileHeader[ 4] = (unsigned char)(filesize>>16);
    bmpFileHeader[ 5] = (unsigned char)(filesize>>24);

    bmpInfoHeader[ 4] = (unsigned char)(width);
    bmpInfoHeader[ 5] = (unsigned char)(width>>8);
    bmpInfoHeader[ 6] = (unsigned char)(width>>16);
    bmpInfoHeader[ 7] = (unsigned char)(width>>24);

    bmpInfoHeader[ 8] = (unsigned char)(height);
    bmpInfoHeader[ 9] = (unsigned char)(height>>8);
    bmpInfoHeader[10] = (unsigned char)(height>>16);
    bmpInfoHeader[11] = (unsigned char)(height>>24);

    bmpInfoHeader[21] = (unsigned char)(size);
    bmpInfoHeader[22] = (unsigned char)(size>>8);
    bmpInfoHeader[23] = (unsigned char)(size>>16);
    bmpInfoHeader[24] = (unsigned char)(size>>24);

    bmpInfoHeader[25] = (unsigned char)(ppm);
    bmpInfoHeader[26] = (unsigned char)(ppm>>8);
    bmpInfoHeader[27] = (unsigned char)(ppm>>16);
    bmpInfoHeader[28] = (unsigned char)(ppm>>24);

    bmpInfoHeader[29] = (unsigned char)(ppm);
    bmpInfoHeader[30] = (unsigned char)(ppm>>8);
    bmpInfoHeader[31] = (unsigned char)(ppm>>16);
    bmpInfoHeader[32] = (unsigned char)(ppm>>24);

    f = fopen(filename,"wb");

    fwrite(bmpFileHeader,1,14,f);
    fwrite(bmpInfoHeader,1,40,f);

    //Image is reflected on the y-axis
    for (int i = height - 1; i >= 0; i--) {
        for (int j = 0; j < width; j++) {
            unsigned char color[3] = {(unsigned char) max(0.0,min(255.0,(255*pixels[i][j].b))),
                                      (unsigned char) max(0.0,min(255.0,(255*pixels[i][j].g))),
                                      (unsigned char) max(0.0,min(255.0,(255*pixels[i][j].r)))};
            //if (pixels[i][j].r > 0)
            //cout << pixels[i][j].r << "." << pixels[i][j].g << "." << pixels[i][j].b << endl;
            fwrite(color,1,3,f);
        }
    }

    fclose(f);
}
