/*
** EPITECH PROJECT, 2023
** GUI
** File description:
** Pnw
*/

#pragma once
#include "IUpdate.hpp"

namespace GUI::Game {
    class Pnw : public GUI::Game::IUpdate {
        public:
            Pnw(std::shared_ptr<GUI::Game::GameState> gameState,
                std::shared_ptr<GUI::Network::IOPooledClient> client,
                std::string command)
            {
                _gameState = gameState;
                _client = client;
                _command = command;
            }

            ~Pnw(void) = default;

            void update(void) override
            {
                std::vector<std::string> args = GUI::Utils::StringUtils::split(_command, " ");
                std::shared_ptr<GUI::Game::Player> newPlayer = nullptr;
                int id = std::stoi(args[1]);
                Vector2 position = {static_cast<float>(std::stoi(args[2])), static_cast<float>(std::stoi(args[3]))};
                Orientation orientation = static_cast<Orientation>(std::stoi(args[4]));
                int level = std::stoi(args[5]);
                std::string teamName = args[6];

                for (auto &player : _gameState->getPlayers()) {
                    if (player->getId() == id) {
                        std::cerr << "Error: Pnw: player already exists" << std::endl;
                        return;
                    }
                }
                newPlayer = std::make_shared<GUI::Game::Player>(teamName, id, position, orientation, level);
                newPlayer->setPositionDiff({- _gameState->getMap()->getSize().x / 2 + 0.5f, - _gameState->getMap()->getSize().y / 2 + 0.5f});
                *(newPlayer->getFoodContainer()) = 9;
                _gameState->getPlayers().push_back(newPlayer);
            }
    };
}
