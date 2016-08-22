#include "Color.h"

#define min(a,b) (a < b ? a : b)
#define max(a,b) (a > b ? a : b)

using namespace std;

Color::Color () {
    r = 122;
    g = 122;
    b = 122;
    a = 1;
}

Color::Color (int red, int green, int blue, double alpha) {
    r = (unsigned  char)max(0,min(red, 255));
    g = (unsigned  char)max(0,min(green, 255));
    b = (unsigned  char)max(0,min(blue, 255));
    a = max(0,min(alpha,1));
}

Color::Color (unsigned char red, unsigned char green, unsigned char blue, double alpha) {
    r = red;
    g = green;
    b = blue;
    a = max(0,min(alpha,1));
}