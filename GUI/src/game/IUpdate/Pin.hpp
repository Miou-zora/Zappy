/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** Pin
*/

#pragma once
#include "IUpdate.hpp"
#include "StringUtils.hpp"

namespace GUI::Game {
    class Pin : public GUI::Game::IUpdate {
        public:
            Pin(std::shared_ptr<GUI::Game::GameState> gameState,
                std::shared_ptr<GUI::Network::IOPooledClient> client,
                std::string command)
            {
                _gameState = gameState;
                _client = client;
                _command = command;
            }

            ~Pin(void) = default;

            void update(void) override
            {
                std::vector<std::string> args = GUI::Utils::StringUtils::split(_command, " ");

                if (args.size() != 11) {
                    std::cerr << "Error: Pin: wrong number of arguments" << std::endl;
                    return;
                }
                _updatePlayer(args);
            }
        private:
            void _updatePlayer(const std::vector<std::string> &args)
            {
                int id = std::stoi(args[1]);
                Vector2 position = {static_cast<float>(std::stoi(args[2])), static_cast<float>(std::stoi(args[3]))};
                std::vector<int> inventory = {
                    std::stoi(args[4]),
                    std::stoi(args[5]),
                    std::stoi(args[6]),
                    std::stoi(args[7]),
                    std::stoi(args[8]),
                    std::stoi(args[9]),
                    std::stoi(args[10])
                };
                std::shared_ptr<GUI::Game::Player> playerToUpdate = nullptr;

                for (auto &player : _gameState->getPlayers()) {
                    if (player->getId() == id) {
                        playerToUpdate = player;
                        break;
                    }
                }
                if (playerToUpdate == nullptr) {
                    std::cerr << "Error: Pin: player not found" << std::endl;
                    return;
                }
                playerToUpdate->setPosition(position);
                playerToUpdate->getFoodContainer()->setQuantity(inventory[0]);
                playerToUpdate->getLinemateContainer()->setQuantity(inventory[1]);
                playerToUpdate->getDeraumereContainer()->setQuantity(inventory[2]);
                playerToUpdate->getSiburContainer()->setQuantity(inventory[3]);
                playerToUpdate->getMendianeContainer()->setQuantity(inventory[4]);
                playerToUpdate->getPhirasContainer()->setQuantity(inventory[5]);
                playerToUpdate->getThystameContainer()->setQuantity(inventory[6]);
            }
    };
}
