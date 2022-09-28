cmake_minimum_required(VERSION 3.23)
project(SoftRaster)

set(CMAKE_CXX_STANDARD 11)

add_executable(SoftRaster main.cpp FrameWindow.cpp FrameWindow.h math/Vec4.cpp math/Vec4.h math/Vec2.cpp math/Vec2.h math/Vec3.cpp math/Vec3.h)
