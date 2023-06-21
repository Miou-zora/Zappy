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
#include <glm/gtx/transform.hpp>

namespace GUI::Graphic {
    Window::Window(float width, float height, const std::string &title):
        _width(width), _height(height), _title(title), _grabbed(false)
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


        glGenVertexArrays(1, &_vertexArrayID); //! This is maybe the Big Array of Vertexes of OpenGL
        glBindVertexArray(_vertexArrayID);

        glfwSetInputMode(_window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
        glfwSetCursorPos(_window, _width / 2, _height / 2);

        _open = true;
    }

    void Window::_grab(std::shared_ptr<GUI::Graphic::Scene> scene)
    {
        double mouseXPos = 0;
        double mouseYPos = 0;
        double sensibility = 0.1;
        if (_grabbed == false) {
            _grabbed = true;
            glfwSetInputMode(_window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
            glfwSetCursorPos(_window, _width / 2, _height / 2);
        }
        glfwGetCursorPos(_window, &mouseXPos, &mouseYPos);
        if (mouseXPos != _width / 2) {
            scene->getCamera()->setRot(scene->getCamera()->getRot().x, scene->getCamera()->getRot().y + glm::radians(mouseXPos - _width / 2) * sensibility, scene->getCamera()->getRot().z);
        }
        if (mouseYPos != _height / 2) {
            if (scene->getCamera()->getRot().x + glm::radians(mouseYPos - _height / 2) * sensibility < M_PI / 2 && scene->getCamera()->getRot().x + glm::radians(mouseYPos - _height / 2) * sensibility > -M_PI / 2)
                scene->getCamera()->setRot(scene->getCamera()->getRot().x + glm::radians(mouseYPos - _height / 2) * sensibility, scene->getCamera()->getRot().y, scene->getCamera()->getRot().z);
        }
        glfwSetCursorPos(_window, _width / 2, _height / 2);
    }

    void Window::_drop(void)
    {
        if (_grabbed == true) {
            _grabbed = false;
            glfwSetInputMode(_window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
        }
    }

    void Window::pollEvent(std::shared_ptr<GUI::Graphic::Scene> scene)
    {
        glfwPollEvents();
        if (glfwGetKey(_window, GLFW_KEY_ESCAPE) == GLFW_PRESS || glfwWindowShouldClose(_window) != 0) {
            _open = false;
        }
        if (glfwGetMouseButton(_window, GLFW_MOUSE_BUTTON_RIGHT) == GLFW_PRESS) {
            _grab(scene);
        } else {
            _drop();
        }
        _cameraMove(scene);
    }

    void Window::_cameraMove(std::shared_ptr<GUI::Graphic::Scene> scene)
    {
        glm::vec3 direction = glm::vec3(0, 0, 0);
        if (glfwGetKey(_window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS || glfwGetKey(_window, GLFW_KEY_RIGHT_SHIFT) == GLFW_PRESS) {
            direction.y -= 0.1;
        }
        if (glfwGetKey(_window, GLFW_KEY_SPACE) == GLFW_PRESS) {
            direction.y += 0.1;
        }
        // I have zqsd
        if (glfwGetKey(_window, GLFW_KEY_A) == GLFW_PRESS) {
            direction.x += 0.1 * cos(scene->getCamera()->getRot().y);
            direction.z += 0.1 * sin(scene->getCamera()->getRot().y);
        }
        if (glfwGetKey(_window, GLFW_KEY_D) == GLFW_PRESS) {
            direction.x -= 0.1 * cos(scene->getCamera()->getRot().y);
            direction.z -= 0.1 * sin(scene->getCamera()->getRot().y);
        }
        if (glfwGetKey(_window, GLFW_KEY_S) == GLFW_PRESS) {
            direction.x += 0.1 * sin(scene->getCamera()->getRot().y);
            direction.z -= 0.1 * cos(scene->getCamera()->getRot().y);
        }
        if (glfwGetKey(_window, GLFW_KEY_W) == GLFW_PRESS) {
            direction.x -= 0.1 * sin(scene->getCamera()->getRot().y);
            direction.z += 0.1 * cos(scene->getCamera()->getRot().y);
        }
        scene->getCamera()->setPos(scene->getCamera()->getPos().x + direction.x,
                                   scene->getCamera()->getPos().y + direction.y,
                                   scene->getCamera()->getPos().z + direction.z);
    }

    void Window::clear(void)
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    void Window::display(void)
    {
        glfwSwapBuffers(_window);
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
