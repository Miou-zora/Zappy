/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** Team
*/

#pragma once
#include <string>
#include "raylib.h"

namespace GUI::Game {
    class Team {
        public:
            Team(const std::string &name, const Color &color = BLUE): _name(name), _color(color) {};
            ~Team(void) = default;

            std::string getName(void) const { return _name; };
            Color getColor(void) const { return _color; };

            void setName(const std::string &name) { _name = name; };
            void setColor(const Color &color) { _color = color; };

            bool operator==(const Team &team) const { return _name == team._name; };
            bool operator!=(const Team &team) const { return _name != team._name; };

            Team &operator=(const Team &team)
            {
                _name = team._name;
                _color = team._color;
                return *this;
            };

        private:
            std::string _name;
            Color _color;
    };
}
