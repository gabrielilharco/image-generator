set(SOURCE_DIR ".")

# Recursively add files
file(GLOB_RECURSE SRCS *.cpp)
file(GLOB_RECURSE HDRS *.h)

add_library(image_gen_lib ${SRCS} ${HDRS})

add_executable(image_gen main.cpp)

#libs
target_link_libraries(image_gen image_gen_lib)
target_include_directories(image_gen_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})