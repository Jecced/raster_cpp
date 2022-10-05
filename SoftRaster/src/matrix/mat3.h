//
// Created by Admin on 2022/9/29.
//

#ifndef SOFTRASTER_MAT3_H
#define SOFTRASTER_MAT3_H

#include <string>
#include "vec3.h"

class Mat3 {
public:
    Mat3();
    Mat3(float a0, float a1, float a2, float b0, float b1, float b2, float c0, float c1, float c2);
    ~Mat3();
private:
    float data[9];
public:
    void set(int index, float v);
    void set(float a0, float a1, float a2, float b0, float b1, float b2, float c0, float c1, float c2);
    float get(int index);
    void transpose();
    Mat3* clone();

    std::string toString();

    Mat3* operator*(const Mat3& v) const;
    Vec3* operator*(const Vec3& v) const;
};


#endif //SOFTRASTER_MAT3_H
