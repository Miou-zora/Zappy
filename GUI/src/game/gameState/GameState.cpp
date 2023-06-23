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
        for (std::size_t index = 0; index < _incantations.size(); index++) {
            if (_incantations[index]->isFinished()) {
                std::cout << "PERSO: INFO: INCANTATION FINISHED: at X=" << _incantations[index]->getPosX() << " y=" << _incantations[index]->getPosY() << std::endl;
                _incantations.erase(_incantations.begin() + index);
                index--;
            }
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
        if (_entityCatched != nullptr)
            _entityCatched->drawInfo(_scene->getCamera());
        DrawFPS(700, 10);
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

    void GameState::_catch(void)
    {
        Ray ray = GetMouseRay(GetMousePosition(), *_scene->getCamera()->getCamera());
        RayCollision collision = { 0, 0, (Vector3){0, 0, 0}, (Vector3){0, 0, 0}};
        std::shared_ptr<std::vector<std::shared_ptr<GUI::Game::ICatchable>>> catchables = _map->getCatchables();
        std::vector<std::pair<RayCollision, std::shared_ptr<GUI::Game::ICatchable>>> catched;
        std::shared_ptr<BoundingBox> boundingBox = nullptr;
        float rayDistance = 0.0f;

        for (auto &catchable : *catchables) {
            boundingBox = catchable->getBoundingBox();
            if (boundingBox == nullptr)
                continue;
            collision = GetRayCollisionBox(ray, *boundingBox);
            if (collision.hit) {
                catched.push_back(std::make_pair(collision, catchable));
            }
        }
        if (catched.empty()) {
            _entityCatched = nullptr;
            return;
        }
        _entityCatched = catched[0].second;
        rayDistance = catched[0].first.distance;
        for (auto &catchable : catched) {
            if (catchable.first.distance < rayDistance) {
                _entityCatched = catchable.second;
                rayDistance = catchable.first.distance;
            }
        }
    }

    void GameState::_drop(void)
    {
        if (_entityCatched == nullptr)
            return;
        _entityCatched = nullptr;
    }
}
