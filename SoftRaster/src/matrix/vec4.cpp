//
// Created by root on 2022/9/27.
//

#include <string>
#include "cmath"
#include "vec4.h"


Vec4::Vec4() {
    x = 0;
    y = 0;
    z = 0;
    w = 0;
}

Vec4::Vec4(float x, float y, float z, float w) {
    this->set(x, y, z, w);
}

Vec4::~Vec4() {

}

void Vec4::set(float x, float y, float z, float w) {
    this->x = x;
    this->y = y;
    this->z = z;
    this->w = w;
}

void Vec4::set(const Vec4 &other) {
    this->x = other.x;
    this->y = other.y;
    this->z = other.z;
    this->w = other.w;
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

Vec4* Vec4::clone() const {
    Vec4* o = new Vec4(this->x, this->y, this->z, this->w);
    return o;
}

Vec4* Vec4::operator+(const Vec4 &o) const {
    Vec4* out = new Vec4();
    out->x = this->x + o.x;
    out->y = this->y + o.y;
    out->z = this->z + o.z;
    out->w = this->w + o.w;
    return out;
}

Vec4* Vec4::operator-(const Vec4 &o) const {
    Vec4* out = new Vec4();
    out->x = this->x - o.x;
    out->y = this->y - o.y;
    out->z = this->z - o.z;
    out->w = this->w - o.w;
    return out;
}

Vec4* Vec4::operator*(const Vec4 &o) const {
    Vec4* out = new Vec4();
    out->x = this->x * o.x;
    out->y = this->y * o.y;
    out->z = this->z * o.z;
    out->w = this->w * o.w;
    return out;
}

Vec4* Vec4::operator/(const Vec4 &o) const {
    Vec4* out = new Vec4();
    out->x = this->x / o.x;
    out->y = this->y / o.y;
    out->z = this->z / o.z;
    out->w = this->w / o.w;
    return out;
}

Vec4* Vec4::operator+(float v) const {
    Vec4* out = new Vec4();
    out->x = this->x + v;
    out->y = this->y + v;
    out->z = this->z + v;
    out->w = this->w + v;
    return out;
}

Vec4* Vec4::operator-(float v) const {
    Vec4* out = new Vec4();
    out->x = this->x - v;
    out->y = this->y - v;
    out->z = this->z - v;
    out->w = this->w - v;
    return out;
}

Vec4* Vec4::operator*(float v) const {
    Vec4* out = new Vec4();
    out->x = this->x * v;
    out->y = this->y * v;
    out->z = this->z * v;
    out->w = this->w * v;
    return out;
}

Vec4* Vec4::operator/(float v) const {
    Vec4* out = new Vec4();
    out->x = this->x / v;
    out->y = this->y / v;
    out->z = this->z / v;
    out->w = this->w / v;
    return out;
}

std::string Vec4::toString() const {
    return "vec4(" + std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z) + ", " +
           std::to_string(w) + ")";
}