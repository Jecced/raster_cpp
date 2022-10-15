//
// Created by Admin on 2022/10/8.
//

#include "vertex_ctl.h"


VertexCtl::VertexCtl() {
    this->a2v = new std::vector<A2V *>();
    this->v2f = new std::vector<V2F *>();
    this->glPositionList = new std::vector<Vec4 *>();
}

void VertexCtl::setMesh(const Mesh &mesh) {
    this->mesh = mesh;

    /**
     * 根据mesh 批量成成a2v
     */
    // 如果模型大小超过当前pool内的大小，则对pool进行强制加入实例对象
    if (this->mesh.size > a2v->size()) {
        for (int i = 0, len = this->mesh.size - a2v->size(); i < len; i++) {
            a2v->push_back(new A2V());
            v2f->push_back(new V2F());
            glPositionList->push_back(vec4(0));
        }
    }
    for(int i = 0, len = this->mesh.size; i < len; i++){
        this->mesh.at(i, *this->a2v->at(i));
    }
}


int VertexCtl::getSize() {
    return this->mesh.size;
}

A2V *VertexCtl::getA2V(const int index) {
    return this->a2v->at(index);
}

V2F *VertexCtl::getV2F(const int index) {
    return this->v2f->at(index);
}

Vec4 *VertexCtl::getGlPosition(const int index) {
    return this->glPositionList->at(index);
}

