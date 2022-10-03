//
// Created by jecced on 2022/10/1.
//

#ifndef SOFTRASTER_CAMERA_TARGET_H
#define SOFTRASTER_CAMERA_TARGET_H

#include "../matrix/vec4.h"
#include "frame_buffer.h"

class CameraTarget {
public:
    int width, height;

    CameraTarget(int width, int height, unsigned int **framebuffer);

    ~CameraTarget();

    void setColor(unsigned int x, unsigned int y, const Vec4 &color);

    void setClearColor(const Vec4 &color);

    void clear();

private:
    static unsigned int toRGB(const Vec4 &color);

    int index(int x, int y) const;

    unsigned index(unsigned int x, unsigned int y) const;

    // Color Buffer
    FrameBuffer* frameBuffer;

    // Z Buffer

};


#endif //SOFTRASTER_CAMERA_TARGET_H
