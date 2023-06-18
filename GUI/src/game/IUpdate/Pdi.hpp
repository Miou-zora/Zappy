/*
** EPITECH PROJECT, 2023
** GUI
** File description:
** Pdi
*/

#pragma once
#include "IUpdate.hpp"

namespace GUI::Game {
    class Pdi : public GUI::Game::IUpdate {
        public:
            Pdi(std::shared_ptr<GUI::Game::GameState> gameState,
                std::shared_ptr<GUI::Network::IOPooledClient> client,
                std::string command)
            {
                _gameState = gameState;
                _client = client;
                _command = command;
            }

            ~Pdi(void) = default;

            void update(void) override
            {
                std::vector<std::string> args = GUI::Utils::StringUtils::split(_command, " ");
                int id = std::stoi(args[1]);

                for (auto it = _gameState->getPlayers().begin(); it != _gameState->getPlayers().end(); it++) {
                    if ((*it)->getId() == id) {
                        _gameState->getPlayers().erase(it);
                        break;
                    }
                }
            }
    };
}
