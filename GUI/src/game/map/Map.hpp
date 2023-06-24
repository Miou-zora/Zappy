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
#include "Player.hpp"

namespace GUI::Game {
    class Map {
        public:
            Map(unsigned int x, unsigned int y, const std::vector<std::shared_ptr<GUI::Game::Player>> &players);
            ~Map(void) = default;

            void resize(unsigned int x, unsigned int y);

            void update(void);
            void render(std::shared_ptr<GUI::Graphic::Object::Camera> camera);

            std::shared_ptr<GUI::Game::Tile> getTile(unsigned int x, unsigned int y) const;

            Vector2 getSize(void) const {return _size; };

            std::shared_ptr<std::vector<std::shared_ptr<GUI::Game::ICatchable>>> getCatchables(void);

        private:
            Vector2 _size;
            std::vector<std::vector<std::shared_ptr<GUI::Game::Tile>>> _tiles;
            const std::vector<std::shared_ptr<GUI::Game::Player>> &_players;
    };
}
