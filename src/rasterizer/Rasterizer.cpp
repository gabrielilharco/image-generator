//
// Created by matheus on 8/28/16.
//

#include "rasterizer/Rasterizer.h"

Rasterizer::Rasterizer(const WorldScene &scene, const unsigned int imageWidth, const unsigned int imageHeight)
    : scene(scene), imageWidth(imageWidth), imageHeight(imageHeight) {
    renderedImage = new Image(imageWidth, imageHeight);
    // Include other initializations
}

const Image &Rasterizer::renderImage() {
    return *renderedImage;
}
