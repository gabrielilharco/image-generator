//
// Created by leao on 29/08/16.
//

#ifndef IMAGE_GENERATOR_BOUNDINGBOX_H
#define IMAGE_GENERATOR_BOUNDINGBOX_H

#include <shared/math/Vector2.h>
#include "TriangleProjection.h"

class BoundingBox {
private:
public:
    BoundingBox(const TriangleProjection&);
    const Vector2 tl, bl, br, tr;

};
#endif //IMAGE_GENERATOR_BOUNDINGBOX_H
