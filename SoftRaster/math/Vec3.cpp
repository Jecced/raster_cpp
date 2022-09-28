//
// Created by Admin on 2022/9/28.
//
#include <cmath>
#include "Vec3.h"

Vec3::Vec3() {
    x = 0;
    y = 0;
    z = 0;
}

Vec3::Vec3(float mx, float my, float mz) {
    x = mx;
    y = my;
    z = mz;
}

Vec3::~Vec3() {

}

void Vec3::set(float mx, float my, float mz) {
    x = mx;
    y = my;
    z = mz;
}

void Vec3::set(const Vec3 &other) {
    x = other.x;
    y = other.y;
    z = other.z;
}

void Vec3::scale(float scale) {
    x *= scale;
    y *= scale;
    z *= scale;
}

bool Vec3::isZero() const {
    return x == 0 && y == 0 && z == 0;
}

void Vec3::reverse() {
    x = -x;
    y = -y;
    z = -z;
}

void Vec3::normalized() {
    float len = x * x + y * y + z * z;
    if (len > 0) {
        len = 1 / std::sqrt(len);
    }
    x *= len;
    y *= len;
    z *= len;
}

Vec3 Vec3::clone() const {
    Vec3 o = Vec3(this->x, this->y, this->z);
    return o;
}

Vec3 Vec3::operator+(const Vec3 &o) const {
    Vec3 out;
    out.x = this->x + o.x;
    out.y = this->y + o.y;
    out.z = this->z + o.z;
    return out;
}

Vec3 Vec3::operator-(const Vec3 &o) const {
    Vec3 out;
    out.x = this->x - o.x;
    out.y = this->y - o.y;
    out.z = this->z - o.z;
    return out;
}

Vec3 Vec3::operator*(const Vec3 &o) const {
    Vec3 out;
    out.x = this->x * o.x;
    out.y = this->y * o.y;
    out.z = this->z * o.z;
    return out;
}

Vec3 Vec3::operator/(const Vec3 &o) const {
    Vec3 out;
    out.x = this->x / o.x;
    out.y = this->y / o.y;
    out.z = this->z / o.z;
    return out;
}


Vec3 Vec3::operator+(float v) const {
    Vec3 out;
    out.x = this->x + v;
    out.y = this->y + v;
    out.z = this->z + v;
    return out;
}

Vec3 Vec3::operator-(float v) const {
    Vec3 out;
    out.x = this->x - v;
    out.y = this->y - v;
    out.z = this->z - v;
    return out;
}

Vec3 Vec3::operator*(float v) const {
    Vec3 out;
    out.x = this->x * v;
    out.y = this->y * v;
    out.z = this->z * v;
    return out;
}

Vec3 Vec3::operator/(float v) const {
    Vec3 out;
    out.x = this->x / v;
    out.y = this->y / v;
    out.z = this->z / v;
    return out;
}