//
// Created by Admin on 2022/9/28.
//

#ifndef SOFTRASTER_VEC3_H
#define SOFTRASTER_VEC3_H


class Vec3 {
public:
    Vec3(float x, float y, float z);
    Vec3();
    ~Vec3();
public:
    float x;
    float y;
    float z;

    void set(float mx, float my, float mz);
    void set(const Vec3& other);

    void scale(float scale);
    bool isZero() const;
    void reverse();
    void normalized();

    Vec3* clone() const;

    Vec3* operator+(const Vec3& o) const;
    Vec3* operator-(const Vec3& o) const;
    Vec3* operator*(const Vec3& o) const;
    Vec3* operator/(const Vec3& o) const;

    Vec3* operator+(float v) const;
    Vec3* operator-(float v) const;
    Vec3* operator*(float v) const;
    Vec3* operator/(float v) const;

    std::string toString() const;
};


#endif //SOFTRASTER_VEC3_H
