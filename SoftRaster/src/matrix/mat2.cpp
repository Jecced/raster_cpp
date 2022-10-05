//
// Created by Admin on 2022/9/28.
//
#include <string>
#include "mat2.h"

Mat2::Mat2() {
    this->set(1.0, 0.0,
              0.0, 1.0);
}

Mat2::Mat2(float a0, float a1, float b0, float b1) {
    this->set(a0, a1, b0, b1);
}

Mat2::~Mat2() {
    delete[] &data;
}

void Mat2::set(int index, float v) {
    data[index] = v;
}

void Mat2::set(float a0, float a1, float b0, float b1) {
    data[0] = a0;
    data[1] = a1;
    data[2] = b0;
    data[3] = b1;
}

float Mat2::get(int index) {
    return data[index];
}

void Mat2::transpose() {
    float temp = data[1];
    data[1] = data[2];
    data[2] = temp;
}

Mat2* Mat2::clone() const {
    Mat2* mat = new Mat2();
    mat->data[0] = this->data[0];
    mat->data[1] = this->data[1];
    mat->data[2] = this->data[2];
    mat->data[3] = this->data[3];
    return mat;
}

std::string Mat2::toString() {
    return "mat2(\n  " + std::to_string(data[0]) + ", " + std::to_string(data[1]) + "\n  " + std::to_string(data[2]) +
           ", " + std::to_string(data[3]) + ")";
}

Mat2* Mat2::operator*(const Mat2 &a) const {
    Mat2 *out = new Mat2();

    // this -> 行, a -> 列
    out->set(0, this->data[0] * a.data[0] + this->data[1] * a.data[2]);
    out->set(1, this->data[0] * a.data[1] + this->data[1] * a.data[3]);

    out->set(2, this->data[2] * a.data[0] + this->data[3] * a.data[2]);
    out->set(3, this->data[2] * a.data[1] + this->data[3] * a.data[3]);

    return out;
}

Vec2* Mat2::operator*(const Vec2 &a) const {
    Vec2 *out = new Vec2(
            this->data[0] * a.x + this->data[1] * a.y,
            this->data[2] * a.x + this->data[3] * a.y
    );
    return out;
}