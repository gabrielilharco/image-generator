set(SOURCE_DIR ".")

# Recursively add files
file(GLOB_RECURSE SRCS *.cpp)
file(GLOB_RECURSE HDRS *.h)

add_library(image_gen_lib ${SRCS} ${HDRS} shared/Image.cpp shared/Camera.cpp shared/Camera.h shared/Light.h shared/PointLight.cpp shared/PointLight.h shared/DirectionalLight.cpp shared/DirectionalLight.h)


add_executable(image_gen main.cpp)

#libs
target_link_libraries(image_gen image_gen_lib)
target_include_directories(image_gen_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})