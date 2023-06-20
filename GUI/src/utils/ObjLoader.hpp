/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** objloader
*/

#pragma once

#include <vector>
#include <glm/glm.hpp>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include "ErrorManagement.hpp"
#include "Model.hpp"
#include <map>

namespace GUI::Utils {
    class ObjLoader {
        /**
         * @brief ObjLoader class that handle the loading of .obj files
         */
        public:
            /**
             * @brief Load the .obj file
             */
            static void readObjFile(std::ifstream &file,
                std::vector<unsigned int>& vertexIndices,
                std::vector<unsigned int>& uvIndices,
                std::vector<unsigned int>& normalIndices,
                std::vector<glm::vec3>& vertices,
                std::vector<glm::vec2>& uvs,
                std::vector<glm::vec3>& normals)
            {
                bool thingsToRead = true;
                std::map<std::string, void (*)(
                    std::ifstream &,
                    std::vector<unsigned int>&,
                    std::vector<unsigned int>&,
                    std::vector<unsigned int>&,
                    std::vector<glm::vec3>&,
                    std::vector<glm::vec2>&,
                    std::vector<glm::vec3>&)> ptrOnFunction = {
                    {"v", &readObjFileVertex},
                    {"vt", &readObjFileUv},
                    {"vn", &readObjFileNormal},
                    {"f", &readObjFileFace}
                };
                std::string topHeader = "";

                while (thingsToRead) {
                    topHeader = "";
                    file >> topHeader;
                    if (file.eof())
                        thingsToRead = false;
                    else {
                        if (ptrOnFunction.find(topHeader) != ptrOnFunction.end()) {
                            ptrOnFunction[topHeader](file, vertexIndices, uvIndices, normalIndices, vertices, uvs, normals);
                        }
                    }
                }
            };

            /**
             * @brief Get the Vertices object
             *
             * @return std::vector<glm::vec3>&
             */
            static std::ifstream openFile(const std::string &filePath)
            {
                std::ifstream file(filePath);

                if (!file) {
                    throw GUI::ObjLoadException("Error: Cannot open file " + filePath);
                }
                return file;
            }

            /**
             * @brief Load the .obj file and return a model. It load the mesh.
             *
             * @return std::shared_ptr<GUI::Graphic::Object::Model> model
             */
            static std::shared_ptr<GUI::Graphic::Object::Model> createModelFromObjFilePath(const std::string &path)
            {
                std::ifstream file = openFile(path);
                std::vector<unsigned int> vertexIndices, uvIndices, normalIndices;
                std::vector<glm::vec3> vertices;
                std::vector<glm::vec2> uvs;
                std::vector<glm::vec3> normals;
                std::shared_ptr<GUI::Graphic::Object::Mesh> mesh = std::make_shared<GUI::Graphic::Object::Mesh>();
                std::shared_ptr<GUI::Graphic::Object::Model> model = std::make_shared<GUI::Graphic::Object::Model>();

                readObjFile(file, vertexIndices, uvIndices, normalIndices, vertices, uvs, normals);
                for (unsigned int i = 0; i < vertexIndices.size(); i++) {
                    mesh->addVertex(vertices[vertexIndices[i] - 1].x, vertices[vertexIndices[i] - 1].y, vertices[vertexIndices[i] - 1].z);
                }
                for (unsigned int i = 0; i < uvIndices.size(); i++) {
                    mesh->addUV(uvs[uvIndices[i] - 1].x, uvs[uvIndices[i] - 1].y);
                }
                if (normalIndices.size() != 0)
                    for (unsigned int i = 0; i < normalIndices.size(); i++)
                        mesh->addNormal(normals[normalIndices[i] - 1].x, normals[normalIndices[i] - 1].y, normals[normalIndices[i] - 1].z);
                else {
                    for (unsigned int i = 0; i < vertexIndices.size() / 3; i++) {
                        glm::vec3 v1 = vertices[vertexIndices[i * 3] - 1];
                        glm::vec3 v2 = vertices[vertexIndices[i * 3 + 1] - 1];
                        glm::vec3 v3 = vertices[vertexIndices[i * 3 + 2] - 1];
                        glm::vec3 normal = glm::normalize(glm::cross(v2 - v1, v3 - v1));
                        mesh->addNormal(normal.x, normal.y, normal.z);
                        mesh->addNormal(normal.x, normal.y, normal.z);
                        mesh->addNormal(normal.x, normal.y, normal.z);
                    }
                }
                mesh->load();
                model->addMesh(mesh);
                return model;
            }

        private:
            static void readObjFileVertex(std::ifstream &file,
                std::vector<unsigned int>& vertexIndices,
                std::vector<unsigned int>& uvIndices,
                std::vector<unsigned int>& normalIndices,
                std::vector<glm::vec3>& vertices,
                std::vector<glm::vec2>& uvs,
                std::vector<glm::vec3>& normals)
            {
                (void)vertexIndices;
                (void)uvIndices;
                (void)normalIndices;
                (void)uvs;
                (void)normals;
                glm::vec3 vertex;
                file >> vertex.x >> vertex.y >> vertex.z;
                vertices.push_back(vertex);
            }

            static void readObjFileUv(std::ifstream &file,
                std::vector<unsigned int>& vertexIndices,
                std::vector<unsigned int>& uvIndices,
                std::vector<unsigned int>& normalIndices,
                std::vector<glm::vec3>& vertices,
                std::vector<glm::vec2>& uvs,
                std::vector<glm::vec3>& normals)
            {
                (void)vertexIndices;
                (void)uvIndices;
                (void)normalIndices;
                (void)vertices;
                (void)normals;
                glm::vec2 uv;
                file >> uv.x >> uv.y;
                uvs.push_back(uv);
            }

            static void readObjFileNormal(std::ifstream &file,
                std::vector<unsigned int>& vertexIndices,
                std::vector<unsigned int>& uvIndices,
                std::vector<unsigned int>& normalIndices,
                std::vector<glm::vec3>& vertices,
                std::vector<glm::vec2>& uvs,
                std::vector<glm::vec3>& normals)
            {
                (void)vertexIndices;
                (void)uvIndices;
                (void)normalIndices;
                (void)uvs;
                (void)vertices;
                glm::vec3 normal;
                file >> normal.x >> normal.y >> normal.z;
                normals.push_back(normal);
            }

            static void readObjFileFace(std::ifstream &file,
                std::vector<unsigned int>& vertexIndices,
                std::vector<unsigned int>& uvIndices,
                std::vector<unsigned int>& normalIndices,
                std::vector<glm::vec3>& vertices,
                std::vector<glm::vec2>& uvs,
                std::vector<glm::vec3>& normals)
            {
                (void)normalIndices;
                (void)vertices;
                (void)uvs;
                (void)normals;
                (void)uvIndices;
                unsigned int vertexIndex[4];
                unsigned int tmpBuffer;
                char slash = 0;
                size_t cursor = 0;

                file.get();
                while (file.peek() != '\n' && file.peek() != '\r' && file.peek() != EOF) {
                    file >> vertexIndex[cursor];
                    while (file.peek() == '/') {
                        file >> slash >> tmpBuffer;
                    }
                    file.get();
                    cursor++;
                }

                if (cursor == 3) {
                    vertexIndices.push_back(vertexIndex[0]);
                    vertexIndices.push_back(vertexIndex[1]);
                    vertexIndices.push_back(vertexIndex[2]);
                } else if (cursor == 4) {
                    vertexIndices.push_back(vertexIndex[0]);
                    vertexIndices.push_back(vertexIndex[1]);
                    vertexIndices.push_back(vertexIndex[2]);
                    vertexIndices.push_back(vertexIndex[2]);
                    vertexIndices.push_back(vertexIndex[3]);
                    vertexIndices.push_back(vertexIndex[0]);
                }
            }
    };
}
