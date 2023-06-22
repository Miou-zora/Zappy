/*
** EPITECH PROJECT, 2023
** GUI
** File description:
** Pic
*/

#pragma once
#include "IUpdate.hpp"
#include "StringUtils.hpp"
#include "Tile.hpp"
#include <map>

namespace GUI::Game {
    class Pic : public GUI::Game::IUpdate {
        public:
            Pic(std::shared_ptr<GUI::Game::GameState> gameState,
                std::shared_ptr<GUI::Network::IOPooledClient> client,
                std::string command)
            {
                _gameState = gameState;
                _client = client;
                _command = command;
            }

            ~Pic(void) = default;

            void update(void) override
            {
                std::vector<std::string> args = GUI::Utils::StringUtils::split(_command, " ");
                std::size_t posX = 0;
                std::size_t posY = 0;
                std::size_t incantationLevel = 0;
                std::vector<size_t> playersId;
                std::shared_ptr<GUI::Game::Incantation> newIncantation = nullptr;

                if (args.size() < 5) {
                    std::cerr << "Error: Pic: wrong number of arguments" << std::endl;
                    return;
                }
                try {
                    posX = std::stoi(args[1]);
                    posY = std::stoi(args[2]);
                } catch (std::exception &e) {
                    std::cerr << "Error: Pic: invalid positions" << std::endl;
                    return;
                }
                for (auto &incantation : _gameState->getIncantations()) {
                    if (incantation->getPosX() == posX && incantation->getPosY() == posY) {
                        std::cerr << "Error: Pic: incantation already exists on tile: x=" << posX << " y=" << posY << std::endl;
                    }
                }
                try {
                    incantationLevel = std::stoi(args[3]);
                } catch (std::exception &e) {
                    std::cerr << "Error: Pic: invalid incantation level" << std::endl;
                    return;
                }
                try {
                    for (size_t i = 4; i < args.size(); i++) {
                        playersId.push_back(std::stoi(args[i]));
                    }
                } catch (std::exception &e) {
                    std::cerr << "Error: Pic: invalid player id" << std::endl;
                    return;
                }
                newIncantation = std::make_shared<GUI::Game::Incantation>(posX, posY, incantationLevel, playersId);
                _gameState->getIncantations().push_back(newIncantation);
                // TODO: add incantation animation, or text to display
            }
    };
}
