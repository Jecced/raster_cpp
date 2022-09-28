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

void Vec2::set(float mx, float my) {
    x = mx;
    y = my;
}

void Vec2::set(Vec2 other) {
    x = other.x;
    y = other.y;
}

void Vec2::scale(float scale) {
    x *= scale;
    y *= scale;
}

bool Vec2::isZero() {
    return x == 0 && y == 0;
}

void Vec2::reverse() {
    x = -x;
    y = -y;
}

void Vec2::normalized() {
    float len = x * x + y * y;
    if (len > 0) {
        len = 1 / sqrt(len);
    }
    x *= len;
    y *= len;
}
