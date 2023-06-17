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
    GameCore::GameCore(void)
    {
        _scene = nullptr;
        _client = nullptr;
        _settings = std::make_shared<GUI::Game::GameSettings>();
    }

    GameCore::GameCore(std::shared_ptr<GUI::Graphic::Scene> scene, std::shared_ptr<GUI::Network::IOPooledClient> client)
    {
        _scene = scene;
        _client = client;
        _settings = std::make_shared<GUI::Game::GameSettings>();
        _scene->getCamera()->setPos(glm::vec3(-2, -3, -3));
        _scene->getCamera()->setRot(glm::vec3(0, - M_PI / 4, 0));
    }

    void GameCore::update(const double &timeElapsed)
    {
        (void) timeElapsed;

        if (_scene == nullptr) {
            throw GUI::GameException("Error: no scene set");
        } else if (_client == nullptr) {
            throw GUI::GameException("Error: no client set");
        }

        std::shared_ptr<GUI::Network::Response> response = _client->getResponse();
        while (response != nullptr && response->get() != "suc") {
            try {
                std::cout << "Command: " << response->get() << std::endl;
                std::shared_ptr<GUI::Game::IUpdate> command = _factory.create(_settings, _client, _scene, response->get());
                command->update();
            } catch (GUI::GameException &e) {
                std::cerr << "Invalid command: " << response->get() << std::endl;
            }
            response = _client->getResponse();
        }
    }
}
