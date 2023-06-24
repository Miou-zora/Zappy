/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** QuitButton
*/

#include "QuitButton.hpp"
#include <iostream>

namespace GUI::Game::Button {
    void QuitButton::click(void)
    {
        _window->close();
    }
}
