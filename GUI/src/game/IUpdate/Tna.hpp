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
                std::vector<std::shared_ptr<GUI::Game::Team>> &teams = _gameState->getTeams();
                for (auto &team : teams) {
                    if (*team == teamName) {
                        std::cerr << "Error: Tna: team name already exists" << std::endl;
                        return;
                    }
                }
                std::shared_ptr<GUI::Game::Team> newTeam = std::make_shared<GUI::Game::Team>(teamName, _findNotAlreadyTakenColor(teams));
                _gameState->getTeams().push_back(newTeam);
            }
        private:
            Color _findNotAlreadyTakenColor(std::vector<std::shared_ptr<GUI::Game::Team>> &teams)
            {
                std::vector<Color> colors = {BLUE, VIOLET, BROWN, GRAY, GOLD, LIME, LIGHTGRAY,
                    PINK, YELLOW, GREEN, SKYBLUE, PURPLE, BEIGE, DARKGRAY, MAROON, ORANGE, DARKGREEN,
                    DARKBLUE, DARKPURPLE, DARKBROWN};
                std::vector<Color> takenColors;

                for (auto &team : teams) {
                    takenColors.push_back(team->getColor());
                }
                for (auto &color : colors) {
                    if (!_isColorInArray(color, takenColors)) {
                        return color;
                    }
                }
                return BLUE;
            }

            bool _isColorInArray(Color color, std::vector<Color> &colors)
            {
                for (auto &colorInArray : colors) {
                    if (color == colorInArray) {
                        return true;
                    }
                }
                return false;
            }
    };
}
