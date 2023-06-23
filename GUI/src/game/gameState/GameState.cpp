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
        _incantations(std::vector<std::shared_ptr<GUI::Game::Incantation>>())
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
        _drawTeams();
        DrawFPS(700, 10);
        BeginMode3D(*_scene->getCamera()->getCamera());
            _map->render();
            for (auto &player : _players) {
                player->render();
            }
        EndMode3D();
        _displayTimeUnit();
    }

    void GameState::init(void)
    {
        // TODO: init camera here
    }

    void GameState::_drawTeams(void) const
    {
        std::string textToDisplay = "Teams Name:\n";

        for (auto &team: _teamNames) {
            textToDisplay += "\t" + team + "\n";
        }
        DrawText(textToDisplay.c_str(), 10, 10, 20, WHITE);
    }

    void GameState::_displayTimeUnit(void) const
    {
        std::string textToDisplay = "Time Unit: " + std::to_string(_settings->getTimeUnit());

        DrawText(textToDisplay.c_str(), 10, 600 - 20, 20, WHITE);
    }
}
