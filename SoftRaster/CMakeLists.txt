cmake_minimum_required(VERSION 3.23)
project(SoftRaster)

set(CMAKE_CXX_STANDARD 11)

add_executable(SoftRaster main.cpp FrameWindow.cpp FrameWindow.h math/vec4.cpp math/vec4.h math/vec2.cpp math/vec2.h math/vec3.cpp math/vec3.h)
