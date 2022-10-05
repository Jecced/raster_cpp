//
// Created by Admin on 2022/9/29.
//

#ifndef SOFTRASTER_MAT4_H
#define SOFTRASTER_MAT4_H

#include <string>
#include "vec4.h"

class Mat4 {
public:
    Mat4();

    Mat4(float a0, float a1, float a2, float a3,
         float b0, float b1, float b2, float b3,
         float c0, float c1, float c2, float c3,
         float d0, float d1, float d2, float d3
    );

    ~Mat4();

private:
    float data[16];
public:
    void set(int index, float v);

    void set(float a0, float a1, float a2, float a3,
             float b0, float b1, float b2, float b3,
             float c0, float c1, float c2, float c3,
             float d0, float d1, float d2, float d3);

    float get(int index);

    void transpose();

    void identity();

    Mat4* clone() const;

    std::string toString();

    Mat4* operator*(const Mat4& v) const;
    Vec4* operator*(const Vec4& v) const;
};


#endif //SOFTRASTER_MAT4_H
