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
#include "Program.hpp"

namespace GUI::Game {
    class Map {
        public:
            Map(unsigned int x, unsigned int y);
            ~Map(void) = default;

            void resize(unsigned int x, unsigned int y);

            void update(void);
            void load(void);
            void render(std::shared_ptr<GUI::Graphic::Object::Camera> camera);

            std::shared_ptr<GUI::Game::Tile> getTile(unsigned int x, unsigned int y) const;

            void setProgram(std::shared_ptr<GUI::Graphic::Program> program);
            void loadProgram(void);

        private:
            glm::uvec2 _size;
            std::vector<std::vector<std::shared_ptr<GUI::Game::Tile>>> _tiles;
            std::shared_ptr<GUI::Graphic::Program> _program;
    };
}
