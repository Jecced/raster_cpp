//
// Created by jecced on 2022/10/1.
//

#include "camera_target.h"

CameraTarget::CameraTarget(int width, int height) {
    this->width = width;
    this->height = height;
    *clearColor = toRGB(*new Vec4(0, 0, 0, 1));
}

CameraTarget::~CameraTarget() {
    if (frameBuffer) {
        delete frameBuffer;
    }
}

void CameraTarget::setColor(unsigned int x, unsigned int y, const Vec4 &color) {
    frameBuffer[width * y + x] = toRGB(color);
}

void CameraTarget::setClearColor(const Vec4 &color) {
    *clearColor = toRGB(color);
}

inline unsigned int CameraTarget::toRGB(const Vec4 &color) {
    unsigned short int r = 255 * color.x;
    unsigned short int g = 255 * color.y;
    unsigned short int b = 255 * color.z;
    return (unsigned int) ((b & 0xff) | (g & 0xff << 8) | (r & 0xff << 16));
}

void CameraTarget::clear() {
    for (int i = 0, len = width * height; i < len; i++) {
        frameBuffer[i] = *clearColor;
    }
}

unsigned int *&CameraTarget::getFrameBuffer() {
    for(int i = 0, len = width * height; i <len ; i++){
        frameBuffer[i] = toRGB(*new Vec4(1, 0, 0, 1));
    }
    return frameBuffer;
}