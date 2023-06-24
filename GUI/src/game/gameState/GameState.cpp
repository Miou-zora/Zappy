/*
** EPITECH PROJECT, 2023
** GUI
** File description:
** GameState
*/

#include "GameState.hpp"
#include <iostream>
#include "QuitButton.hpp"
#include "Window.hpp"
#include "SwitchTimeunitButton.hpp"


bool operator==(const Color &c1, const Color &c2)
{
    return (c1.r == c2.r && c1.g == c2.g && c1.b == c2.b && c1.a == c2.a);
}

namespace GUI::Game {
    GameState::GameState(std::shared_ptr<GUI::Graphic::Scene> scene):
        _scene(scene),
        _map(std::make_shared<GUI::Game::Map>(0, 0)),
        _settings(std::make_shared<GUI::Game::GameSettings>()),
        _incantations(std::vector<std::shared_ptr<GUI::Game::Incantation>>()),
        _eventPool(std::make_shared<GUI::Game::EventPool>()),
        _entityCatched(nullptr),
        _atlas(nullptr)
    {
    }

    void GameState::update(const double &deltaTime)
    {
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            if (_clickOnButton(GetMousePosition()))
                return;
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
        _eventPool->updateEvents(deltaTime);
    }

    void GameState::render(void)
    {
        if (_scene->getCamera() == nullptr) {
            std::cerr << "No camera set. Unable to draw" << std::endl;
            return;
        }
        _map->render(_scene->getCamera());
        _atlas->draw(_scene->getCamera());
        for (auto &player : _players) {
            player->render(_scene->getCamera());
        }
        _eventPool->drawEvents(_scene->getCamera());
        if (_entityCatched != nullptr)
            _entityCatched->drawInfo(_scene->getCamera());
        else
            _drawTeams();
        DrawFPS(700, 10);
        _drawButtons();
        _displayTimeUnit();
    }

    void GameState::init(std::shared_ptr<GUI::Graphic::Window> window, std::shared_ptr<GUI::Network::IOPooledClient> client)
    {
        Model atlas = LoadModel("assets/makima/scene.gltf");
        if (IsModelReady(atlas) == false) {
            std::cout << "PERSO: ERROR: Unable to load atlas" << std::endl;
            return;
        }
        _atlas = std::make_shared<GUI::Graphic::Object::Model>(atlas, WHITE);
        _atlas->setPos(0, -255, -35);
        _atlas->setScale(2, 2, 2);
        _buttons.push_back(std::make_shared<Button::QuitButton>(Button::QuitButton(window, {300, 10}, {50, 50})));
        _buttons.push_back(std::make_shared<Button::SwitchTimeunitButton>(Button::SwitchTimeunitButton(client, 10, {360, 10}, {100, 25}, "assets/button/switchTimeunit/1.png")));
        _buttons.push_back(std::make_shared<Button::SwitchTimeunitButton>(Button::SwitchTimeunitButton(client, 100, {360, 40}, {100, 25}, "assets/button/switchTimeunit/2.png")));
        _buttons.push_back(std::make_shared<Button::SwitchTimeunitButton>(Button::SwitchTimeunitButton(client, 1000, {360, 70}, {100, 25}, "assets/button/switchTimeunit/3.png")));
        // TODO: init camera here
    }

    void GameState::_drawTeams(void) const
    {
        std::string textToDisplay = "Teams Name:\n";

        DrawText(textToDisplay.c_str(), 10, 10, 20, WHITE);
        for (size_t index = 0; index < _teams.size(); index++) {
            textToDisplay = _teams[index]->getName() + "\n";
            DrawText(textToDisplay.c_str(), 10, 10 + (index + 1) * 20, 20, _teams[index]->getColor());
        }
    }

    bool GameState::_clickOnButton(Vector2 mousePos)
    {
        for (auto &button : _buttons) {
            if (CheckCollisionPointRec(mousePos, button->getRect())) {
                button->click();
                return true;
            }
        }
        return false;
    }

    void GameState::_drawButtons(void) const
    {
        for (auto &button : _buttons) {
            button->draw();
        }
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

        catchables->insert(catchables->end(), _players.begin(), _players.end());
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
