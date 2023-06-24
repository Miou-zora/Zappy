/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** Sst
*/

#pragma once
#include "IUpdate.hpp"

namespace GUI::Game {
    class Sst : public GUI::Game::IUpdate {
        public:
            Sst(std::shared_ptr<GUI::Game::GameState> gameState,
                std::shared_ptr<GUI::Network::IOPooledClient> client,
                std::string command)
            {
                _gameState = gameState;
                _client = client;
                _command = command;
            }

            ~Sst(void) = default;

            void update(void) override
            {
                std::vector<std::string> args = GUI::Utils::StringUtils::split(_command, " ");
                int time = 0;

                if (args.size() != 2 && args[0] != "sst") {
                    std::cerr << "Error: invalid sst command" << std::endl;
                    return;
                }
                try {
                    time = std::stoi(args[1]);
                } catch (std::exception &e) {
                    std::cerr << "Error: invalid parameter" << std::endl;
                }
                _gameState->getSettings()->setTimeUnit(time);
            }
    };
}
