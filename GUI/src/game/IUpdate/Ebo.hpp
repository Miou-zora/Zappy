/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** Ebo
*/

#pragma once
#include "IUpdate.hpp"

namespace GUI::Game {
    class Ebo : public GUI::Game::IUpdate {
        public:
            Ebo(std::shared_ptr<GUI::Game::GameState> gameState,
                std::shared_ptr<GUI::Network::IOPooledClient> client,
                std::string command)
            {
                _gameState = gameState;
                _client = client;
                _command = command;
            }

            ~Ebo(void) = default;

            void update(void) override
            {
                std::vector<std::string> args = GUI::Utils::StringUtils::split(_command, " ");
                int id = 0;

                if (args.size() != 2 && args[0] != "ebo") {
                    std::cerr << "Error: Ebo: wrong command" << std::endl;
                    return;
                }
                try {
                    id = std::stoi(args[1]);
                } catch (std::exception &e) {
                    std::cerr << "Error: Ebo: stoi: " << e.what() << std::endl;
                    return;
                }

                for (auto it = _gameState->getEggs().begin(); it != _gameState->getEggs().end(); it++) {
                    if ((*it)->getId() == id) {
                        _gameState->getEggs().erase(it);
                        return;
                    }
                }
                std::cerr << "Error: Ebo: egg not found: " << id << std::endl;
            }
    };
}
