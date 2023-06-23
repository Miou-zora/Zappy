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
#include "raylib.h"

namespace GUI::Graphic {
    Window::Window(float width, float height, const std::string &title):
        _cursorDisabled(false), _open(false), _width(width), _height(height), _title(title), _grabbed(false)
    {

    }

    Window::~Window()
    {

    }

    void Window::create(void)
    {
        InitWindow(_width, _height, (_title + " Raylib").c_str());
        SetTargetFPS(60);
        _open = true;
    }

    void Window::pollEvent(void)
    {
        if (WindowShouldClose()) {
            _open = false;
        }
        if (IsKeyDown(KEY_P)) {
            if (_cursorDisabled) {
                EnableCursor();
                _cursorDisabled = false;
            }
        }
        if (IsKeyDown(KEY_SEMICOLON)) {
            if (!_cursorDisabled) {
                DisableCursor();
                _cursorDisabled = true;
            }
        }
    }

    void Window::clear(void)
    {
        ClearBackground(BLACK);
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
