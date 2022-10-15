//
// Created by jecced on 2022/10/3.
//

#include "frame_buffer.h"

FrameBuffer::FrameBuffer(unsigned int *buffer, unsigned int bufferSize) {
    this->framebuffer = buffer;
    this->bufferSize = bufferSize;
}

void FrameBuffer::clearBuffer() {
    for (int i = 0; i < bufferSize; i++) {
        framebuffer[i] = clearColor;
    }
}

void FrameBuffer::setClearColor(unsigned int color) {
    this->clearColor = color;
}

unsigned int *FrameBuffer::getFrameBuffer() {
    return this->framebuffer;
}

void FrameBuffer::setColor(int index, unsigned int color) {
    framebuffer[index] = color;
}