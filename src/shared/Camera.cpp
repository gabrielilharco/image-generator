#include "Camera.h"

Camera::Camera (int w, int h) {
    height = h;
    width = w;
    origin    = Vector3(  0,  0,-10);
    top_left  = Vector3(-10, 10, 0);
    top_right = Vector3( 10, 10, 0);
    bot_left  = Vector3(-10,-10, 0);
    bot_right = Vector3( 10,-10, 0);
}

Camera::Camera (Vector3 o, Vector3 tl, Vector3 tr, Vector3 bl, Vector3 br, int w, int h) {
    height = h;
    width = w;
    origin = o;
    top_left  = tl;
    top_right = tr;
    bot_left  = bl;
    bot_right = br;
}