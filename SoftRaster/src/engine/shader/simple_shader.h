//
// Created by root on 2022/10/15.
//

#ifndef SOFTRASTER_SIMPLE_SHADER_H
#define SOFTRASTER_SIMPLE_SHADER_H


#include "shader_lab.h"

#include "../../matrix/matrix.h"


class SimpleShader: public ShaderLab{

    void vert(const A2V& i, V2F& o){
        o.normalOS = i.normal;
        o.normalWS = (*transpose(*matM_IT) * *vec4(*i.normal, 0.0))->xyz();

        o.uv0 = i.texCoord;
        o.color = i.color;

        o.positionWS = *matM * *vec4(*i.vertex, 1.0);
        o.positionCS = *matVP * *o.positionWS;
        gl_Position = o.positionCS;
    }

    void frag(const V2F& i){
        gl_FragColor = i.color;
    }
};


#endif //SOFTRASTER_SIMPLE_SHADER_H
