/*
** EPITECH PROJECT, 2023
** GUI
** File description:
** Pdr
*/

#pragma once
#include "IUpdate.hpp"

namespace GUI::Game {
    class Pdr : public GUI::Game::IUpdate {
        public:
            Pdr(std::shared_ptr<GUI::Game::GameState> gameState,
                std::shared_ptr<GUI::Network::IOPooledClient> client,
                std::string command)
            {
                _gameState = gameState;
                _client = client;
                _command = command;
            }

            ~Pdr(void) = default;

            void update(void) override
            {
                std::vector<std::string> args = GUI::Utils::StringUtils::split(_command, " ");
                std::shared_ptr<GUI::Game::Player> player = nullptr;
                std::shared_ptr<GUI::Game::Tile> tile = nullptr;

                if (args.size() != 3) {
                    std::cerr << "Error: Pdr: wrong number of arguments" << std::endl;
                    return;
                }
                player = _findPlayerById(std::stoi(args[1]));
                tile = _gameState->getMap()->getTile(player->getPosition().x, player->getPosition().y);
                if (!player || !tile) {
                    std::cerr << "Error: Pdr: player or tile not found" << std::endl;
                    return;
                }
            }
        private:
            std::shared_ptr<GUI::Game::Player> _findPlayerById(int id)
            {
                for (auto &player : _gameState->getPlayers()) {
                    if (player->getId() == id) {
                        return player;
                    }
                }
                return nullptr;
            }
    };
}
