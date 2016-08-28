#include "shared/rendering/Color.h"

#define min(a,b) (a < b ? a : b)
#define max(a,b) (a > b ? a : b)

Color::Color () {
    r = 0;
    g = 0;
    b = 0;
}

Color::Color(double red, double green, double blue) {
    r = red;
    g = green;
    b = blue;
}

Color Color::operator*(double x) {
    return Color(r * x, g * x, b * x);
}

Color Color::operator*(Color c) {
    return Color(r*c.r,g*c.g,b*c.b);
}

Color Color::operator+(Color c) {
    return Color(r+c.r, g+c.g, b+c.b);
}

