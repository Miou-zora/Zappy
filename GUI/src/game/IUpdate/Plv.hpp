/*
** EPITECH PROJECT, 2023
** GUI
** File description:
** Plv
*/

#pragma once
#include "IUpdate.hpp"
#include "StringUtils.hpp"
#include "Tile.hpp"
#include <map>

namespace GUI::Game {
    class Plv : public GUI::Game::IUpdate {
        public:
            Plv(std::shared_ptr<GUI::Game::GameState> gameState,
                std::shared_ptr<GUI::Network::IOPooledClient> client,
                std::string command)
            {
                _gameState = gameState;
                _client = client;
                _command = command;
            }

            ~Plv(void) = default;

            void update(void) override
            {
                std::vector<std::string> args = GUI::Utils::StringUtils::split(_command, " ");
                std::shared_ptr<GUI::Game::Player> player = nullptr;
                std::size_t level = 0;

                if (args.size() != 3) {
                    std::cerr << "Error: Pgt: wrong number of arguments" << std::endl;
                    return;
                }
                try {
                    player = _findPlayerById(std::stoi(args[1]));
                } catch (std::exception &e) {
                    std::cerr << "Error: Plv: player id is not valid" << std::endl;
                    return;
                }
                try {
                    level = std::stoi(args[2]);
                } catch (std::exception &e) {
                    std::cerr << "Error: Plv: level is not valid" << std::endl;
                    return;
                }
                if (!player) {
                    std::cerr << "Error: Pgt: player not found" << std::endl;
                    return;
                }
                player->setLevel(level);
            }
        private:
            std::shared_ptr<GUI::Game::Player> _findPlayerById(int id)
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
