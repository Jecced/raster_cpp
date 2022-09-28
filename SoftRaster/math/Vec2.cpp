//
// Created by Admin on 2022/9/28.
//

#include <cmath>
#include "Vec2.h"

Vec2::Vec2() {
    x = 0;
    y = 0;
}

Vec2::Vec2(float mx, float my) {
    x = mx;
    y = my;
}

Vec2::~Vec2() {

}

void Vec2::set(float mx, float my) {
    x = mx;
    y = my;
}

void Vec2::set(const Vec2 &other) {
    x = other.x;
    y = other.y;
}

void Vec2::scale(float scale) {
    x *= scale;
    y *= scale;
}

bool Vec2::isZero() const {
    return x == 0 && y == 0;
}

void Vec2::reverse() {
    x = -x;
    y = -y;
}

void Vec2::normalized() {
    float len = x * x + y * y;
    if (len > 0) {
        len = 1 / std::sqrt(len);
    }
    x *= len;
    y *= len;
}

Vec2 Vec2::clone() const {
    Vec2 o = Vec2(this->x, this->y);
    return o;
}

Vec2 Vec2::operator+(const Vec2 &o) const {
    Vec2 out;
    out.x = this->x + o.x;
    out.y = this->y + o.y;
    return out;
}

Vec2 Vec2::operator-(const Vec2 &o) const {
    Vec2 out;
    out.x = this->x - o.x;
    out.y = this->y - o.y;
    return out;
}

Vec2 Vec2::operator*(const Vec2 &o) const {
    Vec2 out;
    out.x = this->x * o.x;
    out.y = this->y * o.y;
    return out;
}

Vec2 Vec2::operator/(const Vec2 &o) const {
    Vec2 out;
    out.x = this->x / o.x;
    out.y = this->y / o.y;
    return out;
}


Vec2 Vec2::operator+(float v) const {
    Vec2 out;
    out.x = this->x + v;
    out.y = this->y + v;
    return out;
}

Vec2 Vec2::operator-(float v) const {
    Vec2 out;
    out.x = this->x - v;
    out.y = this->y - v;
    return out;
}

Vec2 Vec2::operator*(float v) const {
    Vec2 out;
    out.x = this->x * v;
    out.y = this->y * v;
    return out;
}

Vec2 Vec2::operator/(float v) const {
    Vec2 out;
    out.x = this->x / v;
    out.y = this->y / v;
    return out;
}