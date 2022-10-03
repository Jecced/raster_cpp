//
// Created by jecced on 2022/10/1.
//

#include "camera_target.h"
#include "frame_buffer.h"

CameraTarget::CameraTarget(int width, int height, unsigned int **buffer) {
    this->width = width;
    this->height = height;
    unsigned int clearColor = toRGB(*new Vec4(0, 0, 0, 1));
    this->frameBuffer = new FrameBuffer(buffer, (unsigned int)(width * height));
    this->frameBuffer->setClearColor(clearColor);
    this->frameBuffer->clearBuffer();
}

CameraTarget::~CameraTarget() {
}

void CameraTarget::setColor(unsigned int x, unsigned int y, const Vec4 &color) {
    frameBuffer->setColor(index(x, y), toRGB(color));
}

void CameraTarget::setClearColor(const Vec4 &color) {
    frameBuffer->setClearColor(toRGB(color));
}

void CameraTarget::clear() {
    frameBuffer->clearBuffer();
}

inline int CameraTarget::index(int x, int y) const {
    return width * y + x;
}

inline unsigned int CameraTarget::index(unsigned int x, unsigned int y) const {
    return width * y + x;
}

inline unsigned int CameraTarget::toRGB(const Vec4 &color) {
    unsigned short int r = (unsigned short int)(255.0f * color.x);
    unsigned short int g = (unsigned short int)(255.0f * color.y);
    unsigned short int b = (unsigned short int)(255.0f * color.z);
    return (unsigned int) ((b & 0xff) | ((g & 0xff) << 8) | ((r & 0xff) << 16));
}


