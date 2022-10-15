//
// Created by root on 2022/10/15.
//

#ifndef SOFTRASTER_MATH_UTIL_H
#define SOFTRASTER_MATH_UTIL_H


#include <cmath>
#include "../../matrix/vec4.h"

class MathUtil {
public:
    static void bound(int width, int height, Vec4 &p0, Vec4 &p1, Vec4 &p2, Vec4 &out) {
        out.x = min3(p0.x, p1.x, p2.x);
        if (out.x < 0) {
            out.x = 0;
        }

        out.y = min3(p0.y, p1.y, p2.y);
        if (out.y < 0) {
            out.y = 0;
        }

        out.z = max3(p0.x, p1.x, p2.x);
        if (out.z > width) {
            out.z = width;
        }

        out.w = max3(p0.y, p1.y, p2.y);
        if (out.w > height) {
            out.w = height;
        }
        out.x = std::round(out.x);
        out.y = std::round(out.y);
        out.z = std::round(out.z);
        out.w = std::round(out.w);
    }

    static float min3(float a, float b, float c) {
        return std::min(std::min(a, b), c);
    }

    static float max3(float a, float b, float c) {
        return std::max(std::max(a, b), c);
    }
};


#endif //SOFTRASTER_MATH_UTIL_H
