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


Vec2 *vec2(float x);
Vec2 *vec2(float x, float y);
Vec2 *vec2(const Vec2 &a);
Vec3 *vec3(float x);
Vec3 *vec3(float x, float y, float z);
Vec3 *vec3(const Vec3 &a);
Vec3 *vec3(const Vec2 &a, float x);
Vec3 *vec3(float x, const Vec2 &a);
Vec4 *vec4(float x);
Vec4 *vec4(float x, float y, float z, float w);
Vec4 *vec4(const Vec3& a, float w);
Vec4 *vec4(const Vec2& a, float z, float w);


Mat2 *mat2(float a0, float a1, float b0, float b1);

Mat3 *mat3(float a0, float a1, float a2,
           float b0, float b1, float b2,
           float c0, float c1, float c2);

Mat4 *mat4(float a0, float a1, float a2, float a3,
           float b0, float b1, float b2, float b3,
           float c0, float c1, float c2, float c3,
           float d0, float d1, float d2, float d3);

Mat2 *mat2(const Vec2 &a, const Vec2 &b);

Mat3 *mat3(const Vec3 &a, const Vec3 &b, const Vec3 &c);

Mat4 *mat4(const Vec4 &a, const Vec4 &b, const Vec4 &c, const Vec4 &d);

#endif //SOFTRASTER_MATRIX_H
