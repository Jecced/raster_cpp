//
// Created by Admin on 2022/9/29.
//

#include <string>
#include "mat4.h"

Mat4::Mat4() {
    this->identity();
}

Mat4::Mat4(float a0, float a1, float a2, float a3,
           float b0, float b1, float b2, float b3,
           float c0, float c1, float c2, float c3,
           float d0, float d1, float d2, float d3) {
    this->set(a0, a1, a2, a3,
              b0, b1, b2, b3,
              c0, c1, c2, c3,
              d0, d1, d2, d3
    );
}

Mat4::~Mat4() {
    delete[] &data;
}

void Mat4::set(int index, float v) {
    data[index] = v;
}

void Mat4::set(float a0, float a1, float a2, float a3,
               float b0, float b1, float b2, float b3,
               float c0, float c1, float c2, float c3,
               float d0, float d1, float d2, float d3) {
    data[0] = a0;
    data[1] = a1;
    data[2] = a2;
    data[3] = a3;
    data[4] = b0;
    data[5] = b1;
    data[6] = b2;
    data[7] = b3;
    data[8] = c0;
    data[9] = c1;
    data[10] = c2;
    data[11] = c3;
    data[12] = d0;
    data[13] = d1;
    data[14] = d2;
    data[15] = d3;
}

void Mat4::set(const Mat4 &mat4) {
    data[0] = mat4.data[0];
    data[1] = mat4.data[1];
    data[2] = mat4.data[2];
    data[3] = mat4.data[3];
    data[4] = mat4.data[4];
    data[5] = mat4.data[5];
    data[6] = mat4.data[6];
    data[7] = mat4.data[7];
    data[8] = mat4.data[8];
    data[9] = mat4.data[9];
    data[10] = mat4.data[10];
    data[11] = mat4.data[11];
    data[12] = mat4.data[12];
    data[13] = mat4.data[13];
    data[14] = mat4.data[14];
    data[15] = mat4.data[15];
}

float Mat4::get(int index) {
    return data[index];
}

/**
 * 转置
 * a b c d      a e i m
 * e f g h  →   b f j n
 * i j k l  →   c g k o
 * m n o p      d h l p
 */
void Mat4::transpose() {
    float a01 = data[1];
    float a02 = data[2];
    float a03 = data[3];
    float a12 = data[6];
    float a13 = data[7];
    float a23 = data[11];

    data[1] = data[4];
    data[2] = data[8];
    data[3] = data[12];
    data[4] = a01;
    data[6] = data[9];
    data[7] = data[13];
    data[8] = a02;
    data[9] = a12;
    data[11] = data[14];
    data[12] = a03;
    data[13] = a13;
    data[14] = a23;
}

Mat4* Mat4::clone() const {
    Mat4* mat = new Mat4();
    mat->data[0] = this->data[0];
    mat->data[1] = this->data[1];
    mat->data[2] = this->data[2];
    mat->data[3] = this->data[3];
    mat->data[4] = this->data[4];
    mat->data[5] = this->data[5];
    mat->data[6] = this->data[6];
    mat->data[7] = this->data[7];
    mat->data[8] = this->data[8];
    mat->data[9] = this->data[9];
    mat->data[10] = this->data[10];
    mat->data[11] = this->data[11];
    mat->data[12] = this->data[12];
    mat->data[13] = this->data[13];
    mat->data[14] = this->data[14];
    mat->data[15] = this->data[15];
    return mat;
}

std::string Mat4::toString() {
    return "mat4(\n  " +
           std::to_string(data[0]) + ", " + std::to_string(data[1]) + std::to_string(data[2]) +
           std::to_string(data[3]) + "\n  " +
           std::to_string(data[4]) + ", " + std::to_string(data[5]) + std::to_string(data[6]) +
           std::to_string(data[7]) + "\n  " +
           std::to_string(data[8]) + ", " + std::to_string(data[9]) + std::to_string(data[10]) +
           std::to_string(data[11]) + "\n  " +
           std::to_string(data[12]) + ", " + std::to_string(data[13]) + std::to_string(data[14]) +
           std::to_string(data[15]) + "\n  " +
           ")";
}

Mat4 *Mat4::operator*(const Mat4 &a) const {
    Mat4 *out = new Mat4();

    // this -> 行, a -> 列
    out->set(0, this->data[0] * a.data[0] + this->data[1] * a.data[4] + this->data[2] * a.data[8] + this->data[3] * a.data[12]);
    out->set(1, this->data[0] * a.data[1] + this->data[1] * a.data[5] + this->data[2] * a.data[9] + this->data[3] * a.data[13]);
    out->set(2, this->data[0] * a.data[2] + this->data[1] * a.data[6] + this->data[2] * a.data[10] + this->data[3] * a.data[14]);
    out->set(3, this->data[0] * a.data[3] + this->data[1] * a.data[7] + this->data[2] * a.data[11] + this->data[3] * a.data[15]);

    out->set(4, this->data[4] * a.data[0] + this->data[5] * a.data[4] + this->data[6] * a.data[8] + this->data[7] * a.data[12]);
    out->set(5, this->data[4] * a.data[1] + this->data[5] * a.data[5] + this->data[6] * a.data[9] + this->data[7] * a.data[13]);
    out->set(6, this->data[4] * a.data[2] + this->data[5] * a.data[6] + this->data[6] * a.data[10] + this->data[7] * a.data[14]);
    out->set(7, this->data[4] * a.data[3] + this->data[5] * a.data[7] + this->data[6] * a.data[11] + this->data[7] * a.data[15]);

    out->set(8, this->data[8] * a.data[0] + this->data[9] * a.data[4] + this->data[10] * a.data[8] + this->data[11] * a.data[12]);
    out->set(9, this->data[8] * a.data[1] + this->data[9] * a.data[5] + this->data[10] * a.data[9] + this->data[11] * a.data[13]);
    out->set(10, this->data[8] * a.data[2] + this->data[9] * a.data[6] + this->data[10] * a.data[10] + this->data[11] * a.data[14]);
    out->set(11, this->data[8] * a.data[3] + this->data[9] * a.data[7] + this->data[10] * a.data[11] + this->data[11] * a.data[15]);

    out->set(12, this->data[12] * a.data[0] + this->data[13] * a.data[4] + this->data[14] * a.data[8] + this->data[15] * a.data[12]);
    out->set(13, this->data[12] * a.data[1] + this->data[13] * a.data[5] + this->data[14] * a.data[9] + this->data[15] * a.data[13]);
    out->set(14, this->data[12] * a.data[2] + this->data[13] * a.data[6] + this->data[14] * a.data[10] + this->data[15] * a.data[14]);
    out->set(15, this->data[12] * a.data[3] + this->data[13] * a.data[7] + this->data[14] * a.data[11] + this->data[15] * a.data[15]);

    return out;
}

Vec4 *Mat4::operator*(const Vec4 &a) const {
    Vec4 *out = new Vec4(
            this->data[0] * a.x + this->data[1] * a.y + this->data[2] * a.z + this->data[3] * a.w,
            this->data[4] * a.x + this->data[5] * a.y + this->data[6] * a.z + this->data[7] * a.w,
            this->data[8] * a.x + this->data[9] * a.y + this->data[10] * a.z + this->data[11] * a.w,
            this->data[12] * a.x + this->data[13] * a.y + this->data[14] * a.z + this->data[15] * a.w
    );
    return out;
}

void Mat4::identity() {
    this->set(1.0, 0.0, 0.0, 0.0,
              0.0, 1.0, 0.0, 0.0,
              0.0, 0.0, 1.0, 0.0,
              0.0, 0.0, 0.0, 1.0
    );
}