//
// Created by muzio on 8/22/16.
//

#include "shared/geometry/Ray.h"

Ray::Ray(Vector3 origin, Vector3 direction) : direction(direction.normalize()), origin(origin) {
}