/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** Factory
*/

#pragma once
#include "StringUtils.hpp"
#include "IUpdate.hpp"
#include "Welcome.hpp"
#include "IOPooledClient.hpp"
#include "ErrorManagement.hpp"
#include "Sgt.hpp"
#include "Msz.hpp"
#include "Bct.hpp"
#include "Scene.hpp"
#include "GameSettings.hpp"
#include <map>
#include <functional>
#include <memory>

namespace GUI::Game {

    /**
     * @brief Factory class is used to create the right update class
     * 
     */
    class Factory {
        public:
            Factory(void) = default;
            ~Factory(void) = default;

            /**
             * @brief create the right update class depending on the command
             * 
             * @param settings  GUI::Game::GameSettings
             * @param client    GUI::Network::IOPooledClient
             * @param scene     GUI::Graphic::Scene
             * @param command   std::string
             * @return ** std::shared_ptr<GUI::Game::IUpdate> 
             */
            std::shared_ptr<GUI::Game::IUpdate> create(std::shared_ptr<GUI::Game::GameSettings> settings,
                                                        std::shared_ptr<GUI::Network::IOPooledClient> client,
                                                        std::shared_ptr<GUI::Graphic::Scene> scene,
                                                        std::string command)
            {
                std::string command_key = GUI::Utils::StringUtils::try_split_command(command);
                if (_map.find(command_key) == _map.end()) {
                    throw GUI::GameException("Error: command not found");
                }
                return _map[command_key](settings, client, scene, command);
            }

        private:
            std::map<std::string, std::function<std::shared_ptr<GUI::Game::IUpdate>(std::shared_ptr<GUI::Game::GameSettings>,
                                                std::shared_ptr<GUI::Network::IOPooledClient>,
                                                std::shared_ptr<GUI::Graphic::Scene>,
                                                std::string)>> _map = {
                {"WELCOME", [](std::shared_ptr<GUI::Game::GameSettings> settings,
                                std::shared_ptr<GUI::Network::IOPooledClient> client,
                                std::shared_ptr<GUI::Graphic::Scene> scene,
                                std::string command) {
                    return std::make_shared<GUI::Game::Welcome>(settings, client, scene, command);
                }},
                {"sgt", [](std::shared_ptr<GUI::Game::GameSettings> settings,
                            std::shared_ptr<GUI::Network::IOPooledClient> client,
                            std::shared_ptr<GUI::Graphic::Scene> scene,
                            std::string command) {
                    return std::make_shared<GUI::Game::Sgt>(settings, client, scene, command);
                }},
                {"msz", [](std::shared_ptr<GUI::Game::GameSettings> settings,
                            std::shared_ptr<GUI::Network::IOPooledClient> client,
                            std::shared_ptr<GUI::Graphic::Scene> scene,
                            std::string command) {
                    return std::make_shared<GUI::Game::Msz>(settings, client, scene, command);
                }},
                {"bct", [](std::shared_ptr<GUI::Game::GameSettings> settings,
                            std::shared_ptr<GUI::Network::IOPooledClient> client,
                            std::shared_ptr<GUI::Graphic::Scene> scene,
                            std::string command) {
                    return std::make_shared<GUI::Game::Bct>(settings, client, scene, command);
                }},
            };
    };
}
