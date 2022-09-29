//
// Created by Admin on 2022/9/29.
//

#ifndef SOFTRASTER_MATRIX_H
#define SOFTRASTER_MATRIX_H

#include <string>
#include "matrix.h"
#include "mat2.h"
#include "mat3.h"
#include "mat4.h"
#include "vec2.h"
#include "vec3.h"
#include "vec4.h"


float cross(float x1, float y1, float x2, float y2);
float cross(const Vec2 &a, const Vec2 &b);
Vec3 * cross(const Vec3 &a, const Vec3 &b);

Vec2* normalize(const Vec2& v);
Vec3* normalize(const Vec3& v);
Vec4* normalize(const Vec4& v);

float dot(const Vec2& a, const Vec2& b);
float dot(const Vec3& a, const Vec3& b);
float dot(const Vec4& a, const Vec4& b);



#endif //SOFTRASTER_MATRIX_H
