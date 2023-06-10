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

namespace GUI {
    class ObjLoader {
        /**
         * @brief ObjLoader class that handle the loading of .obj files
         */
        public:
            /**
             * @brief Construct a new ObjLoader object
             *
             * @param path path to the .obj file
             */
            ObjLoader(void) = default;
            /**
             * @brief Destroy the ObjLoader object
             */
            ~ObjLoader(void) = default;
            /**
             * @brief Load the .obj file
             *
             * @param path path to the .obj file
             * @param out_vertices vector of vertices
             * @param out_uvs vector of uvs
             * @param out_normals vector of normals
             */
            bool loadObj(const char *path);
            /**
             * @brief Get the Vertices object
             *
             * @return std::vector<glm::vec3>&
             */
            bool readFile(std::vector<unsigned int> &vertexIndices, std::vector<unsigned int> &uvIndices, std::vector<unsigned int> &normalIndices, std::vector<glm::vec3> &temp_vertices, std::vector<glm::vec2> &temp_uvs, std::vector<glm::vec3> &temp_normals);
        private:
            std::ifstream openFile(const std::string &filePath);
            std::ifstream _fileIsGood;
            std::vector<glm::vec3> &_OutVertices;
            std::vector<glm::vec2> &_OutUvs;
            std::vector<glm::vec3> &_OutNormals;
    };
}
