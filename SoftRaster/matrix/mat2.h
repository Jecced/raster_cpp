//
// Created by Admin on 2022/9/28.
//

#ifndef SOFTRASTER_MAT2_H
#define SOFTRASTER_MAT2_H


class Mat2 {
public:
    Mat2();
    Mat2(float a0, float a1, float b0, float b1);
    ~Mat2();
private:
    float data[4];
public:
    void set(int index, float v);
    void set(float a0, float a1, float b0, float b1);
    float get(int index);
    void transpose();
    Mat2* clone();

    std::string toString();
};


#endif //SOFTRASTER_MAT2_H
