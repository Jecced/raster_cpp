//
// Created by Admin on 2022/9/29.
//

#include <string>
#include "mat3.h"
#include "vec3.h"


Mat3::Mat3() {
    this->set(1.0, 0.0, 0.0,
              0.0, 1.0, 0.0,
              0.0, 0.0, 1.0);
}

Mat3::Mat3(float a0, float a1, float a2, float b0, float b1, float b2, float c0, float c1, float c2) {
    this->set(a0, a1, a2, b0, b1, b2, c0, c1, c2);
}

Mat3::~Mat3() {
    delete[] &data;
}

void Mat3::set(int index, float v) {
    data[index] = v;
}

void Mat3::set(float a0, float a1, float a2, float b0, float b1, float b2, float c0, float c1, float c2) {
    data[0] = a0;
    data[1] = a1;
    data[2] = a2;
    data[3] = b0;
    data[4] = b1;
    data[5] = b2;
    data[6] = c0;
    data[7] = c1;
    data[8] = c2;
}

float Mat3::get(int index) {
    return data[index];
}

/**
 * 转置
 * 0 1 2    0 3 6
 * 3 4 5  → 1 4 7
 * 6 7 8    2 5 8
 */
void Mat3::transpose() {
    float a01 = data[1];
    float a02 = data[2];
    float a05 = data[5];

    data[1] = data[3];
    data[3] = a01;
    data[2] = data[6];
    data[6] = a02;
    data[5] = data[7];
    data[7] = a05;
}

Mat3 *Mat3::clone() {
    Mat3 *mat = new Mat3();
    mat->data[0] = this->data[0];
    mat->data[1] = this->data[1];
    mat->data[2] = this->data[2];
    mat->data[3] = this->data[3];
    mat->data[4] = this->data[4];
    mat->data[5] = this->data[5];
    mat->data[6] = this->data[6];
    mat->data[7] = this->data[7];
    mat->data[8] = this->data[8];
    return mat;
}

std::string Mat3::toString() {
    return "mat3(\n  " +
           std::to_string(data[0]) + ", " + std::to_string(data[1]) + std::to_string(data[2]) + "\n  " +
           std::to_string(data[3]) + ", " + std::to_string(data[4]) + std::to_string(data[5]) + "\n  " +
           std::to_string(data[6]) + ", " + std::to_string(data[7]) + std::to_string(data[8]) + "\n  " +
           ")";
}

Mat3 *Mat3::operator*(const Mat3 &a) const {
    Mat3 *out = new Mat3();

    // this -> 行, a -> 列
    out->set(0, this->data[0] * a.data[0] + this->data[1] * a.data[3] + this->data[2] * a.data[6]);
    out->set(1, this->data[0] * a.data[1] + this->data[1] * a.data[4] + this->data[2] * a.data[7]);
    out->set(2, this->data[0] * a.data[2] + this->data[1] * a.data[5] + this->data[2] * a.data[8]);

    out->set(3, this->data[3] * a.data[0] + this->data[4] * a.data[3] + this->data[5] * a.data[6]);
    out->set(4, this->data[3] * a.data[1] + this->data[4] * a.data[4] + this->data[5] * a.data[7]);
    out->set(5, this->data[3] * a.data[2] + this->data[4] * a.data[5] + this->data[5] * a.data[8]);

    out->set(6, this->data[6] * a.data[0] + this->data[7] * a.data[3] + this->data[8] * a.data[6]);
    out->set(7, this->data[6] * a.data[1] + this->data[7] * a.data[4] + this->data[8] * a.data[7]);
    out->set(8, this->data[6] * a.data[2] + this->data[7] * a.data[5] + this->data[8] * a.data[8]);

    return out;
}

Vec3 *Mat3::operator*(const Vec3 &a) const {
    Vec3 *out = new Vec3(
            this->data[0] * a.x + this->data[1] * a.y + this->data[2] * a.z,
            this->data[3] * a.x + this->data[4] * a.y + this->data[5] * a.z,
            this->data[6] * a.x + this->data[7] * a.y + this->data[8] * a.z
    );
    return out;
}