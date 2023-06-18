/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** Cube
*/

#include "Cube.hpp"
#include <iostream>

namespace GUI::Graphic::Object {
    std::shared_ptr<Model> CreateCubeModel(void)
    {
        std::shared_ptr<Model> cubeModel = std::make_shared<Model>();
        std::shared_ptr<Mesh> cubeMesh = std::make_shared<Mesh>();

        std::vector<glm::vec3> vertices = {
            glm::vec3(-1.0f,-1.0f,-1.0f),
            glm::vec3(-1.0f,-1.0f, 1.0f),
            glm::vec3(-1.0f, 1.0f, 1.0f),

            glm::vec3( 1.0f, 1.0f,-1.0f),
            glm::vec3(-1.0f,-1.0f,-1.0f),
            glm::vec3(-1.0f, 1.0f,-1.0f),

            glm::vec3( 1.0f,-1.0f, 1.0f),
            glm::vec3(-1.0f,-1.0f,-1.0f),
            glm::vec3( 1.0f,-1.0f,-1.0f),

            glm::vec3( 1.0f, 1.0f,-1.0f),
            glm::vec3( 1.0f,-1.0f,-1.0f),
            glm::vec3(-1.0f,-1.0f,-1.0f),

            glm::vec3(-1.0f,-1.0f,-1.0f),
            glm::vec3(-1.0f, 1.0f, 1.0f),
            glm::vec3(-1.0f, 1.0f,-1.0f),

            glm::vec3( 1.0f,-1.0f, 1.0f),
            glm::vec3(-1.0f,-1.0f, 1.0f),
            glm::vec3(-1.0f,-1.0f,-1.0f),

            glm::vec3(-1.0f, 1.0f, 1.0f),
            glm::vec3(-1.0f,-1.0f, 1.0f),
            glm::vec3( 1.0f,-1.0f, 1.0f),

            glm::vec3( 1.0f, 1.0f, 1.0f),
            glm::vec3( 1.0f,-1.0f,-1.0f),
            glm::vec3( 1.0f, 1.0f,-1.0f),

            glm::vec3( 1.0f,-1.0f,-1.0f),
            glm::vec3( 1.0f, 1.0f, 1.0f),
            glm::vec3( 1.0f,-1.0f, 1.0f),

            glm::vec3( 1.0f, 1.0f, 1.0f),
            glm::vec3( 1.0f, 1.0f,-1.0f),
            glm::vec3(-1.0f, 1.0f,-1.0f),

            glm::vec3( 1.0f, 1.0f, 1.0f),
            glm::vec3(-1.0f, 1.0f,-1.0f),
            glm::vec3(-1.0f, 1.0f, 1.0f),

            glm::vec3( 1.0f, 1.0f, 1.0f),
            glm::vec3(-1.0f, 1.0f, 1.0f),
            glm::vec3( 1.0f,-1.0f, 1.0f)
        };

        std::vector<glm::vec3> normals = {
            glm::vec3(1.0f, 0.0f, 0.0f),
            glm::vec3(1.0f, 0.0f, 0.0f),
            glm::vec3(1.0f, 0.0f, 0.0f),

            glm::vec3(0.0f, 0.0f, 1.0f),
            glm::vec3(0.0f, 0.0f, 1.0f),
            glm::vec3(0.0f, 0.0f, 1.0f),

            glm::vec3(0.0f, 1.0f, 0.0f),
            glm::vec3(0.0f, 1.0f, 0.0f),
            glm::vec3(0.0f, 1.0f, 0.0f),

            glm::vec3(0.0f, 0.0f, 1.0f),
            glm::vec3(0.0f, 0.0f, 1.0f),
            glm::vec3(0.0f, 0.0f, 1.0f),

            glm::vec3(1.0f, 0.0f, 0.0f),
            glm::vec3(1.0f, 0.0f, 0.0f),
            glm::vec3(1.0f, 0.0f, 0.0f),

            glm::vec3(0.0f, 1.0f, 0.0f),
            glm::vec3(0.0f, 1.0f, 0.0f),
            glm::vec3(0.0f, 1.0f, 0.0f),

            glm::vec3(0.0f, 0.0f, -1.0f),
            glm::vec3(0.0f, 0.0f, -1.0f),
            glm::vec3(0.0f, 0.0f, -1.0f),

            glm::vec3(-1.0f, 0.0f, 0.0f),
            glm::vec3(-1.0f, 0.0f, 0.0f),
            glm::vec3(-1.0f, 0.0f, 0.0f),

            glm::vec3(-1.0f, 0.0f, 0.0f),
            glm::vec3(-1.0f, 0.0f, 0.0f),
            glm::vec3(-1.0f, 0.0f, 0.0f),

            glm::vec3(0.0f, -1.0f, 0.0f),
            glm::vec3(0.0f, -1.0f, 0.0f),
            glm::vec3(0.0f, -1.0f, 0.0f),

            glm::vec3(0.0f, -1.0f, 0.0f),
            glm::vec3(0.0f, -1.0f, 0.0f),
            glm::vec3(0.0f, -1.0f, 0.0f),

            glm::vec3(0.0f, 0.0f, -1.0f),
            glm::vec3(0.0f, 0.0f, -1.0f),
            glm::vec3(0.0f, 0.0f, -1.0f)
        };

        std::vector<glm::vec2> uvs = {
            glm::vec2(0.0f, 0.0f),
            glm::vec2(1.0f, 0.0f),
            glm::vec2(1.0f, 1.0f),
            glm::vec2(0.0f, 0.0f),
            glm::vec2(1.0f, 1.0f),
            glm::vec2(0.0f, 1.0f),
            glm::vec2(1.0f, 0.0f),
            glm::vec2(1.0f, 1.0f),
            glm::vec2(0.0f, 1.0f),
            glm::vec2(0.0f, 0.0f),
            glm::vec2(1.0f, 0.0f),
            glm::vec2(1.0f, 1.0f),
            glm::vec2(0.0f, 0.0f),
            glm::vec2(1.0f, 1.0f),
            glm::vec2(0.0f, 1.0f),
            glm::vec2(1.0f, 0.0f),
            glm::vec2(1.0f, 1.0f),
            glm::vec2(0.0f, 1.0f)
        };
        for (size_t i = 0; i < vertices.size(); i++) {
            cubeMesh->addVertex(vertices[i].x, vertices[i].y, vertices[i].z);
        }
        for (size_t i = 0; i < normals.size(); i++) {
            cubeMesh->addNormal(normals[i].x, normals[i].y, normals[i].z);
        }
        for (size_t i = 0; i < uvs.size(); i++) {
            cubeMesh->addUV(uvs[i].x, uvs[i].y);
        }
        cubeModel->addMesh(cubeMesh);
        cubeModel->load();
        return cubeModel;
    }
}
