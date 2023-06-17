/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** sgt
*/

#pragma once
#include "IUpdate.hpp"
#include "IOPooledClient.hpp"
#include "Request.hpp"

namespace GUI::Game {
    /**
     * @brief Sgt class is used to update the time
     * 
     */
    class Sgt : public GUI::Game::IUpdate {
        public:
            Sgt(std::shared_ptr<GUI::Game::GameSettings> setting,
                std::shared_ptr<GUI::Network::IOPooledClient> client,
                std::shared_ptr<GUI::Graphic::Scene> scene,
                std::string command)
            {
                _settings = setting;
                _client = client;
                _command = command;
                _scene = scene;
            }

            ~Sgt(void) = default;

            /**
             * @brief update the time
             * 
             * @return ** void 
             */
            void update() override
            {
                std::string time = _command.substr(4);
                _settings->setTimeUnit(std::stoi(time));
            }
    };
}