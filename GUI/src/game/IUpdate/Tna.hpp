/*
** EPITECH PROJECT, 2023
** GUI
** File description:
** Tna
*/

#pragma once
#include "IUpdate.hpp"
#include "StringUtils.hpp"
#include <algorithm>
#include <iostream>

namespace GUI::Game {
    class Tna : public GUI::Game::IUpdate {
        public:
            Tna(std::shared_ptr<GUI::Game::GameState> gameState,
                std::shared_ptr<GUI::Network::IOPooledClient> client,
                std::string command)
            {
                _gameState = gameState;
                _client = client;
                _command = command;
            }

            ~Tna(void) = default;

            void update() override
            {
                std::vector<std::string> args = GUI::Utils::StringUtils::split(_command, " ");
                std::string teamName = "";

                if (args.size() != 2) {
                    std::cerr << "Error: Tna command has wrong number of arguments" << std::endl;
                    return;
                }
                teamName = args[1];
                std::vector<std::string> &teams = _gameState->getTeamNames();
                if (std::find(teams.begin(), teams.end(), teamName) == teams.end()) {
                    teams.push_back(teamName);
                }
                else {
                    std::cerr << "Error: Tna: team name already exists" << std::endl;
                    return;
                }
            }
    };
}
