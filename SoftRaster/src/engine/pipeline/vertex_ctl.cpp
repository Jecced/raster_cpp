//
// Created by Admin on 2022/10/8.
//

#include "vertex_ctl.h"


VertexCtl::VertexCtl() {
    this->vertexes = new std::vector<A2V *>();
}

void VertexCtl::setMesh(const Mesh &mesh) {
    this->mesh = mesh;

    /**
     * 根据mesh 批量成成a2v
     */
    // 如果模型大小超过当前pool内的大小，则对pool进行强制加入实例对象
    if (this->mesh.size > vertexes->size()) {
        for (int i = 0, len = this->mesh.size - vertexes->size(); i < len; i++) {
            vertexes->push_back(new A2V());
        }
    }
    for(int i = 0, len = this->mesh.size; i < len; i++){
        this->mesh.at(i, *this->vertexes->at(i));
    }
}


int VertexCtl::getSize() {
    return this->mesh.size;
}
