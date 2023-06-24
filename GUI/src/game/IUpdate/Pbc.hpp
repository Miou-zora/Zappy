/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** Pbc
*/

#pragma once
#include "IUpdate.hpp"
#include <sstream>
#include "BroadcastEvent.hpp"

namespace GUI::Game {
    /**
     * @brief Pbc class is used to update the map size
     */
    class Pbc : public GUI::Game::IUpdate {
        public:
            Pbc(std::shared_ptr<GUI::Game::GameState> gameState,
                std::shared_ptr<GUI::Network::IOPooledClient> client,
                std::string command)
            {
                _gameState = gameState;
                _client = client;
                _command = command;
            }

            ~Pbc(void) = default;

            void update() override
            {
                std::vector<std::string> args = GUI::Utils::StringUtils::split(_command, " ");
                std::shared_ptr<GUI::Game::Tile> tile;
                Vector3 posOfBroadcast = {0, 0, 0};
                std::shared_ptr<GUI::Game::Player> player;
                std::string message = "";

                if (args.size() < 3) {
                    std::cerr << "Error: Pbc: wrong number of arguments" << std::endl;
                    return;
                }
                for (size_t i = 2; i < args.size(); i++) {
                    message += args[i];
                    if (i != args.size() - 1)
                        message += " ";
                }
                try {
                    player = _getPlayerById(std::stoi(args[1]));
                } catch (std::exception &e) {
                    std::cerr << "Error: Pbc: stoi: " << e.what() << std::endl;
                    return;
                }
                tile = _gameState->getMap()->getTile(player->getPosition().x, player->getPosition().y);
                if (tile == nullptr) {
                    std::cerr << "Error: Pie: tile is nullptr" << std::endl;
                    return;
                }
                posOfBroadcast = tile->getPos();
                posOfBroadcast.y += 2;
                _gameState->getEventPool()->addEvent(std::make_shared<GUI::Game::BroadcastEvent>(posOfBroadcast, message));
            }
        private:
            std::shared_ptr<GUI::Game::Player> _getPlayerById(int id)
            {
                for (auto &player : _gameState->getPlayers()) {
                    if (player->getId() == id)
                        return player;
                }
                return nullptr;
            }
    };
}
