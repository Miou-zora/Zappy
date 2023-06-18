/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** IUpdate
*/

#pragma once
#include "GameCore.hpp"
#include "IOPooledClient.hpp"
#include "GameState.hpp"
#include <string>

namespace GUI::Game {
    /**
     * @brief IUpdate class is used to update the game
     */
    class IUpdate {
        public:
            IUpdate() = default;
            ~IUpdate() = default;

            virtual void update() = 0;

        protected:
            std::shared_ptr<GUI::Game::GameState> _gameState;
            std::string _command;
            std::shared_ptr<GUI::Network::IOPooledClient> _client;
    };
}
