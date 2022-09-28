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
    void set(Vec2 other);

    void scale(float scale);
    bool isZero();
    void reverse();
    void normalized();

    Vec2 clone();
};


#endif //SOFTRASTER_VEC2_H
