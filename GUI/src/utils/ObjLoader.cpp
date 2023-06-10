/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** objloader
*/

#include "ObjLoader.hpp"
#include "ErrorManagement.hpp"

std::ifstream GUI::ObjLoader::openFile(const std::string& filePath)
{
    std::ifstream file(filePath);

    if (!file) {
        throw GUI::ObjLoadException("Error: Cannot open file " + filePath);
    }
    return file;
}

bool GUI::ObjLoader::readFile(std::vector<unsigned int>& vertexIndices, std::vector<unsigned int>& uvIndices, std::vector<unsigned int>& normalIndices, std::vector<glm::vec3>& temp_vertices, std::vector<glm::vec2>& temp_uvs, std::vector<glm::vec3>& temp_normals)
{
    while (true) {
        char TopHeader[128];
        _fileIsGood >> TopHeader;
        if (_fileIsGood.eof())
            break;
        if (strcmp(TopHeader, "v") == 0) {
            glm::vec3 vertex;
            _fileIsGood >> vertex.x >> vertex.y >> vertex.z;
            temp_vertices.push_back(vertex);
        }
        else if (strcmp(TopHeader, "vt") == 0) {
            glm::vec2 uv;
            _fileIsGood >> uv.x >> uv.y;
            temp_uvs.push_back(uv);
        }
        else if (strcmp(TopHeader, "vn") == 0) {
            glm::vec3 normal;
            _fileIsGood >> normal.x >> normal.y >> normal.z;
            temp_normals.push_back(normal);
        }
        else if (strcmp(TopHeader, "f") == 0) {
            std::string vertex1, vertex2, vertex3;
            unsigned int vertexIndex[3], uvIndex[3], normalIndex[3];
            char slash;
            _fileIsGood >> vertexIndex[0] >> slash >> uvIndex[0] >> slash >> normalIndex[0]
            >> vertexIndex[1] >> slash >> uvIndex[1] >> slash >> normalIndex[1]
            >> vertexIndex[2] >> slash >> uvIndex[2] >> slash >> normalIndex[2];

            if (slash != '/') {
                throw GUI::ObjLoadException("Error: Cannot read file");
                return false;
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
    }
    _OutNormals = temp_normals;
    _OutUvs = temp_uvs;
    _OutVertices = temp_vertices;
    return true;
}

bool GUI::ObjLoader::loadObj(const char *path)
{
    std::vector<unsigned int> vertexIndices;
    std::vector<unsigned int> uvIndices;
    std::vector<unsigned int> normalIndices;
    std::vector<glm::vec3> temp_vertices;
    std::vector<glm::vec2> temp_uvs;
    std::vector<glm::vec3> temp_normals;

    _fileIsGood = openFile(path);
    if (!_fileIsGood)
        return false;
    if (!readFile(vertexIndices, uvIndices, normalIndices, temp_vertices, temp_uvs, temp_normals))
        return false;
    return true;
}
