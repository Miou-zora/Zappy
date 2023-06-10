/*
** EPITECH PROJECT, 2023
** GUI
** File description:
** Window
*/

#include "Window.hpp"
#include <iostream>
#include <cstring>
#include "ErrorManagement.hpp"

namespace GUI::Graphic {
    Window::Window(float width, float height, const std::string &title):
        _width(width), _height(height), _title(title)
    {

    }

    Window::~Window()
    {

    }

    void Window::create(void)
    {
        if (!glfwInit()) {
            throw GUI::WindowCreationException("Failed to initialize GLFW: " + std::string(strerror(errno)) + " " + std::to_string((short)glfwGetError(NULL)));
        }

        glfwWindowHint(GL_SAMPLES, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        _window = glfwCreateWindow(_width, _height, _title.c_str(), NULL, NULL);
        if (_window == NULL) {
            glfwTerminate();
            throw GUI::WindowCreationException("Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials: " + std::string(strerror(errno)) + " " + std::to_string((short)glfwGetError(NULL)));
        }
        glfwMakeContextCurrent(_window);
        glewExperimental=true;
        if (glewInit() != GLEW_OK) {
            throw GUI::WindowCreationException("Failed to initialize GLEW: " + std::string(strerror(errno)) + " " + std::to_string((short)glfwGetError(NULL)));
        }

        glEnable(GL_DEPTH_TEST);
        glDepthFunc(GL_LESS);
        glfwSetInputMode(_window, GLFW_STICKY_KEYS, GL_TRUE);

        GLuint VertexArrayID; //! This is maybe the Big Array of Vertexes of OpenGL
        glGenVertexArrays(1, &VertexArrayID);
        glBindVertexArray(VertexArrayID);

        _open = true;
    }

    void Window::pollEvent(void)
    {
        if (glfwGetKey(_window, GLFW_KEY_ESCAPE) == GLFW_PRESS || glfwWindowShouldClose(_window) != 0) {
            _open = false;
        }
    }

    void Window::clear(void)
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    void Window::display(void)
    {
        glfwSwapBuffers(_window);
        glfwPollEvents();
    }

    bool Window::isOpen(void)
    {
        return _open;
    }

    void Window::close(void)
    {
        _open = false;
    }

    void Window::setOpen(bool open)
    {
        _open = open;
    }
}
