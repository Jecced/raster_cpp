//
// Created by root on 2022/10/15.
//

#include "pipeline.h"
#include "../util/math_util.h"
#include "../util/barycentric_util.h"

Pipeline::Pipeline(int width, int height, unsigned int *framebuffer) {
    this->width = width;
    this->height = height;
    vertexCtl = new VertexCtl();
    cameraTarget = new CameraTarget(width, height, framebuffer);
    boundBox = new Vec4();
    variableV2F = new V2F(true);
}

void Pipeline::bindShader(ShaderLab &shader) {
    this->shader = &shader;
}

void Pipeline::setupCamera(Camera camera) {
    shader->matV->set(*camera.getViewMat());
    shader->matP->set(*camera.getProjectionMat());
    Mat4 *os = *camera.getScreenMat() * *camera.getOrthographicMat();
    Mat4 *p = *os * *camera.getProjectionMat();
    Mat4 *v = camera.getViewMat();
    Mat4 *vp = *p * *v;
    shader->matVP->set(*vp);
    // TODO 这里缺少M矩阵
    shader->matMVP->set(*vp);
}

void Pipeline::drawMesh(const Mesh &mesh) {
    vertexCtl->setMesh(mesh);
    // 遍历所有顶点，执行顶点着色器
    for (int i = 0, len = vertexCtl->getSize(); i < len; i++) {
        A2V *a2v = vertexCtl->getA2V(i);
        V2F *v2f = vertexCtl->getV2F(i);
        // 执行顶点着色器
        shader->vert(*a2v, *v2f);
        // 缓存齐次坐标的坐标点
        vertexCtl->getGlPosition(i)->set(*shader->gl_Position);
    }

    for (int i = 0, len = mesh.indices->size() / 3; i < len; i++) {
        int i0 = mesh.indices->at(i * 3 + 0);
        int i1 = mesh.indices->at(i * 3 + 1);
        int i2 = mesh.indices->at(i * 3 + 2);

        hsCache[0]->set(*vertexCtl->getGlPosition(i0));
        hsCache[1]->set(*vertexCtl->getGlPosition(i1));
        hsCache[2]->set(*vertexCtl->getGlPosition(i2));

        // TODO 缺少背面剔除

        // 光栅化
        this->rasterizer(
                *hsCache[0],
                *hsCache[1],
                *hsCache[2],

                *vertexCtl->getV2F(i0),
                *vertexCtl->getV2F(i1),
                *vertexCtl->getV2F(i2)
        );
    }
}

// 光栅化
void Pipeline::rasterizer(Vec4 &p0, Vec4 &p1, Vec4 &p2, const V2F &v0, const V2F &v1, const V2F &v2) {
    float z0 = p0.w;
    float z1 = p1.w;
    float z2 = p2.w;
    p0 = *(p0 / p0.w);
    p1 = *(p1 / p1.w);
    p2 = *(p2 / p2.w);

    // 计算三角形面积
    float s = cross(p1.x - p0.x, p1.y - p0.y, p2.x - p0.x, p2.y - p0.y) * 0.5;
    if (s == 0) {
        return;
    }

    //计算包围盒
    MathUtil::bound(this->width, this->height,
                    p0, p1, p2, *this->boundBox);

    float currX = 0;
    float currY = 0;

    // 包围盒内， 逐像素遍历
    for (int x = this->boundBox->x; x < this->boundBox->z; x++) {
        for (int y = this->boundBox->y; y < this->boundBox->w; y++) {
            currX = x + 0.5;
            currY = y + 0.5;

            // 计算重心坐标
            float alpha = cross(currX - p1.x, currY - p1.y, currX - p2.x, currY - p2.y) / 2 / s;
            float beta = cross(currX - p2.x, currY - p2.y, currX - p0.x, currY - p0.y) / 2 / s;
            float gamma = 1 - alpha - beta;

            // 不在三角形内, 跳过
            if (alpha < 0 || beta < 0 || gamma < 0) {
                continue;
            }

            float rz = p0.z * alpha + p1.z * beta + p2.z * gamma;

            // 深度测试
            if (!this->cameraTarget->zTest(x, y, rz)) {
                continue;
            }
            this->cameraTarget->zWriter(x, y, rz);

            float z = 1 / z0 * alpha + 1 / z1 * beta + 1 / z2 * gamma;
            z = 1 / z;

            alpha = alpha / z0 * z;
            beta = beta / z1 * z;
            gamma = gamma / z2 * z;

            // 顶点数据variable插值
            BarycentricUtil::barycentric(v0, v1, v2, alpha, beta, gamma, *variableV2F);

            shader->frag(*variableV2F);

            cameraTarget->setColor(x, y, *shader->gl_FragColor);
        }
    }
}

void Pipeline::clear() {
    cameraTarget->clear();
}