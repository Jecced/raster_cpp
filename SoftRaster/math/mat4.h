//
// Created by Admin on 2022/9/29.
//

#ifndef SOFTRASTER_MAT4_H
#define SOFTRASTER_MAT4_H


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

    Mat4 clone();

    std::string toString();
};


#endif //SOFTRASTER_MAT4_H
