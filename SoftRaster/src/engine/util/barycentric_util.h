//
// Created by root on 2022/10/15.
//

#ifndef SOFTRASTER_BARYCENTRIC_UTIL_H
#define SOFTRASTER_BARYCENTRIC_UTIL_H

#include "../struct/v2f.h"

/**
 * 重心坐标工具类
 */
class BarycentricUtil {
public:
    /**
     * 将三个顶点的数据进行重心坐标插值
     */
    static void barycentric(const V2F& v0, const V2F& v1, const V2F& v2, const float alpha, const float beta, const float gamma, V2F& out){
        barycentricVec3(*v0.normalWS, *v1.normalWS, *v2.normalWS, alpha, beta, gamma, *out.normalWS);
        barycentricVec3(*v0.normalOS, *v1.normalOS, *v2.normalOS, alpha, beta, gamma, *out.normalOS);
        barycentricVec4(*v0.positionWS, *v1.positionWS, *v2.positionWS, alpha, beta, gamma, *out.positionWS);
        barycentricVec4(*v0.positionCS, *v1.positionCS, *v2.positionCS, alpha, beta, gamma, *out.positionCS);
        barycentricVec4(*v0.color, *v1.color, *v2.color, alpha, beta, gamma, *out.color);
        barycentricVec2(*v0.uv0, *v1.uv0, *v2.uv0, alpha, beta, gamma, *out.uv0);
    }
private:
    static void barycentricVec4(const Vec4& v0, const Vec4& v1, const Vec4& v2, const float alpha, const float beta, const float gamma, Vec4& out){
        out.x = v0.x * alpha + v1.x * beta + v2.x * gamma;
        out.y = v0.y * alpha + v1.y * beta + v2.y * gamma;
        out.z = v0.z * alpha + v1.z * beta + v2.z * gamma;
        out.w = v0.w * alpha + v1.w * beta + v2.w * gamma;
    }

    static void barycentricVec3(const Vec3& v0, const Vec3& v1, const Vec3& v2, const float alpha, const float beta, const float gamma, Vec3& out){
        out.x = v0.x * alpha + v1.x * beta + v2.x * gamma;
        out.y = v0.y * alpha + v1.y * beta + v2.y * gamma;
        out.z = v0.z * alpha + v1.z * beta + v2.z * gamma;
    }

    static void barycentricVec2(const Vec2& v0, const Vec2& v1, const Vec2& v2, const float alpha, const float beta, const float gamma, Vec2& out){
        out.x = v0.x * alpha + v1.x * beta + v2.x * gamma;
        out.y = v0.y * alpha + v1.y * beta + v2.y * gamma;
    }
};


#endif //SOFTRASTER_BARYCENTRIC_UTIL_H
