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
        _model(std::make_shared<GUI::Graphic::Object::Model>(LoadModelFromMesh(GenMeshCube(1, 1, 1)), BEIGE)),
        _randomValueX((float) rand() / (float) RAND_MAX),
        _randomValueY((float) rand() / (float) RAND_MAX)
    {
        float globalScale = 0.2f + ((float) rand() / (float) RAND_MAX) * (0.1f);
        _model->setScale(globalScale, globalScale * (1 + rand() / (float) RAND_MAX * 0.5f), globalScale);
    }


    void Egg::update(void)
    {
        _model->setPos(_position.x + _positionDiff.x + (1.f * _randomValueX), 0.70f, _position.y + _positionDiff.y + (1.f * _randomValueY));
    }

    void Egg::render(std::shared_ptr<GUI::Graphic::Object::Camera> camera)
    {
        _model->draw(camera);
    }
}
