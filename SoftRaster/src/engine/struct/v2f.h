//
// Created by root on 2022/10/15.
//

#ifndef SOFTRASTER_V2F_H
#define SOFTRASTER_V2F_H

#include "../../matrix/matrix.h"

class V2F {
public:
    Vec4* positionCS;
    Vec4* positionWS;
    Vec3* normalOS;
    Vec3* normalWS;
    Vec2* uv0;
    Vec4* color;

};


#endif //SOFTRASTER_V2F_H
