cmake_minimum_required(VERSION 3.23)
project(SoftRaster)

set(CMAKE_CXX_STANDARD 11)

add_executable(SoftRaster main.cpp matrix/vec4.cpp matrix/vec4.h matrix/vec2.cpp matrix/vec2.h matrix/vec3.cpp matrix/vec3.h matrix/mat2.cpp matrix/mat2.h matrix/mat3.cpp matrix/mat3.h matrix/mat4.cpp matrix/mat4.h matrix/matrix.cpp matrix/matrix.h pipeline/camera_target.cpp pipeline/camera_target.h devices/windows_forms.cpp devices/windows_forms.h pipeline/frame_buffer.cpp pipeline/frame_buffer.h)
