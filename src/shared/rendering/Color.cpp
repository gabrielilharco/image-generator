#include "shared/rendering/Color.h"

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

Color Color::operator/(double d) {
    return Color(r/d, g/d, b/d);
}

double max(double a, double b, double c) {
    if(a >= b && a >= c) return a;
    if(b >= a && b >= c) return b;
    return c;
}

double min(double a, double b, double c) {
    if(a <= b && a <= c) return a;
    if(b <= a && b <= c) return b;
    return c;
}

HSL Color::toHSL() {
    double red = r/255.0, green = g/255.0, blue = b/255.0;
    double M = max(red, green, blue), m = min(red, green, blue);
    double h, s, l = (M + m) / 2;

    if(M == m) {
        h = s = 0; // achromatic
    }
    else {
        double d = M - m;
        s = l > 0.5 ? d / (2 - M - m) : d / (M + m);
        if(M == red) { h = (green - blue) / d + (green < blue ? 6 : 0); }
        else if (M == green) { h = (blue - red) / d + 2; }
        else if (M == blue) { h = (red - green) / d + 4; }
        h /= 6;
    }

    return HSL(h, s, l);
}