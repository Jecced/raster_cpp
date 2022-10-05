//
// Created by jecced on 2022/10/5.
//

#ifndef SOFTRASTER_TEXTURE_H
#define SOFTRASTER_TEXTURE_H

#include "../matrix/vec2.h"
#include "../matrix/vec4.h"

class Texture {
private:
    unsigned int *data;
public:
    int width, height, channel;

    Texture(char const *filename);

    unsigned int at(int x, int y);

    Vec4 *sample(const Vec2 &uv);

    Vec4* sample(const Vec2 &uv, Vec4 *out);
};


#endif //SOFTRASTER_TEXTURE_H
