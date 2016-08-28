//
// Created by muzio on 8/22/16.
//

#include "Ray.h"

Ray::Ray(Vector3 origin, Vector3 direction) : direction(direction.normalize()), origin(origin) {
}