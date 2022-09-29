//
// Created by Admin on 2022/9/28.
//

#ifndef SOFTRASTER_VEC2_H
#define SOFTRASTER_VEC2_H


class Vec2 {
public:
    Vec2(float x, float y);
    Vec2();
    ~Vec2();

public:
    float x;
    float y;

    void set(float x, float y);
    void set(const Vec2& other);

    void scale(float scale);
    bool isZero() const;
    void reverse();
    void normalized();

    Vec2* clone() const;

    Vec2* operator+(const Vec2& o) const;
    Vec2* operator-(const Vec2& o) const;
    Vec2* operator*(const Vec2& o) const;
    Vec2* operator/(const Vec2& o) const;

    Vec2* operator+(float v) const;
    Vec2* operator-(float v) const;
    Vec2* operator*(float v) const;
    Vec2* operator/(float v) const;

    std::string toString() const;
};


#endif //SOFTRASTER_VEC2_H
