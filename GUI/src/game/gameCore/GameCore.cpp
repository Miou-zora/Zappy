/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** GameCore
*/

#include "GameCore.hpp"
#include "ErrorManagement.hpp"
#include <iostream>

namespace GUI::Game {
    GameCore::GameCore(std::shared_ptr<GUI::Graphic::Scene> scene, std::shared_ptr<GUI::Network::IOPooledClient> client):
        _gameState(std::make_shared<GUI::Game::GameState>(scene)),
        _client(client)
    {

    }

    void GameCore::update(const double &timeElapsed)
    {
        (void) timeElapsed;

        if (_gameState == nullptr) {
            throw GUI::GameException("Error: no game state set");
        } else if (_client == nullptr) {
            throw GUI::GameException("Error: no client set");
        }

        std::shared_ptr<GUI::Network::Response> response = _client->getResponse();
        while (response != nullptr && response->get() != "suc") {
            try {
                std::cout << "Command: " << response->get() << std::endl;
                std::shared_ptr<GUI::Game::IUpdate> command = _factory.create(_gameState, _client, response->get());
                command->update();
            } catch (GUI::GameException &e) {
                std::cerr << "Invalid command: " << response->get() << std::endl;
            }
            response = _client->getResponse();
        }
        _gameState->update();
    }

    void GameCore::render(void) {
        _gameState->render();
    }

    void GameCore::init(void)
    {
        _gameState->init();
    }
}
