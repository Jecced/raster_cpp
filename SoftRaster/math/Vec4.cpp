//
// Created by root on 2022/9/27.
//

#include "cmath"
#include "Vec4.h"


Vec4::Vec4() {
    x = 0;
    y = 0;
    z = 0;
    w = 0;
}

Vec4::Vec4(float mx, float my, float mz, float mw) {
    x = mx;
    y = my;
    z = mz;
    w = mw;
}

Vec4::~Vec4() {

}

void Vec4::set(float mx, float my, float mz, float mw) {
    x = mx;
    y = my;
    z = mz;
    w = mw;
}

void Vec4::set(const Vec4 &other) {
    x = other.x;
    y = other.y;
    z = other.z;
    w = other.w;
}

void Vec4::scale(float scale) {
    x *= scale;
    y *= scale;
    z *= scale;
    w *= scale;
}

bool Vec4::isZero() const {
    return x == 0 && y == 0 && z == 0 && w == 0;
}

void Vec4::reverse() {
    x = -x;
    y = -y;
    z = -z;
    w = -w;
}

void Vec4::normalized() {
    float len = x * x + y * y + z * z + w * w;
    if (len > 0) {
        len = 1 / std::sqrt(len);
    }
    x *= len;
    y *= len;
    z *= len;
    w *= len;
}

Vec4 Vec4::clone() const {
    Vec4 o = Vec4(this->x, this->y, this->z, this->w);
    return o;
}

Vec4 Vec4::operator+(const Vec4 &o) const {
    Vec4 out;
    out.x = this->x + o.x;
    out.y = this->y + o.y;
    out.z = this->z + o.z;
    out.w = this->w + o.w;
    return out;
}

Vec4 Vec4::operator-(const Vec4 &o) const {
    Vec4 out;
    out.x = this->x - o.x;
    out.y = this->y - o.y;
    out.z = this->z - o.z;
    out.w = this->w - o.w;
    return out;
}

Vec4 Vec4::operator*(const Vec4 &o) const {
    Vec4 out;
    out.x = this->x * o.x;
    out.y = this->y * o.y;
    out.z = this->z * o.z;
    out.w = this->w * o.w;
    return out;
}

Vec4 Vec4::operator/(const Vec4 &o) const {
    Vec4 out;
    out.x = this->x / o.x;
    out.y = this->y / o.y;
    out.z = this->z / o.z;
    out.w = this->w / o.w;
    return out;
}