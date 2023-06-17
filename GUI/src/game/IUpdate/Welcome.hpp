/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** Welcome
*/

#pragma once
#include "IUpdate.hpp"
#include "IOPooledClient.hpp"
#include "Request.hpp"

namespace GUI::Game {
    /**
     * @brief Welcome class is used to update the game
     * 
     */
    class Welcome : public GUI::Game::IUpdate {
        public:
            Welcome(std::shared_ptr<GUI::Game::GameSettings> setting,
                    std::shared_ptr<GUI::Network::IOPooledClient> client,
                    std::shared_ptr<GUI::Graphic::Scene> scene,
                    std::string command)
            {
                _settings = setting;
                _client = client;
                _command = command;
                _scene = scene;
            }

            ~Welcome(void) = default;

            void update() override
            {
                std::shared_ptr<GUI::Network::Request> request = std::make_shared<GUI::Network::Request>("GRAPHIC");
                _client->addRequest(request);
            }

        private:
    };
}
