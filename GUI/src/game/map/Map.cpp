/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** Map
*/

#include "Map.hpp"
#include <iostream>

namespace GUI::Game {
    Map::Map(unsigned int x, unsigned int y): _size(x, y)
    {
        std::shared_ptr<GUI::Game::Tile> tile;

        for (unsigned int i = 0; i < x; i++) {
            std::vector<std::shared_ptr<GUI::Game::Tile>> tmp;
            for (unsigned int j = 0; j < y; j++) {
                tile = std::make_shared<GUI::Game::Tile>(i, j);
                tile->setScale(glm::vec3(0.45, 0.45, 0.45));
                tmp.push_back(tile);
            }
            _tiles.push_back(tmp);
        }
    }

    void Map::resize(unsigned int x, unsigned int y)
    {
        std::shared_ptr<GUI::Game::Tile> tile;

        _size = glm::uvec2(x, y);
        _tiles.clear();
        for (unsigned int i = 0; i < x; i++) {
            std::vector<std::shared_ptr<GUI::Game::Tile>> tmp;
            for (unsigned int j = 0; j < y; j++) {
                tile = std::make_shared<GUI::Game::Tile>(i, j);
                tile->setScale(glm::vec3(0.45, 0.45, 0.45));
                tmp.push_back(tile);
            }
            _tiles.push_back(tmp);
        }
        load();
        setProgram(_program);
        loadProgram();
        update();
    }

    void Map::load(void)
    {
        for (auto &y_tiles : _tiles) {
            for (auto &tile : y_tiles) {
                tile->load();
            }
        }
    }

    void Map::update(void)
    {
        for (auto &y_tiles : _tiles) {
            for (auto &tile : y_tiles) {
                tile->update();
            }
        }
    }

    void Map::render(std::shared_ptr<GUI::Graphic::Object::Camera> camera)
    {
        for (auto &y_tiles : _tiles) {
            for (auto &tile : y_tiles) {
                tile->draw(camera);
            }
        }
    }

    void Map::setProgram(std::shared_ptr<GUI::Graphic::Program> program)
    {
        _program = program;
        for (auto &y_tiles : _tiles) {
            for (auto &tile : y_tiles) {
                tile->setProgram(program);
            }
        }
    }

    void Map::loadProgram(void)
    {
        for (auto &y_tiles : _tiles) {
            for (auto &tile : y_tiles) {
                tile->loadProgram();
            }
        }
    }

    std::shared_ptr<GUI::Game::Tile> Map::getTile(unsigned int x, unsigned int y) const
    {
        for (auto &y_tiles : _tiles) {
            for (auto &tile : y_tiles) {
                if (tile->getPos().x == x && tile->getPos().z == y) {
                    return tile;
                }
            }
        }
        return nullptr;
    }
}
