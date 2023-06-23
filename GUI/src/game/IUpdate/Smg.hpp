/*
** EPITECH PROJECT, 2023
** GUI
** File description:
** Smg
*/

#pragma once
#include "IUpdate.hpp"

namespace GUI::Game {
    class Smg : public GUI::Game::IUpdate {
        public:
            Smg(std::shared_ptr<GUI::Game::GameState> gameState,
                std::shared_ptr<GUI::Network::IOPooledClient> client,
                std::string command)
            {
                _gameState = gameState;
                _client = client;
                _command = command;
            }

            ~Smg(void) = default;

            void update(void) override
            {
                std::vector<std::string> args = GUI::Utils::StringUtils::split(_command, " ");
                std::string message = "";

                if (args.size() < 2) {
                    std::cerr << "Error: Smg: wrong number of arguments" << std::endl;
                    return;
                }
                for (size_t i = 1; i < args.size(); i++) {
                    message += args[i];
                    if (i != args.size() - 1)
                        message += " ";
                }
                std::cout << "PERSO: INFO: MESSAGE RECEIVED: " << message << std::endl;
            }
    };
}
