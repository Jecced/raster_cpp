//
// Created by root on 2022/9/27.
//

#ifndef SOFTRASTER_VEC4_H
#define SOFTRASTER_VEC4_H


class Vec4 {
public:
    Vec4(float x, float y, float z, float w);
    Vec4();
    ~Vec4();

public:
    float x;
    float y;
    float z;
    float w;

    void set(float x, float y, float z, float w);
    void set(const Vec4& other);

    void scale(float scale);
    bool isZero() const;
    void reverse();
    void normalized();

    Vec4* clone() const;

    Vec4* operator+(const Vec4& o) const;
    Vec4* operator-(const Vec4& o) const;
    Vec4* operator*(const Vec4& o) const;
    Vec4* operator/(const Vec4& o) const;

    Vec4* operator+(float v) const;
    Vec4* operator-(float v) const;
    Vec4* operator*(float v) const;
    Vec4* operator/(float v) const;

    std::string toString() const;
};


#endif //SOFTRASTER_VEC4_H
