//
// Created by leao on 12/09/16.
//

#ifndef IMAGE_GENERATOR_HSV_H
#define IMAGE_GENERATOR_HSV_H

class Color;

class HSL {
public:
    double h, s, l;

    HSL ();
    HSL (double, double, double);

    Color toRGB ();
    void setLuminance (double);

};
#endif //IMAGE_GENERATOR_HSV_H
