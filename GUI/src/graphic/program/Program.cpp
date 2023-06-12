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
        _vertexShaderPath(vertexShaderPath),
        _fragmentShaderPath(fragmentShaderPath),
        _id(0),
        _loaded(false)
    {

    }

    Program::Program(const Program &program)
    {
        this->_fragmentShaderPath = program._fragmentShaderPath;
        this->_vertexShaderPath = program._fragmentShaderPath;
        this->_loaded = program._loaded;
        this->_id = program._id;
    }

    Program::~Program()
    {

    }

    Program &Program::operator=(const Program &program)
    {
        this->_fragmentShaderPath = program._fragmentShaderPath;
        this->_vertexShaderPath = program._fragmentShaderPath;
        this->_loaded = program._loaded;
        this->_id = program._id;
        return *this;
    }

    void Program::load(const std::string &vertexShaderPath, const std::string &fragmentShaderPath)
    {
        _vertexShaderPath = vertexShaderPath;
        _fragmentShaderPath = fragmentShaderPath;
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
        if (_loaded || _vertexShaderPath.empty() || _fragmentShaderPath.empty()) {
            std::cerr << "Program already loaded or no shader path given" << std::endl;
            return;
        }

        GLuint VertexShaderID = glCreateShader(GL_VERTEX_SHADER);
        GLuint FragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
        std::string VertexShaderCode;
        std::string FragmentShaderCode;
        GLint result = GL_FALSE;

        VertexShaderCode = GUI::Utils::FileUtils::loadFile(_vertexShaderPath);
        FragmentShaderCode = GUI::Utils::FileUtils::loadFile(_fragmentShaderPath);


        std::cout << "Compiling shader: " << _vertexShaderPath << std::endl;
        _compileShader(VertexShaderCode, VertexShaderID, result);

        std::cout << "Compiling shader: " << _fragmentShaderPath << std::endl;
        _compileShader(FragmentShaderCode, FragmentShaderID, result);

        std::cout << "Linking program" << std::endl;
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
