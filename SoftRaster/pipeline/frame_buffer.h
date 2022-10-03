//
// Created by jecced on 2022/10/3.
//

#ifndef SOFTRASTER_FRAME_BUFFER_H
#define SOFTRASTER_FRAME_BUFFER_H


class FrameBuffer {
private:
    unsigned int **framebuffer;
    unsigned int bufferSize;
    unsigned int clearColor;
public:
    FrameBuffer(unsigned int **buffer, unsigned int bufferSize);

    void clearBuffer();

    void setClearColor(unsigned int color);

    unsigned int **getFrameBuffer();

    void setColor(int index, unsigned int color);
};


#endif //SOFTRASTER_FRAME_BUFFER_H
