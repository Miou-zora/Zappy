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

namespace GUI::Game {
    /**
     * @brief GameCore class
     *  This class is the core of the game
     *  It contains the scene and the client and the data of the game
     */
    class GameCore {
        public:
            GameCore(void);
            GameCore(std::shared_ptr<GUI::Graphic::Scene> scene, std::shared_ptr<GUI::Network::IOPooledClient> client);
            ~GameCore(void) = default;

            /**
             * @brief Update the game
             *
             * @param timeElapsed
             */
            void update(const double &timeElapsed);

            /**
             * @brief Set the Scene object
             *
             * @param scene
             */
            void setScene(std::shared_ptr<GUI::Graphic::Scene> scene) { _scene = scene; };

            /**
             * @brief Set the Client object
             *
             * @param client
             */
            void setClient(std::shared_ptr<GUI::Network::IOPooledClient> client) { _client = client; };

            /**
             * @brief Get the Scene object
             *
             * @return std::shared_ptr<GUI::Graphic::Scene>
             */
            std::shared_ptr<GUI::Graphic::Scene> getScene(void) const { return _scene; };
            
            /**
             * @brief Get the Client object
             *
             * @return std::shared_ptr<GUI::Network::IOPooledClient>
             */
            std::shared_ptr<GUI::Network::IOPooledClient> getClient(void) const { return _client; };

        private:
            std::shared_ptr<GUI::Graphic::Scene> _scene;
            std::shared_ptr<GUI::Network::IOPooledClient> _client;
            std::shared_ptr<GUI::Game::GameSettings> _settings;
            GUI::Game::Factory _factory;

    };
}
