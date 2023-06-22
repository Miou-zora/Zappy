/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** Map
*/

#pragma once
#include <vector>
#include <memory>
#include "Tile.hpp"
#include "raylib.h"

namespace GUI::Game {
    class Map {
        public:
            Map(unsigned int x, unsigned int y);
            ~Map(void) = default;

            void resize(unsigned int x, unsigned int y);

            void update(void);
            void render(void);

            std::shared_ptr<GUI::Game::Tile> getTile(unsigned int x, unsigned int y) const;

            Vector2 getSize(void) const {return _size; };

        private:
            Vector2 _size;
            std::vector<std::vector<std::shared_ptr<GUI::Game::Tile>>> _tiles;
    };
}
