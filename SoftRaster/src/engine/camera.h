//
// Created by jecced on 2022/10/5.
//

#ifndef SOFTRASTER_CAMERA_H
#define SOFTRASTER_CAMERA_H


#include "../matrix/matrix.h"

class Camera {
private:
    // 位置
    Vec3 *position;
    // 朝向
    Vec3 *direct;
    // 上方向
    Vec3 *up;
    // 是否使用透视
    bool perspective;
    // fov可视角
    float fov;

    int width, height;

    float near, far;

    /**
     * 将标准-1~1的矩阵变换到屏幕大小的矩阵
     * 将宽/高, 由-1 ~ 1变成-w/2 ~ w/2和 h/2 ~ -h/2
     * 注意, 这里h相当于做了一次翻转
     */
    Mat4* matScreen;

    /**
     * 将rl, tb, nf, 变换到-1 ~ 1的标准矩阵中
     */
    Mat4* matOrthographic;

    /**
     * 观察矩阵, 将摄像机摆放到0,0,0, 并且将世界看向-z方向
     */
    Mat4* matView;
    Mat4* matViewIT;

    /**
     * 透视矩阵, 将世界根据近大远小进行变换
     */
    Mat4* matProjection;
    Mat4* matProjectionIT;

public:
    Camera(int width, int height, float near, float far);

    Camera(int width, int height, float near, float far, float fov);

    void setPosition(float x, float y, float z);

    void setPosition(const Vec3 &position);

    void setPosition(const Vec4 &position);

    Vec4 *getPosition();

    void lookAt(const Vec3 &position);

    void usePerspective();

    void useOrthographic();

    Mat4* getViewMat();

    Mat4* getViewMatIT();

    Mat4* getOrthographicMat();

    Mat4* getScreenMat();

    Mat4* getProjectionMat();

    Mat4* getProjectionMatIT();

private:
    void calcMatView();

    /**
     * 计算正交矩阵 / 正射投影视体
     * 将rl, tb, nf, 变换到-1 ~ 1的标准矩阵中
     */
    void calcMatOrthographic();

    /**
     * 将标准-1~1的矩阵变换到屏幕大小的矩阵
     * 将宽/高, 由-1 ~ 1变成-w/2 ~ w/2和 h/2 ~ -h/2
     * 注意, 这里h相当于做了一次翻转
     */
    void calcMatScreen();

    /**
     * 计算透视矩阵, 实现近大远小
     */
    void calcMatProjection();
};


#endif //SOFTRASTER_CAMERA_H
