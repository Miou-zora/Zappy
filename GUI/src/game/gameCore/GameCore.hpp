/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** GameCore
*/

#pragma once
#include "GameSettings.hpp"
#include "Scene.hpp"
#include "Factory.hpp"
#include "IOPooledClient.hpp"
#include <functional>
#include "Map.hpp"
#include "GameState.hpp"

namespace GUI::Game {
    /**
     * @brief GameCore class
     *  This class is the core of the game
     *  It contains the scene and the client and the data of the game
     */
    class GameCore {
        public:
            GameCore(std::shared_ptr<GUI::Graphic::Scene> scene = nullptr, std::shared_ptr<GUI::Network::IOPooledClient> client = nullptr);
            ~GameCore(void) = default;

            /**
             * @brief Update the game
             *
             * @param timeElapsed
             */
            void update(const double &timeElapsed);

            /**
             * @brief Draw the game
             */
            void render(void);

            void init(void);

            /**
             * @brief Set the Client object
             *
             * @param client
             */
            void setClient(std::shared_ptr<GUI::Network::IOPooledClient> client) { _client = client; };

            /**
             * @brief Get the Client object
             *
             * @return std::shared_ptr<GUI::Network::IOPooledClient>
             */
            std::shared_ptr<GUI::Network::IOPooledClient> getClient(void) const { return _client; };

            /**
             * @brief Set the Scene object
             *
             * @param scene
             */
            void setGameState(std::shared_ptr<GUI::Game::GameState> gameState) { _gameState = gameState; };

            /**
             * @brief Get the Scene object
             *
             * @return std::shared_ptr<GUI::Graphic::Scene>
             */
            std::shared_ptr<GUI::Game::GameState> getGameState(void) const { return _gameState; };

        private:
            std::shared_ptr<GUI::Game::GameState> _gameState;
            std::shared_ptr<GUI::Network::IOPooledClient> _client;
            GUI::Game::Factory _factory;

    };
}
