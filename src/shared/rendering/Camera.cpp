//
// Created by matheus on 8/28/16.
//

#include "Camera.h"
Camera::Camera(const Matrix44 transform,
                                         const double distanceToViewport,
                                         const double width,
                                         const double height)
    : camToWorldTransform(transform),
      worldToCamTransform(Matrix44::inverse(transform)),
      distanceToViewport(distanceToViewport),
      width(width), height(height) {}

const Vector3 Camera::calculateOrigin() const {
    return Vector3(0, 0, 0) * camToWorldTransform;
}

const Vector3 Camera::calculateTopLeft() const {
    return Vector3(-width * 1.0 / 2, height * 1.0 / 2, -distanceToViewport) *
        camToWorldTransform;
}

const Vector3 Camera::calculateTopRight() const {
    return Vector3(width * 1.0 / 2, height * 1.0 / 2, -distanceToViewport) *
        camToWorldTransform;
}

const Vector3 Camera::calculateBottomLeft() const {
    return Vector3(-width * 1.0 / 2, -height * 1.0 / 2, -distanceToViewport) *
        camToWorldTransform;
}

const Vector3 Camera::calculateBottomRight() const {
    return Vector3(width * 1.0 / 2, -height * 1.0 / 2, -distanceToViewport) *
        camToWorldTransform;
}
