//
// Created by Admin on 2022/10/8.
//

#ifndef SOFTRASTER_MESH_H
#define SOFTRASTER_MESH_H

#include <vector>
#include "../../matrix/matrix.h"
#include "../struct/a2v.h"

class Mesh {
public:
    std::vector<Vec3> *vertices;
    std::vector<Vec3> *normals;
    std::vector<Vec2> *texCoords;
    std::vector<Vec4> *color;

    std::vector<int> *indices;
public:
    Mesh();

    int size;

    A2V at(int index);
    A2V at(int index, A2V & out);
};


#endif //SOFTRASTER_MESH_H
