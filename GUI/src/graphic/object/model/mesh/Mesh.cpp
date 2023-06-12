/*
** EPITECH PROJECT, 2023
** GUI
** File description:
** Mesh
*/

#include "Mesh.hpp"

#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <iostream>

namespace GUI::Graphic::Object {
    Mesh::Mesh(void)
    {

    }

    Mesh::Mesh(const Mesh &other)
    {
        setVertices(other.getVertices());
        setNormals(other.getNormals());
        setUVs(other.getUVs());
        this->_vertexBuffer = other._vertexBuffer;
        this->_normalBuffer = other._normalBuffer;
        this->_uvBuffer = other._uvBuffer;
        this->_program = other._program;
    }

    Mesh &Mesh::operator=(const Mesh &other)
    {
        setVertices(other.getVertices());
        setNormals(other.getNormals());
        setUVs(other.getUVs());
        this->_vertexBuffer = other._vertexBuffer;
        this->_normalBuffer = other._normalBuffer;
        this->_uvBuffer = other._uvBuffer;
        this->_program = other._program;
        return *this;
    }

    void Mesh::addVertex(float x, float y, float z)
    {
        _vertices.push_back(x);
        _vertices.push_back(y);
        _vertices.push_back(z);
    }

    void Mesh::addNormal(float x, float y, float z)
    {
        _normals.push_back(x);
        _normals.push_back(y);
        _normals.push_back(z);
    }

    void Mesh::addUV(float x, float y)
    {
        _uvs.push_back(x);
        _uvs.push_back(y);
    }

    const std::vector<float> &Mesh::getVertices(void) const
    {
        return _vertices;
    }

    const std::vector<float> &Mesh::getNormals(void) const
    {
        return _normals;
    }

    const std::vector<float> &Mesh::getUVs(void) const
    {
        return _uvs;
    }

    void Mesh::setVertices(const std::vector<float> &vertices)
    {
        for (auto &vertex : vertices)
            _vertices.push_back(vertex);
    }

    void Mesh::setNormals(const std::vector<float> &normals)
    {
        for (auto &normal : normals)
            _normals.push_back(normal);
    }

    void Mesh::setUVs(const std::vector<float> &uvs)
    {
        for (auto &uv : uvs)
            _uvs.push_back(uv);
    }

    void Mesh::load(void)
    {
        glGenBuffers(1, &_vertexBuffer);
        glBindBuffer(GL_ARRAY_BUFFER, _vertexBuffer);
        glBufferData(GL_ARRAY_BUFFER, sizeof(_vertices[0]) * _vertices.size(), &_vertices[0], GL_STATIC_DRAW);

        glGenBuffers(1, &_normalBuffer);
        glBindBuffer(GL_ARRAY_BUFFER, _normalBuffer);
        glBufferData(GL_ARRAY_BUFFER, sizeof(_normals[0]) * _normals.size(), &_normals[0], GL_STATIC_DRAW);

        glGenBuffers(1, &_uvBuffer);
        glBindBuffer(GL_ARRAY_BUFFER, _uvBuffer);
        glBufferData(GL_ARRAY_BUFFER, sizeof(_uvs[0]) * _uvs.size(), &_uvs[0], GL_STATIC_DRAW);
    }

    void Mesh::loadProgram(std::shared_ptr<Program> program)
    {
        _program = program;
    }

    void Mesh::render(float *mvp) const
    {
        GLuint matrixID = 0;

        glUseProgram(_program->getID());                                     //! Shader link of the object
        matrixID = glGetUniformLocation(_program->getID(), "MVP");    //! Get id of the program to make modification
        glUniformMatrix4fv(matrixID, 1, GL_FALSE, mvp);                     //! Load mvp matrix into shader

        glEnableVertexAttribArray(0);                   //! Say that we use layout(location = 0) variable in shader, for exemple this is for vertices
        glBindBuffer(GL_ARRAY_BUFFER, _vertexBuffer);   //! Binding _vertices attribut
        glVertexAttribPointer(  //! Setup Vertex Array
            0,                  //! Specifie location variable of shader like glEnableVertexAttribArray // attribute 0. No particular reason for 0, but must match the layout in the shader.
            3,                  //! Size of Mesh / Shape, for exemple this is for a triangle so we say 3 for 3 vertices // size
            GL_FLOAT,           //! Type of values. For this, this is position so we want floats // type
            GL_FALSE,           //! Normalize vector // normalized?
            0,                  //! Move to n byte vertex after for each vertex // stride
            (void*)0            //! Start a starting ptr + n for the start // array buffer offset
        );

        glEnableVertexAttribArray(1);  //! Say that we use layout(location = 1) variable in shader, for exemple this is for color of vertices
        glBindBuffer(GL_ARRAY_BUFFER, _normalBuffer); //! Binding _vertices attribut
        glVertexAttribPointer(  //! Setup Vertex Array
            1,                  //! Specifie location variable of shader like glEnableVertexAttribArray // attribute 0. No particular reason for 0, but must match the layout in the shader.
            3,                  //! Size of Mesh / Shape, for exemple this is for a triangle so we say 3 for 3 vertices // size
            GL_FLOAT,           //! Type of values. For this, this is position so we want floats // type
            GL_FALSE,           //! Normalize vector // normalized?
            0,                  //! Move to n byte vertex after for each vertex // stride
            (void*)0            //! Start a starting ptr + n for the start // array buffer offset
        );
        glDrawArrays(GL_TRIANGLES, 0, _vertices.size()); //! Draw vertices: mode TRIANGLES, starting at position, number of vertices
        glDisableVertexAttribArray(0);
    }
}
