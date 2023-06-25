/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** Egg
*/

#include "Egg.hpp"

namespace GUI::Game {
    Egg::Egg(std::shared_ptr<GUI::Game::Team> teamName, int id, Vector2 position):
        _id(id),
        _team(teamName),
        _position(position),
        _model(std::make_shared<GUI::Graphic::Object::Model>(LoadModelFromMesh(GenMeshCube(1, 1, 1)), BEIGE))
    {

    }


    void Egg::update(void)
    {
        _model->setPos(_position.x + _positionDiff.x, 0.75f, _position.y + _positionDiff.y);
        _model->setScale(0.15f, 0.20f, 0.15f);
    }

    void Egg::render(std::shared_ptr<GUI::Graphic::Object::Camera> camera)
    {
        _model->draw(camera);
    }
}
