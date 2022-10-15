//
// Created by root on 2022/10/16.
//

#ifndef SOFTRASTER_SHADER_UNLIT_H
#define SOFTRASTER_SHADER_UNLIT_H


#include "shader_lab.h"

class ShaderUnlit : public ShaderLab {
private:
    Texture* mainTex;

public:
    ShaderUnlit(char const *filename){
        mainTex = new Texture(filename);
    }

    void vert(const A2V &i, V2F &o) {
        o.normalOS = i.normal;
        o.normalWS = (*transpose(*matM_IT) * *vec4(*i.normal, 0.0))->xyz();

        o.uv0 = i.texCoord;
        o.color = i.color;

        o.positionWS = *matM * *vec4(*i.vertex, 1.0);
        o.positionCS = *matVP * *o.positionWS;
        gl_Position = o.positionCS;
    }

    void frag(const V2F &i) {
        gl_FragColor = texture2D(*mainTex, *i.uv0);
//        *i.normalOS = *normalize(*i.normalOS);
//        *i.normalOS = *(*i.normalOS * 0.5);
//        *i.normalOS = *(*i.normalOS + 0.5);
//        gl_FragColor = vec4(*i.normalOS, 1.0);
//        gl_FragColor = vec4(*i.uv0, 0, 1);
    }
};


#endif //SOFTRASTER_SHADER_UNLIT_H
