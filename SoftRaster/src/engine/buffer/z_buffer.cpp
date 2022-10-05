//
// Created by jecced on 2022/10/3.
//

#include "z_buffer.h"

ZBuffer::ZBuffer(unsigned int size) {
    this->data = new float[size];
    this->size = size;
}

ZBuffer::~ZBuffer() {
    delete data;
}

void ZBuffer::clearBuffer() {
    for (int i = 0; i < this->size; i++) {
        this->data[i] = -1;
    }
}

void ZBuffer::setZ(int index, float z) {
    this->data[index] = z;
}

bool ZBuffer::zTest(int index, float z) {
    if (z > 1 || z < -1) {
        return false;
    }
    return z > this->data[index];
}