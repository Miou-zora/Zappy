/*
** EPITECH PROJECT, 2023
** GUI
** File description:
** GameState
*/

#include "GameState.hpp"
#include <iostream>

namespace GUI::Game {
    GameState::GameState(std::shared_ptr<GUI::Graphic::Scene> scene):
        _scene(scene),
        _map(std::make_shared<GUI::Game::Map>(0, 0)),
        _settings(std::make_shared<GUI::Game::GameSettings>()),
        _program(std::make_shared<GUI::Graphic::Program>())
    {

    }

    void GameState::update(void)
    {
        _map->update();
        for (auto &player : _players) {
            player->update();
        }
    }

    void GameState::render(void)
    {
        if (_scene->getCamera() == nullptr) {
            std::cerr << "No camera set. Unable to draw" << std::endl;
            return;
        }
        _map->render(_scene->getCamera());
        for (auto &player : _players) {
            player->render(_scene->getCamera());
        }
    }

    void GameState::init(void)
    {
        _program->load();
        _map->load();
        _map->setProgram(_program);
        _map->loadProgram();
        _scene->getCamera()->setPos(glm::vec3(-1, 5, -1));
        _scene->getCamera()->setRot(glm::vec3(M_PI / 4, -M_PI / 4, 0));
    }
}
