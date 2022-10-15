//
// Created by root on 2022/10/15.
//

#ifndef SOFTRASTER_PIPELINE_H
#define SOFTRASTER_PIPELINE_H


#include "vertex_ctl.h"
#include "../comp/camera.h"
#include "../buffer/camera_target.h"
#include "../shader/shader_lab.h"

class Pipeline {
private:
    int width, height;
    VertexCtl *vertexCtl;
    CameraTarget *cameraTarget;
    ShaderLab *shader;
    V2F *variableV2F;
    Vec4 *hsCache[3] = {vec4(0), vec4(0), vec4(0)};
    Vec4 *boundBox;
public:
    Pipeline(int width, int height, unsigned int *framebuffer);

    void setupCamera(Camera camera);

    void drawMesh(const Mesh &mesh);

    void bindShader(ShaderLab &shader);

    void clear();

private:
    void rasterizer(Vec4 &p0, Vec4 &p1, Vec4 &p2, const V2F &v0, const V2F &v1, const V2F &v2);
};


#endif //SOFTRASTER_PIPELINE_H
