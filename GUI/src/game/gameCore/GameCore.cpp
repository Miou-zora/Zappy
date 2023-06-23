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
        if (_gameState == nullptr) {
            throw GUI::GameException("Error: no game state set");
        } else if (_client == nullptr) {
            throw GUI::GameException("Error: no client set");
        }

        std::shared_ptr<GUI::Network::Response> response = _client->getResponse();
        while (response != nullptr && response->get() != "suc") {
            try {
                std::shared_ptr<GUI::Game::IUpdate> command = _factory.create(_gameState, _client, response->get());
                std::cout << "PERSO: INFO: VALID COMMAND: " << response->get() << std::endl;
                command->update();
            } catch (GUI::GameException &e) {
                std::cerr << "PERSO: INFO: INVALID COMMAND:" << response->get() << std::endl;
            }
            response = _client->getResponse();
        }
        _gameState->update(timeElapsed);
    }

    void GameCore::render(void) {
        _gameState->render();
    }

    void GameCore::init(void)
    {
        _gameState->init();
    }
}
