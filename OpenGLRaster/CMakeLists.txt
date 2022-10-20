cmake_minimum_required(VERSION 3.23)
project(OpenGLRaster)

set(CMAKE_CXX_STANDARD 11)

# 添加头文件
set(GLFW_H libs/glfw/3.3.8/include)
set(GLAD_H libs/glad/include)
include_directories(${GLFW_H} ${GLAD_H})

# 添加目标链接
if (APPLE)
    link_libraries("-framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo")
    set(GLFW_LINK ${PROJECT_SOURCE_DIR}/libs/glfw/3.3.8/lib/mac/lib-x86_64/libglfw.3.dylib)
elseif(WIN32)
    set(GLFW_LINK ${PROJECT_SOURCE_DIR}/libs/glfw/3.3.8/lib/win64/glfw3.dll)
    # dll copy
    file(COPY ${GLFW_LINK} DESTINATION ${PROJECT_SOURCE_DIR}/cmake-build-debug)
endif()
link_libraries(${GLFW_LINK})

set(SOURCE_FILES src/main.cpp libs/glad/src/glad.c)
add_executable(OpenGLRaster ${SOURCE_FILES})

# mac下这步很重要
if (APPLE)
    target_link_libraries(OpenGLRaster "-framework OpenGL")
elseif(WIN32)
    target_link_libraries(OpenGLRaster -lopengl32 ${GLFW_LINK})
endif()
