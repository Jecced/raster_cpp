//
// Created by Admin on 2022/10/8.
//

#include <map>

#include "mesh.h"



Mesh::Mesh() {
    // 位置
    this->vertices = new std::vector<Vec3>();
    // 法线
    this->normals = new std::vector<Vec3>();
    // uv0
    this->texCoords = new std::vector<Vec2>();
    // 顶点色
    this->color = new std::vector<Vec4>();

    // 索引顺序
    this->indices = new std::vector<int>();
}




A2V Mesh::at(int index) {
    return at(index, *new A2V ());
}

A2V Mesh::at(int index, A2V &out) {
    out.normal->set(normals->at(index));
    out.vertex->set(vertices->at(index));
    out.texCoord->set(texCoords->at(index));
    out.color->set(color->at(index));
    return out;
}
