cmake_minimum_required(VERSION 3.6)
project(RayTracer)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        src/shared/Color.h
        src/shared/Image.h
        src/main.cpp
    README.md src/shared/Vector3.h src/shared/Object.h src/shared/Sphere.h src/shared/Plane.h src/shared/Triange.h)

add_executable(RayTracer ${SOURCE_FILES})