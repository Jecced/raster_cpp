//
// Created by jecced on 2022/10/5.
//

#include "texture.h"
#include <iostream>
//https://github.com/nothings/stb
#include "stb_image.h"

#define STB_IMAGE_IMPLEMENTATION

Texture::Texture(char const *filename) {
    stbi_uc *pixels = stbi_load(filename, &width, &height, &channel, STBI_rgb_alpha);
    if (!pixels) {
        std::cout << "load img error" << std::endl;
        std::cout << filename << std::endl;
    } else {
        data = (unsigned int *) pixels;
    }
}

unsigned int Texture::at(int x, int y) {
    return data[y * width + x];
}

Vec4 *Texture::sample(const Vec2 &uv) {
    return this->sample(uv, new Vec4());
}

Vec4* Texture::sample(const Vec2 &uv, Vec4 *out) {
    unsigned int c = at(uv.x * width, uv.y * height);
    out->x = ((c >> 0) & 0xff) / 255.0f;
    out->y = ((c >> 8) & 0xff) / 255.0f;
    out->z = ((c >> 16) & 0xff) / 255.0f;
    out->w = ((c >> 24) & 0xff) / 255.0f;
    return out;
}