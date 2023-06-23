/*
** EPITECH PROJECT, 2023
** GUI
** File description:
** Sbp
*/

#pragma once
#include "IUpdate.hpp"
#include "StringUtils.hpp"
#include "Tile.hpp"
#include <map>

namespace GUI::Game {
    class Sbp : public GUI::Game::IUpdate {
        public:
            Sbp(std::shared_ptr<GUI::Game::GameState> gameState,
                std::shared_ptr<GUI::Network::IOPooledClient> client,
                std::string command)
            {
                _gameState = gameState;
                _client = client;
                _command = command;
            }

            ~Sbp(void) = default;

            void update(void) override
            {
                std::vector<std::string> args = GUI::Utils::StringUtils::split(_command, " ");

                if (args.size() != 1) {
                    std::cerr << "Error: Sbp: wrong number of arguments" << std::endl;
                    return;
                }
                std::cout << "PERSO: INFO: YOU SEND A VALID COMMAND WITH BAD PARAMETER" << std::endl;
            }
    };
}
