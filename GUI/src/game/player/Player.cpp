/*
** EPITECH PROJECT, 2023
** GUI
** File description:
** Player
*/

#include "Player.hpp"
#include <iostream>
#include "Team.hpp"
#include "IOPooledClient.hpp"
#include "Request.hpp"

namespace GUI::Game {
    Player::Player(std::shared_ptr<GUI::Game::Team> teamName, int id, Vector2 position, Orientation orientation, std::shared_ptr<GUI::Network::IOPooledClient> client, size_t level):
        _id(id),
        _team(teamName),
        _position(position),
        _level(level),
        _orientation(orientation),
        _model(std::make_shared<GUI::Graphic::Object::Model>(LoadModelFromMesh(GenMeshCube(1, 1, 1)))),
        _foodContainer(std::make_shared<GUI::Game::FoodContainer>()),
        _linemateContainer(std::make_shared<GUI::Game::LinemateContainer>()),
        _deraumereContainer(std::make_shared<GUI::Game::DeraumereContainer>()),
        _siburContainer(std::make_shared<GUI::Game::SiburContainer>()),
        _mendianeContainer(std::make_shared<GUI::Game::MendianeContainer>()),
        _phirasContainer(std::make_shared<GUI::Game::PhirasContainer>()),
        _thystameContainer(std::make_shared<GUI::Game::ThystameContainer>()),
        _client(client)
    {

    }


    void Player::update(void)
    {
        Vector3 rotation = {0, 0, 0};
        switch (_orientation) {
            case NORTH:
                rotation.y = PI / 2;
                break;
            case EAST:
                rotation.y = PI;
                break;
            case SOUTH:
                rotation.y = -PI / 2;
                break;
            case WEST:
                break;
        }
        _model->setRot(rotation.x, rotation.y, rotation.z);
        _model->setPos(_position.x + _positionDiff.x, 0.75f, _position.y + _positionDiff.y);
        _model->setScale(0.25f + 0.05 * _level, 0.25f + 0.05 * _level, 0.25f + 0.05 * _level);
    }

    void Player::render(std::shared_ptr<GUI::Graphic::Object::Camera> camera)
    {
        _model->draw(camera);
    }

    void Player::drawInfo(std::shared_ptr<GUI::Graphic::Object::Camera> _camera)
    {
        Vector3 scale = _model->getScale();
        if (_camera != nullptr) {
            scale.x += 0.01;
            scale.y += 0.01;
            scale.z += 0.01;
            BeginMode3D(*_camera->getCamera());
                DrawModelWiresEx(*_model->getModel(), _model->getPos(), _model->getRot(), 1, scale, RAYWHITE);
            EndMode3D();
        }
        DrawText(("Player " + std::to_string(_id) + " x=" + std::to_string(static_cast<int>(_position.x)) + " y=" + std::to_string(static_cast<int>(_position.y))).c_str(), 10, 10, 20, WHITE);
        DrawText(("Team: " + _team->getName()).c_str(), 10, 30, 20, _team->getColor());
        DrawText(("Level: " + std::to_string(_level)).c_str(), 10, 50, 20, WHITE);
        DrawText(("Orientation: " + _orientationToString(_orientation)).c_str(), 10, 70, 20, WHITE);
        DrawText(("Food: " + std::to_string(_foodContainer->getQuantity())).c_str(), 10, 90, 20, WHITE);
        DrawText(("Linemate: " + std::to_string(_linemateContainer->getQuantity())).c_str(), 10, 110, 20, WHITE);
        DrawText(("Deraumere: " + std::to_string(_deraumereContainer->getQuantity())).c_str(), 10, 130, 20, WHITE);
        DrawText(("Sibur: " + std::to_string(_siburContainer->getQuantity())).c_str(), 10, 150, 20, WHITE);
        DrawText(("Mendiane: " + std::to_string(_mendianeContainer->getQuantity())).c_str(), 10, 170, 20, WHITE);
        DrawText(("Phiras: " + std::to_string(_phirasContainer->getQuantity())).c_str(), 10, 190, 20, WHITE);
        DrawText(("Thystame: " + std::to_string(_thystameContainer->getQuantity())).c_str(), 10, 210, 20, WHITE);
        _client->addRequest(std::make_shared<GUI::Network::Request>("pin " + _id));
    }

    std::shared_ptr<BoundingBox> Player::getBoundingBox(void)
    {
        if (_model == nullptr)
            return nullptr;
        return _model->getBoundingBox();
    }
}
