//
// Created by matheus on 8/28/16.
//

#ifndef IMAGE_GENERATOR_CAMERARASTERIZATION_H
#define IMAGE_GENERATOR_CAMERARASTERIZATION_H

#include "shared/math/Vector3.h"
#include "shared/math/Matrix44.h"

class Camera {
 public:
    Camera(const Matrix44 transform, const double distanceToViewport,
        const double width, const double height);

    const Matrix44 camToWorldTransform;
    const Matrix44 worldToCamTransform;
    const double distanceToViewport;
    const double width;
    const double height;
    const Vector3 calculateOrigin() const;
    const Vector3 calculateTopLeft() const;
    const Vector3 calculateTopRight() const;
    const Vector3 calculateBottomLeft() const;
    const Vector3 calculateBottomRight() const;
};


#endif //IMAGE_GENERATOR_CAMERARASTERIZATION_H
