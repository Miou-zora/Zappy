/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** AButton
*/

#include "AButton.hpp"
#include <iostream>

namespace GUI::Graphic {
    void AButton::setTexture(const std::string &texturePath)
    {
        if (IsTextureReady(_texture))
            UnloadTexture(_texture);
        _texture = LoadTexture(texturePath.c_str());
        if (!IsTextureReady(_texture)) {
            std::cout << "Error: " << texturePath << " not found" << std::endl;
            return;
        }
        if (_size.x == 0)
            _size.x = _texture.width;
        if (_size.y == 0)
            _size.y = _texture.height;
    }


    void AButton::draw(void)
    {
        if (!IsTextureReady(_texture))
            return;
        DrawTexturePro(_texture, {0, 0, (float)_texture.width, (float)_texture.height}, {_pos.x, _pos.y, _size.x, _size.y}, {0, 0}, 0, WHITE);
    }
}
