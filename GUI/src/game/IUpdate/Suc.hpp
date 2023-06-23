/*
** EPITECH PROJECT, 2023
** GUI
** File description:
** Suc
*/

#pragma once
#include "IUpdate.hpp"
#include "StringUtils.hpp"
#include <algorithm>
#include <iostream>

namespace GUI::Game {
    class Suc : public GUI::Game::IUpdate {
        public:
            Suc(std::shared_ptr<GUI::Game::GameState> gameState,
                std::shared_ptr<GUI::Network::IOPooledClient> client,
                std::string command)
            {
                _gameState = gameState;
                _client = client;
                _command = command;
            }

            ~Suc(void) = default;

            void update() override
            {
                std::vector<std::string> args = GUI::Utils::StringUtils::split(_command, " ");

                if (args.size() != 1) {
                    std::cerr << "Error: Suc command has wrong number of arguments" << std::endl;
                    return;
                }
                std::cout << "PERSO: INFO: YOU SEND AN INVALID COMMAND" << std::endl;
            }
    };
}
