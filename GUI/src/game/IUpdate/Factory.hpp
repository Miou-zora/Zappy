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
#include "Tna.hpp"
#include "Pnw.hpp"
#include "Pdi.hpp"
#include "Pgt.hpp"
#include "Ppo.hpp"
#include "Pin.hpp"
#include "Pdr.hpp"
#include "Pic.hpp"
#include "Plv.hpp"
#include "Pie.hpp"
#include "Sbp.hpp"
#include "Suc.hpp"
#include "Smg.hpp"
#include "Pbc.hpp"
#include "Sst.hpp"
#include "Seg.hpp"
#include "Pex.hpp"
#include "Enw.hpp"
#include "Pfk.hpp"
#include "Edi.hpp"
#include "Ebo.hpp"
#include "GameState.hpp"
#include <map>
#include <functional>
#include <memory>

namespace GUI::Game {

    /**
     * @brief Factory class is used to create the right update class
     */
    class Factory {
        public:
            Factory(void) = default;
            ~Factory(void) = default;

            /**
             * @brief create the right update class depending on the command
             *
             * @param settings  GUI::Game::GameState
             * @param client    GUI::Network::IOPooledClient
             * @param command   std::string
             * @return ** std::shared_ptr<GUI::Game::IUpdate>
             */
            std::shared_ptr<GUI::Game::IUpdate> create(std::shared_ptr<GUI::Game::GameState> gameState,
                                                        std::shared_ptr<GUI::Network::IOPooledClient> client,
                                                        std::string command)
            {
                std::string command_key = GUI::Utils::StringUtils::try_split_command(command);
                if (_map.find(command_key) == _map.end()) {
                    throw GUI::GameException("Error: command not found");
                }
                return _map[command_key](gameState, client, command);
            }

        private:
            std::map<std::string, std::function<std::shared_ptr<GUI::Game::IUpdate>(std::shared_ptr<GUI::Game::GameState>,
                                                        std::shared_ptr<GUI::Network::IOPooledClient>,
                                                        std::string)>> _map = {
                {"WELCOME", [](std::shared_ptr<GUI::Game::GameState> gameState,
                                std::shared_ptr<GUI::Network::IOPooledClient> client,
                                std::string command) {
                    return std::make_shared<GUI::Game::Welcome>(gameState, client, command);
                }},
                {"sgt", [](std::shared_ptr<GUI::Game::GameState> gameState,
                            std::shared_ptr<GUI::Network::IOPooledClient> client,
                            std::string command) {
                    return std::make_shared<GUI::Game::Sgt>(gameState ,client, command);
                }},
                {"msz", [](std::shared_ptr<GUI::Game::GameState> gameState,
                                std::shared_ptr<GUI::Network::IOPooledClient> client,
                                std::string command) {
                    return std::make_shared<GUI::Game::Msz>(gameState ,client, command);
                }},
                {"bct", [](std::shared_ptr<GUI::Game::GameState> gameState,
                                std::shared_ptr<GUI::Network::IOPooledClient> client,
                                std::string command) {
                    return std::make_shared<GUI::Game::Bct>(gameState ,client, command);
                }},
                {"tna", [](std::shared_ptr<GUI::Game::GameState> gameState,
                                std::shared_ptr<GUI::Network::IOPooledClient> client,
                                std::string command) {
                    return std::make_shared<GUI::Game::Tna>(gameState ,client, command);
                }},
                {"pnw", [](std::shared_ptr<GUI::Game::GameState> gameState,
                                std::shared_ptr<GUI::Network::IOPooledClient> client,
                                std::string command) {
                    return std::make_shared<GUI::Game::Pnw>(gameState ,client, command);
                }},
                {"pdi", [](std::shared_ptr<GUI::Game::GameState> gameState,
                                std::shared_ptr<GUI::Network::IOPooledClient> client,
                                std::string command) {
                    return std::make_shared<GUI::Game::Pdi>(gameState ,client, command);
                }},
                {"pgt", [](std::shared_ptr<GUI::Game::GameState> gameState,
                                std::shared_ptr<GUI::Network::IOPooledClient> client,
                                std::string command) {
                    return std::make_shared<GUI::Game::Pgt>(gameState ,client, command);
                }},
                {"ppo", [](std::shared_ptr<GUI::Game::GameState> gameState,
                                std::shared_ptr<GUI::Network::IOPooledClient> client,
                                std::string command) {
                    return std::make_shared<GUI::Game::Ppo>(gameState ,client, command);
                }},
                {"pin", [](std::shared_ptr<GUI::Game::GameState> gameState,
                                std::shared_ptr<GUI::Network::IOPooledClient> client,
                                std::string command) {
                    return std::make_shared<GUI::Game::Pin>(gameState ,client, command);
                }},
                {"pdr", [](std::shared_ptr<GUI::Game::GameState> gameState,
                                std::shared_ptr<GUI::Network::IOPooledClient> client,
                                std::string command) {
                    return std::make_shared<GUI::Game::Pdr>(gameState ,client, command);
                }},
                {"pic", [](std::shared_ptr<GUI::Game::GameState> gameState,
                            std::shared_ptr<GUI::Network::IOPooledClient> client,
                            std::string command) {
                    return std::make_shared<GUI::Game::Pic>(gameState ,client, command);
                }},
                {"plv", [](std::shared_ptr<GUI::Game::GameState> gameState,
                            std::shared_ptr<GUI::Network::IOPooledClient> client,
                            std::string command) {
                    return std::make_shared<GUI::Game::Plv>(gameState ,client, command);
                }},
                {"pie", [](std::shared_ptr<GUI::Game::GameState> gameState,
                            std::shared_ptr<GUI::Network::IOPooledClient> client,
                            std::string command) {
                    return std::make_shared<GUI::Game::Pie>(gameState ,client, command);
                }},
                {"sbp", [](std::shared_ptr<GUI::Game::GameState> gameState,
                            std::shared_ptr<GUI::Network::IOPooledClient> client,
                            std::string command) {
                    return std::make_shared<GUI::Game::Sbp>(gameState ,client, command);
                }},
                {"suc", [](std::shared_ptr<GUI::Game::GameState> gameState,
                            std::shared_ptr<GUI::Network::IOPooledClient> client,
                            std::string command) {
                    return std::make_shared<GUI::Game::Suc>(gameState ,client, command);
                }},
                {"smg", [](std::shared_ptr<GUI::Game::GameState> gameState,
                            std::shared_ptr<GUI::Network::IOPooledClient> client,
                            std::string command) {
                    return std::make_shared<GUI::Game::Smg>(gameState ,client, command);
                }},
                {"pbc", [](std::shared_ptr<GUI::Game::GameState> gameState,
                            std::shared_ptr<GUI::Network::IOPooledClient> client,
                            std::string command) {
                    return std::make_shared<GUI::Game::Pbc>(gameState ,client, command);
                }},
                {"sst", [](std::shared_ptr<GUI::Game::GameState> gameState,
                            std::shared_ptr<GUI::Network::IOPooledClient> client,
                            std::string command) {
                    return std::make_shared<GUI::Game::Pbc>(gameState ,client, command);
                }},
                {"seg", [](std::shared_ptr<GUI::Game::GameState> gameState,
                            std::shared_ptr<GUI::Network::IOPooledClient> client,
                            std::string command) {
                    return std::make_shared<GUI::Game::Seg>(gameState ,client, command);
                }},
                {"pex", [](std::shared_ptr<GUI::Game::GameState> gameState,
                            std::shared_ptr<GUI::Network::IOPooledClient> client,
                            std::string command) {
                    return std::make_shared<GUI::Game::Pex>(gameState ,client, command);
                }},
                {"enw", [](std::shared_ptr<GUI::Game::GameState> gameState,
                            std::shared_ptr<GUI::Network::IOPooledClient> client,
                            std::string command) {
                    return std::make_shared<GUI::Game::Enw>(gameState ,client, command);
                }},
                {"pfk", [](std::shared_ptr<GUI::Game::GameState> gameState,
                            std::shared_ptr<GUI::Network::IOPooledClient> client,
                            std::string command) {
                    return std::make_shared<GUI::Game::Pfk>(gameState ,client, command);
                }},
                {"edi", [](std::shared_ptr<GUI::Game::GameState> gameState,
                            std::shared_ptr<GUI::Network::IOPooledClient> client,
                            std::string command) {
                    return std::make_shared<GUI::Game::Pfk>(gameState ,client, command);
                }},
                {"ebo", [](std::shared_ptr<GUI::Game::GameState> gameState,
                            std::shared_ptr<GUI::Network::IOPooledClient> client,
                            std::string command) {
                    return std::make_shared<GUI::Game::Ebo>(gameState ,client, command);
                }},
           };
    };
}
