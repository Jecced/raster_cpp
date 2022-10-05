//
// Created by Admin on 2022/9/29.
//

#include <cmath>
#include "matrix.h"
#include "vec2.h"
#include "vec3.h"
#include "vec4.h"

float cross(float x1, float y1, float x2, float y2) {
    return x1 * y2 - x2 * y1;
}

float cross(const Vec2 &a, const Vec2 &b) {
    return a.x * b.y - b.x * a.y;
}

Vec3 *cross(const Vec3 &a, const Vec3 &b) {
    Vec3 *o = new Vec3(
            a.y * b.z - a.z * b.y,
            a.z * b.x - a.x * b.z,
            a.x * b.y - a.y * b.x
    );
    return o;
}

Vec2 *normalize(const Vec2 &v) {
    Vec2 *o = v.clone();
    o->normalized();
    return o;
}

Vec3 *normalize(const Vec3 &v) {
    Vec3 *o = v.clone();
    o->normalized();
    return o;
}

Vec4 *normalize(const Vec4 &v) {
    Vec4 *o = v.clone();
    o->normalized();
    return o;
}


float dot(const Vec2 &a, const Vec2 &b) {
    return a.x * b.x + a.y * b.y;
}

float dot(const Vec3 &a, const Vec3 &b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

float dot(const Vec4 &a, const Vec4 &b) {
    return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
}

Vec2 *vec2(float x) {
    return new Vec2(x, x);
}

Vec2 *vec2(float x, float y) {
    return new Vec2(x, y);
}

Vec2 *vec2(const Vec2 &a) {
    return a.clone();
}

Vec3 *vec3(float x) {
    return new Vec3(x, x, x);
}

Vec3 *vec3(float x, float y, float z) {
    return new Vec3(x, y, z);
}

Vec3 *vec3(const Vec3 &a) {
    return a.clone();
}

Vec3 *vec3(const Vec2 &a, float x) {
    return new Vec3(a.x, a.y, x);
}

Vec3 *vec3(float x, const Vec2 &a) {
    return new Vec3(x, a.x, a.y);
}

Vec4 *vec4(float x) {
    return new Vec4(x, x, x, x);
}

Vec4 *vec4(float x, float y, float z, float w) {
    return new Vec4(x, y, z, w);
}

Vec4 *vec4(const Vec3 &a, float w) {
    return new Vec4(a.x, a.y, a.z, w);
}

Vec4 *vec4(const Vec2 &a, float z, float w) {
    return new Vec4(a.x, a.y, z, w);
}

Mat2 *mat2(float a0, float a1, float b0, float b1) {
    return new Mat2(a0, a1, b0, b1);
}

Mat3 *mat3(float a0, float a1, float a2,
           float b0, float b1, float b2,
           float c0, float c1, float c2) {
    return new Mat3(a0, a1, a2,
                    b0, b1, b2,
                    c0, c1, c2);
}

Mat4 *mat4(float a0, float a1, float a2, float a3,
           float b0, float b1, float b2, float b3,
           float c0, float c1, float c2, float c3,
           float d0, float d1, float d2, float d3) {
    return new Mat4(a0, a1, a2, a3,
                    b0, b1, b2, b3,
                    c0, c1, c2, c3,
                    d0, d1, d2, d3);
}

Mat2 *mat2(const Vec2 &a, const Vec2 &b) {
    return new Mat2(a.x, a.y, b.x, b.y);
}

Mat3 *mat3(const Vec3 &a, const Vec3 &b, const Vec3 &c) {
    return new Mat3(a.x, a.y, a.z,
                    b.x, b.y, b.z,
                    c.x, c.y, c.z);
}

Mat4 *mat4(const Vec4 &a, const Vec4 &b, const Vec4 &c, const Vec4 &d) {
    return new Mat4(a.x, a.y, a.z, a.w,
                    b.x, b.y, b.z, b.w,
                    c.x, c.y, c.z, c.w,
                    d.x, d.y, d.z, d.w);
}

inline float distance(const Vec2 &a, const Vec2 &b){
    float dx = a.x - b.x;
    float dy = a.y - b.y;
    return std::sqrt(dx * dx + dy * dy);
}

inline float distance(const Vec3 &a, const Vec3 &b){
    float dx = a.x - b.x;
    float dy = a.y - b.y;
    float dz = a.z - b.z;
    return std::sqrt(dx * dx + dy * dy + dz * dz);
}

inline float distance(const Vec4 &a, const Vec4 &b){
    float dx = a.x - b.x;
    float dy = a.y - b.y;
    float dz = a.z - b.z;
    float dw = a.w - b.w;
    return std::sqrt(dx * dx + dy * dy + dz * dz + dw * dw);
}

inline float length(const Vec2 &a){
    return std::sqrt(a.x * a.x + a.y * a.y);
}

inline float length(const Vec3 &a){
    return std::sqrt(a.x * a.x + a.y * a.y + a.z * a.z);
}

inline float length(const Vec4 &a){
    return std::sqrt(a.x * a.x + a.y * a.y + a.z * a.z + a.w * a.w);
}
