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
            Msz(std::shared_ptr<GUI::Game::GameSettings> settings,
            std::shared_ptr<GUI::Network::IOPooledClient> client,
            std::shared_ptr<GUI::Graphic::Scene> scene,
            std::string command)
            {
                _settings = settings;
                _client = client;
                _command = command;
                _scene = scene;
            }

            ~Msz(void) = default;

            void update() override
            {
                std::string size = _command.substr(4);
                std::string x = "";
                std::string y = "";
                bool is_x = true;

                for (std::size_t i = 0; i < size.size(); i++) {
                    if (size[i] == ' ') {
                        is_x = false;
                        continue;
                    }
                    if (is_x)
                        x += size[i];
                    else
                        y += size[i];
                }
                _settings->setMapSize(std::stoi(x), std::stoi(y));
            }

        private:
    };
}
