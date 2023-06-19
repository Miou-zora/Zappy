/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** Pgt
*/

#pragma once
#include "IUpdate.hpp"
#include "StringUtils.hpp"
#include "Tile.hpp"
#include <map>

namespace GUI::Game {
    class Pgt : public GUI::Game::IUpdate {
        public:
            Pgt(std::shared_ptr<GUI::Game::GameState> gameState,
                std::shared_ptr<GUI::Network::IOPooledClient> client,
                std::string command)
            {
                _gameState = gameState;
                _client = client;
                _command = command;
            }

            ~Pgt(void) = default;

            void update(void) override
            {
                std::vector<std::string> args = GUI::Utils::StringUtils::split(_command, " ");
                std::shared_ptr<GUI::Game::Player> player = nullptr;
                std::shared_ptr<GUI::Game::Tile> tile = nullptr;

                if (args.size() != 3) {
                    std::cerr << "Error: Pgt: wrong number of arguments" << std::endl;
                    return;
                }
                player = _findPlayerById(std::stoi(args[1]));
                tile = _gameState->getMap()->getTile(player->getPosition().x, player->getPosition().y);
                if (!player || !tile) {
                    std::cerr << "Error: Pgt: player or tile not found" << std::endl;
                    return;
                }
                _pullAllElementFromTileToPlayer(player, tile, 1, std::stoi(args[2]));
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

            void _pullAllElementFromTileToPlayer(std::shared_ptr<GUI::Game::Player> player, std::shared_ptr<GUI::Game::Tile> tile, size_t quantity, size_t type)
            {
                std::map<size_t, std::pair<std::shared_ptr<GUI::Game::Container>, std::shared_ptr<GUI::Game::Container>>> containerPerType = {
                    {0, std::pair<std::shared_ptr<GUI::Game::Container>, std::shared_ptr<GUI::Game::Container>>(tile->getFoodContainer(), player->getFoodContainer())},
                    {1, std::pair<std::shared_ptr<GUI::Game::Container>, std::shared_ptr<GUI::Game::Container>>(tile->getLinemateContainer(), player->getLinemateContainer())},
                    {2, std::pair<std::shared_ptr<GUI::Game::Container>, std::shared_ptr<GUI::Game::Container>>(tile->getDeraumereContainer(), player->getDeraumereContainer())},
                    {3, std::pair<std::shared_ptr<GUI::Game::Container>, std::shared_ptr<GUI::Game::Container>>(tile->getSiburContainer(), player->getSiburContainer())},
                    {4, std::pair<std::shared_ptr<GUI::Game::Container>, std::shared_ptr<GUI::Game::Container>>(tile->getMendianeContainer(), player->getMendianeContainer())},
                    {5, std::pair<std::shared_ptr<GUI::Game::Container>, std::shared_ptr<GUI::Game::Container>>(tile->getPhirasContainer(), player->getPhirasContainer())},
                    {6, std::pair<std::shared_ptr<GUI::Game::Container>, std::shared_ptr<GUI::Game::Container>>(tile->getThystameContainer(), player->getThystameContainer())}
                };
                std::pair<std::shared_ptr<GUI::Game::Container>, std::shared_ptr<GUI::Game::Container>> containers = containerPerType[type];

                for (size_t i = 0; i < quantity; i++) {
                    if ((*(containers.first)) > 0) {
                        (*(containers.first)) -= 1;
                        (*(containers.second)) += 1;
                    } else {
                        break;
                    }
                }
            }
    };
}
