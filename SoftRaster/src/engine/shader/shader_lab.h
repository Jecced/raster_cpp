//
// Created by root on 2022/10/15.
//

#ifndef SOFTRASTER_SHADER_LAB_H
#define SOFTRASTER_SHADER_LAB_H


#include "../../matrix/matrix.h"
#include "../struct/a2v.h"
#include "../struct/v2f.h"
#include "../../tex/texture.h"

class ShaderLab {
public:
    Vec4* gl_Position;
    Vec4* gl_FragColor;

    Mat4* matM;
    Mat4* matM_IT;
    Mat4* matV;
    Mat4* matP;
    Mat4* matVP;
    Mat4* matMVP;

public:
    ShaderLab(){
        gl_Position = vec4(0);
        gl_FragColor = vec4(1);
    }
    virtual V2F vert(const A2V& i);

    virtual void frag(const V2F& i);

private:
    Vec4 *texture2D(const Texture& tex,const Vec2& uv){
        return tex.sample(uv);
    }
};


#endif //SOFTRASTER_SHADER_LAB_H
