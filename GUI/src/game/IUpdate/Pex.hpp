/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** Pex
*/

#pragma once
#include "IUpdate.hpp"
#include "ExpulsionEvent.hpp"

namespace GUI::Game {
    /**
     * @brief Pbc class is used to update the map size
     */
    class Pex : public GUI::Game::IUpdate {
        public:
            Pex(std::shared_ptr<GUI::Game::GameState> gameState,
                std::shared_ptr<GUI::Network::IOPooledClient> client,
                std::string command)
            {
                _gameState = gameState;
                _client = client;
                _command = command;
            }

            ~Pex(void) = default;

            void update() override
            {
                std::vector<std::string> args = GUI::Utils::StringUtils::split(_command, " ");
                std::shared_ptr<GUI::Game::Player> player = nullptr;
                Vector3 posOfExpulsion = {0, 0, 0};

                if (args.size() != 2 && args[0] != "pex") {
                    std::cerr << "Error: Pex: wrong command" << std::endl;
                    return;
                }
                try {
                    player = _getPlayerById(std::stoi(args[1]));
                } catch (std::exception &e) {
                    std::cerr << "Error: Pex: stoi: " << e.what() << std::endl;
                    return;
                }
                if (player == nullptr) {
                    std::cerr << "Error: Pex: player is nullptr" << std::endl;
                    return;
                }
                posOfExpulsion = player->getModel()->getPos();
                _gameState->getEventPool()->addEvent(std::make_shared<GUI::Game::ExpulsionEvent>(posOfExpulsion));
            }
        private:
            std::shared_ptr<GUI::Game::Player> _getPlayerById(int id)
            {
                for (auto &player : _gameState->getPlayers()) {
                    if (player->getId() == id) {
                        return player;
                    }
                }
                return nullptr;
            }
    };
}
