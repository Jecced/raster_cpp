//
// Created by jecced on 2022/10/1.
//

#ifndef SOFTRASTER_CAMERA_TARGET_H
#define SOFTRASTER_CAMERA_TARGET_H

#include "../matrix/vec4.h"

class CameraTarget {
public:
    int width, height;

    CameraTarget(int width, int height);

    ~CameraTarget();

    void setColor(unsigned int x, unsigned int y, const Vec4 &color);

    void setClearColor(const Vec4 &color);

    unsigned int*& getFrameBuffer();

    void clear();

private:
    unsigned int *frameBuffer;

    unsigned int *clearColor;

    unsigned int toRGB(const Vec4 &color);

    // Color Buffer

    // Z Buffer

};


#endif //SOFTRASTER_CAMERA_TARGET_H
