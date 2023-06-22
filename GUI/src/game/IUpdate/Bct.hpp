/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** Bct
*/

#pragma once
#include "IUpdate.hpp"
#include "StringUtils.hpp"
#include <iostream>

namespace GUI::Game {
    /**
     * @brief Bct class is used to update the map
     */
    class Bct : public IUpdate{
        public:
            Bct(std::shared_ptr<GUI::Game::GameState> gameState,
                std::shared_ptr<GUI::Network::IOPooledClient> client,
                std::string command)
            {
                _gameState = gameState;
                _client = client;
                _command = command;
            }
            ~Bct() = default;

            /**
             * @brief update the map
             *
             * @return ** void
             */
            void update()
            {
                std::shared_ptr<GUI::Game::Tile> tile = nullptr;
                std::vector<std::string> args = GUI::Utils::StringUtils::split(_command, " ");

                if (args.size() != 10) {
                    std::cerr << "Error: Bct: invalid number of arguments" << std::endl;
                    return;
                }
                try {
                    tile = _gameState->getMap()->getTile(std::stoi(args[1]), std::stoi(args[2]));
                } catch (std::exception &e) {
                    std::cerr << "Error: Bct: " << e.what() << std::endl;
                    return;
                }
                if (tile == nullptr) {
                    std::cerr << "Error: Bct: tile not found: x: " << std::to_string(std::stoi(args[1])) << " y: " << std::to_string(std::stoi(args[2])) << std::endl;
                    return;
                }
                tile->setFoodQuantity(std::stoi(args[3]));
                tile->setLinemateQuantity(std::stoi(args[4]));
                tile->setDeraumereQuantity(std::stoi(args[5]));
                tile->setSiburQuantity(std::stoi(args[6]));
                tile->setMendianeQuantity(std::stoi(args[7]));
                tile->setPhirasQuantity(std::stoi(args[8]));
                tile->setThystameQuantity(std::stoi(args[9]));
            }

        private:
    };
}
