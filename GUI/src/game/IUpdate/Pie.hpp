/*
** EPITECH PROJECT, 2023
** GUI
** File description:
** Pie
*/

#pragma once
#include "IUpdate.hpp"
#include "StringUtils.hpp"
#include "Tile.hpp"
#include <map>
#include "IncantationEvent.hpp"

namespace GUI::Game {
    class Pie : public GUI::Game::IUpdate {
        public:
            Pie(std::shared_ptr<GUI::Game::GameState> gameState,
                std::shared_ptr<GUI::Network::IOPooledClient> client,
                std::string command)
            {
                _gameState = gameState;
                _client = client;
                _command = command;
            }

            ~Pie(void) = default;

            void update(void) override
            {
                std::vector<std::string> args = GUI::Utils::StringUtils::split(_command, " ");
                std::size_t x = 0;
                std::size_t y = 0;
                bool result = false;
                int incantationLevel = 0;
                std::shared_ptr<GUI::Game::Tile> tile;
                Vector3 posOfIncantationBillboard = {0, 0, 0};

                if (args.size() != 4) {
                    std::cerr << "Error: Pie: wrong number of arguments" << std::endl;
                    return;
                }
                try {
                    x = std::stoi(args[1]);
                    y = std::stoi(args[2]);
                    result = std::stoi(args[3]);
                } catch (std::exception &e) {
                    std::cerr << "Error: Pie: stoi: " << e.what() << std::endl;
                    return;
                }
                for (auto &incantation : _gameState->getIncantations()) {
                    if (incantation->getPosX() == x && incantation->getPosY() == y) {
                        incantation->finish(result);
                        incantationLevel = incantation->getLevel();
                    }
                }
                if (result) {
                    tile = _gameState->getMap()->getTile(x, y);
                    if (tile == nullptr) {
                        std::cerr << "Error: Pie: tile is nullptr" << std::endl;
                        return;
                    }
                    posOfIncantationBillboard = tile->getPos();
                    posOfIncantationBillboard.y += 2;
                    _gameState->getEventPool()->addEvent(std::make_shared<GUI::Game::IncantationEvent>(incantationLevel, posOfIncantationBillboard));
                }
            }
    };
}
