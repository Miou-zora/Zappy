/*
** EPITECH PROJECT, 2023
** GUI
** File description:
** Player
*/

#include "Player.hpp"
#include "Cube.hpp"
#include "Program.hpp"
#include <iostream>

namespace GUI::Game {
    Player::Player(const std::string &teamName, int id, glm::ivec2 position, Orientation orientation, size_t level):
        _id(id),
        _teamName(teamName),
        _position(position),
        _level(level),
        _orientation(orientation),
        _model(GUI::Graphic::Object::CreateCubeModel())
    {

    }

    void Player::load(std::shared_ptr<GUI::Graphic::Program> _program)
    {
        _model->setPos(glm::vec3(_position.x, -1, _position.y));
        glm::vec3 rotation = glm::vec3(0, 0, 0);
        switch (_orientation) {
            case NORTH:
                rotation.y = M_PI / 2;
                break;
            case EAST:
                rotation.y = M_PI;
                break;
            case SOUTH:
                rotation.y = - M_PI / 2;
                break;
            case WEST:
                break;
        }
        _model->setRot(rotation);
        _model->setProgram(_program);
        _model->update();
        _model->loadProgram();
    }

    void Player::update(void)
    {
        _model->setPos(glm::vec3(_position.x, -1 + 0.05 * (10 - _level), _position.y));
        _model->setScale(glm::vec3(0.10 + 0.05 * _level, 0.10 + 0.05 * _level, 0.10 + 0.05 * _level));
        _model->update();
    }

    void Player::render(std::shared_ptr<GUI::Graphic::Object::Camera> camera)
    {
        _model->draw(camera);
    }
}
