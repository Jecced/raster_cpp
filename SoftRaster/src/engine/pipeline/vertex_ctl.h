//
// Created by Admin on 2022/10/8.
//

#ifndef SOFTRASTER_VERTEX_CTL_H
#define SOFTRASTER_VERTEX_CTL_H


#include "vector"
#include "../comp/mesh.h"
#include "../struct/v2f.h"

class VertexCtl {
private:
    Mesh mesh;
    std::vector<A2V*> *a2v;
    std::vector<V2F*> *v2f;
public:
    VertexCtl();
    void setMesh(const Mesh& mesh);
    int getSize();

    A2V* getA2V(const int index);
    V2F* getV2F(const int index);
private:
};


#endif //SOFTRASTER_VERTEX_CTL_H
