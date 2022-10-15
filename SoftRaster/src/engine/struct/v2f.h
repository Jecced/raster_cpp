//
// Created by root on 2022/10/15.
//

#ifndef SOFTRASTER_V2F_H
#define SOFTRASTER_V2F_H

#include "../../matrix/matrix.h"

class V2F {
public:
    Vec4 *positionCS;
    Vec4 *positionWS;
    Vec3 *normalOS;
    Vec3 *normalWS;
    Vec2 *uv0;
    Vec4 *color;
public:
    V2F(bool use = false) {
        if (use) {
            positionCS = new Vec4();
            positionWS = new Vec4();
            normalOS = new Vec3();
            normalWS = new Vec3();
            uv0 = new Vec2();
            color = new Vec4();
        }
    }
};


#endif //SOFTRASTER_V2F_H
