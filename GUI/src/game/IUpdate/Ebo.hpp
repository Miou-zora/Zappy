/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** Ebo
*/

#pragma once
#include "IUpdate.hpp"

namespace GUI::Game {
    class Ebo : public GUI::Game::IUpdate {
        public:
            Ebo(std::shared_ptr<GUI::Game::GameState> gameState,
                std::shared_ptr<GUI::Network::IOPooledClient> client,
                std::string command)
            {
                _gameState = gameState;
                _client = client;
                _command = command;
            }

            ~Ebo(void) = default;

            void update(void) override
            {
                std::vector<std::string> args = GUI::Utils::StringUtils::split(_command, " ");
                int id = 0;

                if (args.size() != 2 && args[0] != "ebo") {
                    std::cerr << "Error: Ebo: wrong command sended" << std::endl;
                    return;
                }
                try {
                    id = std::stoi(args[1]);
                } catch (std::exception &e) {
                    std::cerr << "Error: Ebo: " << e.what() << std::endl;
                    return;
                }
                if (_findEggById(id) == nullptr) {
                    std::cerr << "Error: Ebo: egg not found" << std::endl;
                    return;
                }
            }
        private:
            std::shared_ptr<GUI::Game::Egg> _findEggById(int id)
            {
                for (auto &egg : _gameState->getEggs()) {
                    if (egg->getId() == id)
                        return egg;
                }
                return nullptr;
            }
    };
}
