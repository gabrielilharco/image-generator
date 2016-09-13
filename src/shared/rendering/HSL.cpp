//
// Created by leao on 12/09/16.
//
#include <cstdio>
#include "HSL.h"
#include "Color.h"
HSL::HSL () {
    h = 0; s = 0; l = 0;
}

HSL::HSL (double hue, double saturation, double luminance) {
    h = hue;
    s = saturation;
    l = luminance;
}

double hueToRGB(double p, double q, double t) {
    if(t < 0) t += 1;
    if(t > 1) t -= 1;
    if(t < 1.0/6.0) return p + (q - p) * 6 * t;
    if(t < 1.0/2.0) return q;
    if(t < 2.0/3.0) return p + (q - p) * (2/3 - t) * 6;
    return p;
}

Color HSL::toRGB () {
    double r, g, b;

    if(s == 0) { r = 1; g = 1; b = 1; }
    else {

        double q = l < 0.5 ? l * (1 + s) : l + s - l * s;
        double p = 2.0 * l - q;
        r = hueToRGB(p, q, h + 1.0/3.0);
        g = hueToRGB(p, q, h);
        b = hueToRGB(p, q, h - 1.0/3.0);
    }

    return Color(r*255, g*255, b*255);
}

void HSL::setLuminance (double luminance) {
    l = luminance;
}