/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** Seg
*/

#pragma once
#include "IUpdate.hpp"
#include "StringUtils.hpp"

namespace GUI::Game {
    class Seg : public GUI::Game::IUpdate {
        public:
            Seg(std::shared_ptr<GUI::Game::GameState> gameState,
                std::shared_ptr<GUI::Network::IOPooledClient> client,
                std::string command)
            {
                _gameState = gameState;
                _client = client;
                _command = command;
            }

            ~Seg(void) = default;

            void update(void) override
            {
                std::vector<std::string> args = GUI::Utils::StringUtils::split(_command, " ");
                std::string teamName = "";
                std::shared_ptr<GUI::Game::Team> team = nullptr;

                if (args.size() != 2) {
                    std::cerr << "Error: Ppo: wrong number of arguments" << std::endl;
                    return;
                }
                teamName = args[1];
                team = _getTeamByName(teamName);
                if (team == nullptr) {
                    std::cerr << "Error: Ppo: team not found" << std::endl;
                    return;
                }
                std::cout << "Team " << teamName << " won the game !" << std::endl;
            }
        private:
            std::shared_ptr<GUI::Game::Team> _getTeamByName(std::string teamName)
            {
                for (auto &team : _gameState->getTeams()) {
                    if (team->getName() == teamName)
                        return team;
                }
                return nullptr;
            }
    };
}
