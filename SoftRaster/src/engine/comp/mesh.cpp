//
// Created by Admin on 2022/10/8.
//

#include <iostream>
#include <map>

#include "mesh.h"

#define TINYOBJLOADER_IMPLEMENTATION

#include "../../libs/tiny_obj_loader.h"


Mesh::Mesh() {
    this->vertices = new std::vector<Vec3>();
    this->normals = new std::vector<Vec3>();
    this->texCoords = new std::vector<Vec2>();
}


Mesh *Mesh::Obj2Mesh(const char *filename) {

    tinyobj::attrib_t attrib;
    std::vector<tinyobj::shape_t> shapes;
    std::vector<tinyobj::material_t> materials;

    std::string err;
    bool ret = tinyobj::LoadObj(&attrib, &shapes, &materials, &err, filename,
                                nullptr, true);

    if (!err.empty()) {
        std::cerr << "ERR: " << err << std::endl;
    }

    if (!ret) {
        printf("Failed to load/parse .obj.\n");
        return nullptr;
    }

    Mesh *out = new Mesh();
    std::map<std::string, int> *vertexMap = new std::map<std::string, int>();

    int index = 0;

    out->indices = new std::vector<int>();

    std::vector<tinyobj::index_t> indices = shapes.at(0).mesh.indices;
    for (int i = 0, len = indices.size(); i < len; i++) {
        tinyobj::index_t faceData = indices.at(i);
        std::string testSetKey =
                std::to_string(faceData.vertex_index) + "_" + std::to_string(faceData.normal_index) + "_" +
                std::to_string(faceData.texcoord_index);
//        std::iterator<std::pair<const std::string, int>>
        auto v = vertexMap->find(testSetKey);
        if (v != vertexMap->end()) {
            out->indices->push_back(v->second);
            continue;
        }
        out->indices->push_back(index);
        vertexMap->insert(std::pair<std::string, int>(testSetKey, index));
        index++;

        out->vertices->push_back(
                *vec3(
                        attrib.vertices.at(faceData.vertex_index * 3 + 0),
                        attrib.vertices.at(faceData.vertex_index * 3 + 1),
                        attrib.vertices.at(faceData.vertex_index * 3 + 2)
                )
        );
        out->normals->push_back(
                *vec3(
                        attrib.normals.at(faceData.normal_index * 3 + 0),
                        attrib.normals.at(faceData.normal_index * 3 + 1),
                        attrib.normals.at(faceData.normal_index * 3 + 2)
                )
        );
        out->texCoords->push_back(
                *vec2(
                        attrib.texcoords.at(faceData.normal_index * 2 + 0),
                        attrib.texcoords.at(faceData.normal_index * 2 + 1)
                )
        );
    }
    out->size = index;
    vertexMap->clear();

    return out;
}

A2V Mesh::at(int index) {
    return at(index, *new A2V ());
}

A2V Mesh::at(int index, A2V &out) {
    out.normal.set(normals->at(index));
    out.vertex.set(vertices->at(index));
    out.texCoord.set(texCoords->at(index));
    return out;
}
