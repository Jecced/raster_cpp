//
// Created by jecced on 2022/10/3.
//

#ifndef SOFTRASTER_Z_BUFFER_H
#define SOFTRASTER_Z_BUFFER_H


class ZBuffer {
private:
    float *data;
    unsigned int size;
public:
    ZBuffer(unsigned int size);

    ~ZBuffer();

    void clearBuffer();

    void setZ(int index, float z);

    bool zTest(int index, float z);
};


#endif //SOFTRASTER_Z_BUFFER_H
