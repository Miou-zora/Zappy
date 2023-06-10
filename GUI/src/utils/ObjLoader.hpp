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
                // ptr on function
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

                while (thingsToRead) {
                    std::string TopHeader;
                    file >> TopHeader;
                    if (file.eof())
                        thingsToRead = false;
                    else {
                        if (ptrOnFunction.find(TopHeader) != ptrOnFunction.end()) {
                            ptrOnFunction[TopHeader](file, vertexIndices, uvIndices, normalIndices, vertices, uvs, normals);
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
                (void)vertices;
                (void)uvs;
                (void)normals;
                std::string vertex1, vertex2, vertex3;
                unsigned int vertexIndex[3], uvIndex[3], normalIndex[3];
                char slash;
                file >> vertexIndex[0] >> slash >> uvIndex[0] >> slash >> normalIndex[0]
                >> vertexIndex[1] >> slash >> uvIndex[1] >> slash >> normalIndex[1]
                >> vertexIndex[2] >> slash >> uvIndex[2] >> slash >> normalIndex[2];

                if (slash != '/') {
                    throw GUI::ObjLoadException("Error: Cannot read file");
                }
                vertexIndices.push_back(vertexIndex[0]);
                vertexIndices.push_back(vertexIndex[1]);
                vertexIndices.push_back(vertexIndex[2]);
                uvIndices.push_back(uvIndex[0]);
                uvIndices.push_back(uvIndex[1]);
                uvIndices.push_back(uvIndex[2]);
                normalIndices.push_back(normalIndex[0]);
                normalIndices.push_back(normalIndex[1]);
                normalIndices.push_back(normalIndex[2]);
            }
    };
}
