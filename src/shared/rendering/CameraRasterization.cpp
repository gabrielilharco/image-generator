//
// Created by matheus on 8/28/16.
//

#include "CameraRasterization.h"
CameraRasterization::CameraRasterization(const Matrix44 transform,
                                         const double distanceToViewport,
                                         const double width,
                                         const double height)
    : transform(transform), distanceToViewport(distanceToViewport),
      width(width), height(height) {}
