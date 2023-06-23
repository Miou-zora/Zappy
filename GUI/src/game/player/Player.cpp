/*
** EPITECH PROJECT, 2023
** GUI
** File description:
** Player
*/

#include "Player.hpp"
#include <iostream>

namespace GUI::Game {
    Player::Player(const std::string &teamName, int id, Vector2 position, Orientation orientation, size_t level):
        _id(id),
        _teamName(teamName),
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
        _thystameContainer(std::make_shared<GUI::Game::ThystameContainer>())
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
        _model->setPos(_position.x + _positionDiff.x, 0.75f, _position.y + _positionDiff.x);
        _model->setScale(0.25f + 0.05 * _level, 0.25f + 0.05 * _level, 0.25f + 0.05 * _level);
    }

    void Player::render(std::shared_ptr<GUI::Graphic::Object::Camera> camera)
    {
        _model->draw(camera);
    }
}
