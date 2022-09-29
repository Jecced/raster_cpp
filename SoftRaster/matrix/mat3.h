//
// Created by Admin on 2022/9/29.
//

#ifndef SOFTRASTER_MAT3_H
#define SOFTRASTER_MAT3_H


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
};


#endif //SOFTRASTER_MAT3_H
