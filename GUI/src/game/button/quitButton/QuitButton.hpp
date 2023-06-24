/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** QuitButton
*/

#pragma once
#include "Camera.hpp"
#include "AButton.hpp"
#include <functional>
#include "Window.hpp"

namespace GUI::Game::Button {
    class QuitButton : public GUI::Graphic::AButton {
        public:
            QuitButton(std::shared_ptr<GUI::Graphic::Window> window, const Vector2 &pos = {0, 0}, const Vector2 &size = {0, 0}, const std::string &texturePath = "assets/button/quitButton.png"): AButton(texturePath, pos, size), _window(window) {};
            ~QuitButton(void) = default;

            void click(void) override;
        private:
            std::shared_ptr<GUI::Graphic::Window> _window;
    };
}
