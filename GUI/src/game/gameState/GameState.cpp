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
        _incantations(std::vector<std::shared_ptr<GUI::Game::Incantation>>()),
        _eventPool(std::make_shared<GUI::Game::EventPool>()),
        _entityCatched(nullptr)
    {

    }

    void GameState::update(void)
    {
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            _catch();
        } else if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) {
            _drop();
        }
        _map->update();
        for (auto &player : _players) {
            player->update();
        }
        _eventPool->updateEvents();
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
        _eventPool->drawEvents(_scene->getCamera());
        _drawTeams();
        DrawFPS(700, 10);
        _displayTimeUnit();
        if (_entityCatched != nullptr)
            _entityCatched->drawInfo();
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

    void GameState::_catch(void)
    {
        Ray ray = GetMouseRay(GetMousePosition(), *_scene->getCamera()->getCamera());
        (void) ray;
        // TODO: check if catchable is in range
        // if something is catched, set _catchable to the catched object
    }

    void GameState::_drop(void)
    {
        if (_entityCatched == nullptr)
            return;
        _entityCatched = nullptr;
    }
}
