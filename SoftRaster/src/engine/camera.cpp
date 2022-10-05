//
// Created by jecced on 2022/10/5.
//

#include "camera.h"
#include <math.h>

Camera::Camera(int width, int height, float near, float far) {
    Camera(width, height, near, far, 45);
}

Camera::Camera(int width, int height, float near, float far, float fov) {
    this->position = vec3(0, 0, 0);
    this->direct = vec3(0, 0, -1);
    this->up = vec3(0, 1, 0);
    this->width = width;
    this->height = height;
    this->near = near;
    this->far = far;
    this->fov = fov;

    this->matScreen = new Mat4();
    this->matOrthographic = new Mat4();
    this->matView = new Mat4();
    this->matViewIT = new Mat4();
    this->matProjection = new Mat4();
    this->matProjectionIT = new Mat4();

    this->setPosition(0, 0, 0);
    this->lookAt(*vec3(0, 0, -1));
    this->usePerspective();
    this->calcMatScreen();
    this->calcMatOrthographic();
}

void Camera::setPosition(const Vec3 &p) {
    this->setPosition(p.x, p.y, p.z);
}

void Camera::setPosition(const Vec4 &p) {
    this->setPosition(p.x, p.y, p.z);
}

void Camera::setPosition(float x, float y, float z) {
    this->position->set(x, y, z);
    this->calcMatView();
    this->calcMatProjection();
}

Vec4 *Camera::getPosition() {
    return vec4(*position, 1);
}

void Camera::lookAt(const Vec3 &p) {

    Vec3 *pos = vec3(this->position->x, this->position->y, this->position->z);
    Vec3 *dir = *pos - p;

    dir->normalized();
    this->direct->set(*dir);
    this->calcMatView();
    this->calcMatProjection();
}

void Camera::usePerspective() {
    this->perspective = true;
}

void Camera::useOrthographic() {
    this->perspective = false;
}

Mat4 *Camera::getViewMat() {
    return this->matView;
}

Mat4 *Camera::getViewMatIT() {
    return this->matViewIT;
}

Mat4 *Camera::getOrthographicMat() {
    return this->matOrthographic;
}

Mat4 *Camera::getScreenMat() {
    return this->matScreen;
}

Mat4 *Camera::getProjectionMat() {
    return this->matProjection;
}

Mat4 *Camera::getProjectionMatIT() {
    return this->matProjectionIT;
}

void Camera::calcMatView() {
    /**
     * 凝视方向g: this.direct
     * 向上方向t: this.up
     * 眼睛位置e: this.position.xyz
     *
     * w = -normalize(g)
     * u = normalize(t x w)
     * v = w x u
     */
    Vec3 *w = this->direct->clone();
    Vec3 *u = normalize(*cross(*w, *this->up));
    if (u->isZero()) {
        u->set(0, 0, 1);
    }

    Vec3 *v = cross(*w, *u);

    Mat4 *matAngle = mat4(
            u->x, u->y, u->z, 0,
            v->x, v->y, v->z, 0,
            w->x, w->y, w->z, 0,
            0, 0, 0, 1
    );

    Mat4 *matMove = mat4(
            1, 0, 0, -this->position->x,
            0, 1, 0, -this->position->y,
            0, 0, 1, -this->position->z,
            0, 0, 0, 1
    );

    this->matView = *matAngle * *matMove;

    // 逆矩阵
    Mat4 *matAngleIT = transpose(*matAngle);

    Mat4 *matMoveIT = mat4(
            1, 0, 0, this->position->x,
            0, 1, 0, this->position->y,
            0, 0, 1, this->position->z,
            0, 0, 0, 1
    );

    this->matViewIT = *matMoveIT * *matAngleIT;
}

/**
 * 计算正交矩阵 / 正射投影视体
 * 将rl, tb, nf, 变换到-1 ~ 1的标准矩阵中
 */
void Camera::calcMatOrthographic() {
    /**
     * tan(fov/2) = t / n
     */
    float t = tan(this->fov / 360.0f * 2.0f * 3.1415926f / 2.0f) * abs(near);
    float b = -t;
    /**
     *  nx     r
     * ---- = ---
     *  ny     t
     */
    float r = ((float) this->width / (float) this->height) * t;
    float l = -r;

    float n = near, f = far;
    /**
     * 正交矩阵, 将矩阵移动缩放到lrtbnf方块内
     */
    this->matOrthographic->set(
            2 / (r - l), 0, 0, -(r + l) / (r - l),
            0, 2 / (t - b), 0, -(t + b) / (t - b),
            0, 0, 2 / (n - f), -(n + f) / (n - f),
            0, 0, 0, 1
    );

}

/**
 * 将标准-1~1的矩阵变换到屏幕大小的矩阵
 * 将宽/高, 由-1 ~ 1变成-w/2 ~ w/2和 h/2 ~ -h/2
 * 注意, 这里h相当于做了一次翻转
 */
void Camera::calcMatScreen() {
    float w = (float) this->width;
    float h = (float) this->height;
    this->matScreen->set(
            w / 2, 0, 0, w / 2,
            0, -h / 2, 0, h / 2,
            0, 0, 1, 0,
            0, 0, 0, 1
    );
}

/**
 * 计算透视矩阵, 实现近大远小
 */
void Camera::calcMatProjection() {
    if (!this->perspective) {
        this->matProjection->identity();
        this->matProjectionIT->identity();
        return;
    }

    float n = this->near;
    float f = this->far;
    this->matProjection->set(
            n, 0, 0, 0,
            0, n, 0, 0,
            0, 0, n + f, -f * n,
            0, 0, 1, 0
    );

    this->matProjectionIT->set(
            f, 0, 0, 0,
            0, f, 0, 0,
            0, 0, 0, f * n,
            0, 0, -1, n + f
    );
}