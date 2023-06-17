/*
** EPITECH PROJECT, 2023
** GUI
** File description:
** Program
*/

#include "Program.hpp"

#include <GL/glew.h>
#include "FileUtils.hpp"
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>

namespace GUI::Graphic {
    Program::Program(const std::string &vertexShaderPath, const std::string &fragmentShaderPath):
        _vertexShaderCode(vertexShaderPath),
        _fragmentShaderCode(fragmentShaderPath),
        _id(0),
        _loaded(false)
    {

    }

    Program::Program(const Program &program)
    {
        _vertexShaderCode = program._vertexShaderCode;
        _fragmentShaderCode = program._fragmentShaderCode;
        _loaded = program._loaded;
        _id = program._id;
    }

    Program::~Program()
    {

    }

    Program &Program::operator=(const Program &program)
    {
        _vertexShaderCode = program._vertexShaderCode;
        _fragmentShaderCode = program._fragmentShaderCode;
        _loaded = program._loaded;
        _id = program._id;
        return *this;
    }

    void Program::load(const std::string &vertexShaderCode, const std::string &fragmentShaderCode)
    {
        _vertexShaderCode = vertexShaderCode;
        _fragmentShaderCode = fragmentShaderCode;
        load();
    }


    void Program::_compileShader(const std::string &shaderCode, unsigned int shaderID, int &result)
    {
        char const *sourcePointer = shaderCode.c_str();
        int InfoLogLength = 0;

        glShaderSource(shaderID, 1, &sourcePointer , NULL);
        glCompileShader(shaderID);

        glGetShaderiv(shaderID, GL_COMPILE_STATUS, &result);
        glGetShaderiv(shaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
        if (InfoLogLength > 0) {
            std::vector<char> shaderErrorMessage(InfoLogLength+1);
            glGetShaderInfoLog(shaderID, InfoLogLength, NULL, &shaderErrorMessage[0]);
            std::cerr << &shaderErrorMessage[0] << std::endl;
        }
    }

    void Program::_linkProgram(int &result, unsigned int VertexShaderID, unsigned int FragmentShaderID)
    {
        int InfoLogLength = 0;
        GLuint ProgramID = glCreateProgram();

        glAttachShader(ProgramID, VertexShaderID);
        glAttachShader(ProgramID, FragmentShaderID);
        glLinkProgram(ProgramID);

        glGetProgramiv(ProgramID, GL_LINK_STATUS, &result);
        glGetProgramiv(ProgramID, GL_INFO_LOG_LENGTH, &InfoLogLength);
        if (InfoLogLength > 0) {
            std::vector<char> ProgramErrorMessage(InfoLogLength+1);
            glGetProgramInfoLog(ProgramID, InfoLogLength, NULL, &ProgramErrorMessage[0]);
            std::cerr << &ProgramErrorMessage[0] << std::endl;
        }
        _id = ProgramID;
    }

    void Program::load(void)
    {
        if (_loaded || _vertexShaderCode.empty() || _fragmentShaderCode.empty()) {
            std::cerr << "Program already loaded or no shader code given" << std::endl;
            return;
        }

        GLuint VertexShaderID = glCreateShader(GL_VERTEX_SHADER);
        GLuint FragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
        GLint result = GL_FALSE;

        _compileShader(_vertexShaderCode, VertexShaderID, result);

        _compileShader(_fragmentShaderCode, FragmentShaderID, result);

        _linkProgram(result, VertexShaderID, FragmentShaderID);

        glDetachShader(_id, VertexShaderID);
        glDetachShader(_id, FragmentShaderID);
        glDeleteShader(VertexShaderID);
        glDeleteShader(FragmentShaderID);
        _loaded = true;
    }

    void Program::unload(void)
    {
        if (_loaded)
            glDeleteProgram(_id);
    }
}
