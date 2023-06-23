/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** Map
*/

#include "Map.hpp"
#include <iostream>

namespace GUI::Game {
    Map::Map(unsigned int x, unsigned int y): _size({static_cast<float>(x), static_cast<float>(y)})
    {
        std::shared_ptr<GUI::Game::Tile> tile;

        for (unsigned int i = 0; i < x; i++) {
            std::vector<std::shared_ptr<GUI::Game::Tile>> tmp;
            for (unsigned int j = 0; j < y; j++) {
                tile = std::make_shared<GUI::Game::Tile>((Vector2){static_cast<float>(i), static_cast<float>(j)}, (Vector3){static_cast<float>(i) - static_cast<float>(x) / 2 + 0.5f, 0, static_cast<float>(j) - static_cast<float>(y) / 2 + 0.5f});
                tmp.push_back(tile);
            }
            _tiles.push_back(tmp);
        }
    }

    void Map::resize(unsigned int x, unsigned int y)
    {
        std::shared_ptr<GUI::Game::Tile> tile;

        _size.x = x;
        _size.y = y;
        _tiles.clear();
        for (unsigned int i = 0; i < x; i++) {
            std::vector<std::shared_ptr<GUI::Game::Tile>> tmp;
            for (unsigned int j = 0; j < y; j++) {
                tile = std::make_shared<GUI::Game::Tile>((Vector2){static_cast<float>(i), static_cast<float>(j)}, (Vector3){static_cast<float>(i) - static_cast<float>(x) / 2 + 0.5f, 0, static_cast<float>(j) - static_cast<float>(y) / 2 + 0.5f});
                tmp.push_back(tile);
            }
            _tiles.push_back(tmp);
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

    std::shared_ptr<GUI::Game::Tile> Map::getTile(unsigned int x, unsigned int y) const
    {
        for (auto &y_tiles : _tiles) {
            for (auto &tile : y_tiles) {
                if (tile->getTileIndexes().x == x && tile->getTileIndexes().y == y) {
                    return tile;
                }
            }
        }
        return nullptr;
    }

    std::shared_ptr<std::vector<std::shared_ptr<GUI::Game::ICatchable>>> Map::getCatchables(void)
    {
        std::shared_ptr<std::vector<std::shared_ptr<GUI::Game::ICatchable>>> catchables = std::make_shared<std::vector<std::shared_ptr<GUI::Game::ICatchable>>>();

        for (auto &y_tiles : _tiles) {
            for (auto &tile : y_tiles) {
                catchables->push_back(tile);
            }
        }
        return catchables;
    }
}
