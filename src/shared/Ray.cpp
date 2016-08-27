//
// Created by muzio on 8/22/16.
//

#include "Ray.h"

Ray::Ray(Vector3 direction, Vector3 origin) : direction(direction.normalize()), origin(origin) {
}