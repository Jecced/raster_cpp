//
// Created by root on 2022/9/27.
//

#ifndef SOFTRASTER_VEC4_H
#define SOFTRASTER_VEC4_H


class Vec4 {
public:
    Vec4(float x, float y, float z, float w);
public:
    float x;
    float y;
    float z;
    float w;

    float r;
    float g;
    float b;
    float a;

    void set(float x, float y, float z, float w);

    void fromVec4(Vec4 other);

    
};


#endif //SOFTRASTER_VEC4_H
