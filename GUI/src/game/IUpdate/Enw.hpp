/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** Enw
*/

#pragma once
#include "IUpdate.hpp"
#include "StringUtils.hpp"
#include <iostream>

namespace GUI::Game {
    /**
     * @brief Bct class is used to update the map
     */
    class Enw : public IUpdate{
        public:
            Enw(std::shared_ptr<GUI::Game::GameState> gameState,
                std::shared_ptr<GUI::Network::IOPooledClient> client,
                std::string command)
            {
                _gameState = gameState;
                _client = client;
                _command = command;
            }
            ~Enw() = default;

            /**
             * @brief update the map
             *
             * @return ** void
             */
            void update()
            {
                std::vector<std::string> args = GUI::Utils::StringUtils::split(_command, " ");
                std::vector<std::shared_ptr<GUI::Game::Egg>> &eggs = _gameState->getEggs();
                std::shared_ptr<GUI::Game::Egg> newEgg = nullptr;
                std::shared_ptr<GUI::Game::Player> player = nullptr;
                int eggId = 0;
                int playerId = 0;
                int posX = 0;
                int posY = 0;

                try {
                    _parseArgs(args, eggId, playerId, posX, posY);
                } catch (std::exception &e) {
                    return;
                }
                if (playerId != -1) {
                    player = _findPlayerById(_gameState->getPlayers(), playerId);
                }
                for (auto &egg: eggs) {
                    if (egg->getId() == eggId) {
                        std::cerr << "Error: Enw: egg already exists: " << std::to_string(eggId) << std::endl;
                        return;
                    }
                }
                if (playerId != -1)
                    if (player)
                        newEgg = std::make_shared<GUI::Game::Egg>(player->getTeam(), eggId, (Vector2){static_cast<float>(posX), static_cast<float>(posY)});
                    else
                        newEgg = std::make_shared<GUI::Game::Egg>(nullptr, eggId, (Vector2){static_cast<float>(posX), static_cast<float>(posY)});
                else
                    newEgg = std::make_shared<GUI::Game::Egg>(nullptr, eggId, (Vector2){static_cast<float>(posX), static_cast<float>(posY)});
                newEgg->setPositionDiff({-_gameState->getMap()->getSize().x / 2 + 0.5f, -_gameState->getMap()->getSize().y / 2 + 0.5f});
                eggs.push_back(newEgg);
            }
        private:
            void _parseArgs(std::vector<std::string> &args, int &eggId, int &playerId, int &posX, int &posY)
            {
                if (args.size() != 5) {
                    std::cerr << "Error: Enw: invalid number of arguments" << std::endl;
                    throw std::exception();
                }
                if (args[0] != "enw") {
                    std::cerr << "Error: Enw: invalid command" << std::endl;
                    throw std::exception();
                }
                try {
                    eggId = std::stoi(args[1]);
                    playerId = std::stoi(args[2]);
                    posX = std::stoi(args[3]);
                    posY = std::stoi(args[4]);
                } catch (std::exception &e) {
                    std::cerr << "Error: Enw: " << e.what() << std::endl;
                    throw std::exception();
                }
            }

            std::shared_ptr<GUI::Game::Player> _findPlayerById(std::vector<std::shared_ptr<GUI::Game::Player>> &players, int playerId)
            {
                for (auto &player : players) {
                    if (player->getId() == playerId)
                        return player;
                }
                return nullptr;
            }
    };
}
