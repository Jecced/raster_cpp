//
// Created by Admin on 2022/9/29.
//

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

Vec3 * cross(const Vec3 &a, const Vec3 &b) {
    Vec3 *o = new Vec3(
            a.y * b.z - a.z * b.y,
            a.z * b.x - a.x * b.z,
            a.x * b.y - a.y * b.x
    );
    return o;
}

Vec2* normalize(const Vec2& v){
    Vec2* o = v.clone();
    o->normalized();
    return o;
}

Vec3* normalize(const Vec3& v){
    Vec3* o = v.clone();
    o->normalized();
    return o;
}

Vec4* normalize(const Vec4& v){
    Vec4* o = v.clone();
    o->normalized();
    return o;
}


float dot(const Vec2& a, const Vec2& b){
    return a.x * b.x + a.y * b.y;
}
float dot(const Vec3& a, const Vec3& b){
    return a.x * b.x + a.y * b.y + a.z * b.z;
}
float dot(const Vec4& a, const Vec4& b){
    return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
}