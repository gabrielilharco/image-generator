#ifndef IMAGE_GENERATOR_CAMERA_H
#define IMAGE_GENERATOR_CAMERA_H

#include "Vector3.h"

class Camera {

public:
    Vector3 origin, top_left, top_right, bot_left, bot_right;
    int height, width;

    Camera (int, int);
    Camera (Vector3, Vector3, Vector3, Vector3, Vector3, int, int);


};

#endif //IMAGE_GENERATOR_CAMERA_H
