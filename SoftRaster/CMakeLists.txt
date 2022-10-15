cmake_minimum_required(VERSION 3.23)
project(SoftRaster)

set(CMAKE_CXX_STANDARD 11)

add_executable(SoftRaster src/main.cpp src/matrix/vec4.cpp src/matrix/vec4.h src/matrix/vec2.cpp src/matrix/vec2.h src/matrix/vec3.cpp src/matrix/vec3.h src/matrix/mat2.cpp src/matrix/mat2.h src/matrix/mat3.cpp src/matrix/mat3.h src/matrix/mat4.cpp src/matrix/mat4.h src/matrix/matrix.cpp src/matrix/matrix.h src/engine/buffer/camera_target.cpp src/engine/buffer/camera_target.h src/devices/windows_forms.cpp src/devices/windows_forms.h src/engine/buffer/frame_buffer.cpp src/engine/buffer/frame_buffer.h src/engine/buffer/z_buffer.cpp src/engine/buffer/z_buffer.h src/libs/stb_image.h src/tex/texture.cpp src/tex/texture.h src/engine/comp/camera.cpp src/engine/comp/camera.h src/engine/comp/mesh.cpp src/engine/comp/mesh.h src/engine/pipeline/vertex_ctl.cpp src/engine/pipeline/vertex_ctl.h src/engine/struct/a2v.h src/engine/util/mesh_util.h src/engine/util/barycentric_util.h)
