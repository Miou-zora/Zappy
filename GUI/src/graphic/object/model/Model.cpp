/*
** EPITECH PROJECT, 2023
** GUI
** File description:
** Model
*/

#include "Model.hpp"
#include "ObjLoader.hpp"
#include "ErrorManagement.hpp"

namespace GUI::Graphic::Object {
    Model::Model()
    {

    }

    Model::Model(Program &program)
    {
        _program = program;
    }

    Model::Model(const Model &model): Object()
    {
        for (auto mesh : model._meshes)
            _meshes.push_back(mesh);
    }

    void Model::setProgram(Program &program)
    {
        _program = program;
    }

    const Program &Model::getProgram(void) const
    {
        return _program;
    }

    Model &Model::operator=(const Model &model)
    {
        for (auto mesh : model._meshes)
            _meshes.push_back(mesh);
        return *this;
    }

    void Model::loadProgram()
    {
        if (!_program.isLoaded()) {

        }
        for (auto mesh : _meshes)
            mesh.loadProgram(_program);
    }

    void Model::load(void)
    {
        for (auto mesh : _meshes)
            mesh.load();
    }

    void Model::update(void)
    {

    }

    void Model::draw(const Camera &camera)
    {
        glm::mat4 model = getModelMatrix();
        glm::mat4 view = camera.getViewMatrix();
        glm::mat4 projection = camera.getProjectionMatrix();
        glm::mat4 mvp = projection * view * model;
        for (auto mesh : _meshes)
            mesh.render(&mvp[0][0]);
    }

    void Model::unload(void)
    {

    }

    void Model::addMesh(Mesh mesh)
    {
        _meshes.push_back(mesh);
    }

    void Model::addMesh(const std::string &path)
    {
        std::vector<unsigned int> vertexIndices;
        std::vector<unsigned int> uvIndices;
        std::vector<unsigned int> normalIndices;
        std::vector<glm::vec3> vertices;
        std::vector<glm::vec2> uvs;
        std::vector<glm::vec3> normals;
        Mesh mesh;
        std::ifstream file;

        try {
            file = Utils::ObjLoader::openFile(path);
            Utils::ObjLoader::readObjFile(file, vertexIndices, uvIndices, normalIndices, vertices, uvs, normals);
        } catch (const ObjLoadException &e) {
            std::cerr << e.what() << std::endl;
            return;
        }
        for (unsigned int i = 0; i < vertexIndices.size(); i++) {
            mesh.addVertex(vertices[i].x, vertices[i].y, vertices[i].z);
            mesh.addUV(uvs[i].x, uvs[i].y);
            mesh.addNormal(normals[i].x, normals[i].y, normals[i].z);
        }
    }

    const Mesh &Model::getMesh(int index) const
    {
        return _meshes[index];
    }

    Mesh &Model::getMesh(int index)
    {
        return _meshes[index];
    }
}
