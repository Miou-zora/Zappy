/*
** EPITECH PROJECT, 2023
** GUI
** File description:
** Ppo
*/

#pragma once
#include "IUpdate.hpp"
#include "StringUtils.hpp"
namespace GUI::Game {
    class Ppo : public GUI::Game::IUpdate {
        public:
            Ppo(std::shared_ptr<GUI::Game::GameState> gameState,
                std::shared_ptr<GUI::Network::IOPooledClient> client,
                std::string command)
            {
                _gameState = gameState;
                _client = client;
                _command = command;
            }

            ~Ppo(void) = default;

            void update(void) override
            {
                std::vector<std::string> args = GUI::Utils::StringUtils::split(_command, " ");

                if (args.size() != 5) {
                    std::cerr << "Error: Ppo: wrong number of arguments" << std::endl;
                    return;
                }
                int id = std::stoi(args[1]);
                glm::uvec2 position = {std::stoi(args[2]), std::stoi(args[3])};
                Orientation orientation = static_cast<Orientation>(std::stoi(args[4]));
                _updatePlayer(id, position, orientation);
            }

        private:
            void _updatePlayer(int id, glm::uvec2 position, Orientation orientation)
            {
                for (auto &player : _gameState->getPlayers()) {
                    if (player->getId() == id) {
                        player->setPosition(position);
                        player->setOrientation(orientation);
                        return;
                    }
                }
                std::cerr << "Error: Ppo: player not found" << std::endl;
            }
    };
}
