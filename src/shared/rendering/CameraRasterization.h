//
// Created by matheus on 8/28/16.
//

#ifndef IMAGE_GENERATOR_CAMERARASTERIZATION_H
#define IMAGE_GENERATOR_CAMERARASTERIZATION_H

#include "shared/math/Matrix44.h"

class CameraRasterization {
 public:
    CameraRasterization(const Matrix44 &transform, const double distanceToViewport,
        const double width, const double height);

    const Matrix44 &transform;
    const double distanceToViewport;
    const double width;
    const double height;
};


#endif //IMAGE_GENERATOR_CAMERARASTERIZATION_H
