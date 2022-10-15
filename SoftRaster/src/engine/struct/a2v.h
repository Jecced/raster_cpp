//
// Created by Admin on 2022/10/8.
//

#ifndef SOFTRASTER_A2V_H
#define SOFTRASTER_A2V_H


#include "../../matrix/matrix.h"

class A2V {
public:
    Vec3* vertex;
    Vec3* normal;
    Vec4* color;
    Vec2* texCoord;

public:
    A2V(){
        vertex = new Vec3();
        normal = new Vec3();
        texCoord = new Vec2();
        color = new Vec4();
    }
};


#endif //SOFTRASTER_A2V_H
