/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** Msz
*/

#pragma once
#include "IUpdate.hpp"
#include "IOPooledClient.hpp"
#include "Request.hpp"
#include <iostream>
#include <sstream>

namespace GUI::Game {
    /**
     * @brief Msz class is used to update the map size
     * 
     */
    class Msz : public GUI::Game::IUpdate {
        public:
            Msz(std::shared_ptr<GUI::Game::GameState> gameState,
                std::shared_ptr<GUI::Network::IOPooledClient> client,
                std::string command)
            {
                _gameState = gameState;
                _client = client;
                _command = command;
            }

            ~Msz(void) = default;

            void update() override
            {
                std::string size = _command.substr(4);
                std::stringstream ss(size);
                unsigned int x = 0;
                unsigned int y = 0;

                ss >> x;
                ss >> y;
                _gameState->getSettings()->setMapSize(x, y);
                _gameState->getMap()->resize(x, y);
            }

        private:
    };
}
