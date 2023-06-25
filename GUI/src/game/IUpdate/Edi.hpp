/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** Edi
*/

#pragma once
#include "IUpdate.hpp"

namespace GUI::Game {
    class Edi : public GUI::Game::IUpdate {
        public:
            Edi(std::shared_ptr<GUI::Game::GameState> gameState,
                std::shared_ptr<GUI::Network::IOPooledClient> client,
                std::string command)
            {
                _gameState = gameState;
                _client = client;
                _command = command;
            }

            ~Edi(void) = default;

            void update(void) override
            {
                std::vector<std::string> args = GUI::Utils::StringUtils::split(_command, " ");
                int id = 0;

                if (args.size() != 2 && args[0] != "edi") {
                    std::cerr << "Error: Edi: wrong command" << std::endl;
                    return;
                }
                try {
                    id = std::stoi(args[1]);
                } catch (std::exception &e) {
                    std::cerr << "Error: Edi: stoi: " << e.what() << std::endl;
                    return;
                }

                for (auto it = _gameState->getEggs().begin(); it != _gameState->getEggs().end(); it++) {
                    if ((*it)->getId() == id) {
                        _gameState->getEggs().erase(it);
                        std::cout << "Egg " << id << " hatched" << std::endl;
                        return;
                    }
                }
                std::cerr << "Error: Edi: egg not found: " << id << std::endl;
            }
    };
}
