/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** AButton
*/

#pragma once
#include "Camera.hpp"
#include "raylib.h"

namespace GUI::Graphic {
    class AButton {
        public:
            AButton(const std::string &texturePath = "", const Vector2 &pos = {0, 0}, const Vector2 &size = {0, 0}): _pos(pos), _size(size)
            {
                if (!texturePath.empty())
                    setTexture(texturePath);
            }
            ~AButton(void) = default;

            void draw(void);
            virtual void click(void) = 0;
            Rectangle getRect(void) const { return {_pos.x, _pos.y, _size.x, _size.y}; };

            void setTexture(const std::string &texturePath);
            void setPos(const Vector2 &pos) { _pos = pos; };
            void setSize(const Vector2 &size) { _size = size; };
        private:
            Texture2D _texture;
            Vector2 _pos;
            Vector2 _size;
    };
}
