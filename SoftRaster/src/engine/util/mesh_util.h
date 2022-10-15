//
// Created by root on 2022/10/15.
//

#ifndef SOFTRASTER_MESH_UTIL_H
#define SOFTRASTER_MESH_UTIL_H

#define TINYOBJLOADER_IMPLEMENTATION

#include "../../libs/tiny_obj_loader.h"

#include "../comp/mesh.h"
#include "iostream"

class MeshUtil{
public:
    static Mesh *Obj2Mesh(const char *filename) {

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
            std::cerr << "Failed to load/parse .obj.\n" << std::endl;
            return nullptr;
        }

        Mesh *out = new Mesh();
        std::map<std::string, int> *vertexMap = new std::map<std::string, int>();

        int index = 0;

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
                            attrib.texcoords.at(faceData.texcoord_index * 2 + 0),
                            attrib.texcoords.at(faceData.texcoord_index * 2 + 1)
                    )
            );
            // 插入一个纯白的顶点色
            out->color->push_back(*vec4(1));
        }
        out->size = index;
        vertexMap->clear();

        return out;
    }
};

#endif //SOFTRASTER_MESH_UTIL_H
