//
// Created by Admin on 2022/10/8.
//

#ifndef SOFTRASTER_VERTEX_CTL_H
#define SOFTRASTER_VERTEX_CTL_H


#include "vector"
#include "../comp/mesh.h"

class VertexCtl {
private:
    Mesh mesh;
    std::vector<A2V*> *vertexes;
public:
    VertexCtl();
    void setMesh(const Mesh& mesh);
    int getSize();
private:
};


#endif //SOFTRASTER_VERTEX_CTL_H
