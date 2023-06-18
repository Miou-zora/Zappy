/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** Tile
*/

#include "Tile.hpp"
#include "Cube.hpp"
#include <iostream>

namespace GUI::Game {
    Tile::Tile(void):
        Object(),
        _model(nullptr),
        _foodQuantity(0),
        _linemateQuantity(0),
        _deraumereQuantity(0),
        _siburQuantity(0),
        _mendianeQuantity(0),
        _phirasQuantity(0),
        _thystameQuantity(0)
    {

    }

    Tile::Tile(int x, int z):
        Object(glm::vec3(x, 0, z), glm::vec4(0, 0, 0, 0), glm::vec3(1, 1, 1)),
        _model(nullptr),
        _foodQuantity(0),
        _linemateQuantity(0),
        _deraumereQuantity(0),
        _siburQuantity(0),
        _mendianeQuantity(0),
        _phirasQuantity(0),
        _thystameQuantity(0)
    {

    }

    Tile::Tile(int x, int y, int z):
        Object(glm::vec3(x, y, z), glm::vec4(0, 0, 0, 0), glm::vec3(1, 1, 1)),
        _model(nullptr),
        _foodQuantity(0),
        _linemateQuantity(0),
        _deraumereQuantity(0),
        _siburQuantity(0),
        _mendianeQuantity(0),
        _phirasQuantity(0),
        _thystameQuantity(0)
    {

    }

    Tile::Tile(const glm::vec3 &pos):
        Object(pos, glm::vec4(0, 0, 0, 0), glm::vec3(1, 1, 1)), _model(nullptr),
        _foodQuantity(0),
        _linemateQuantity(0),
        _deraumereQuantity(0),
        _siburQuantity(0),
        _mendianeQuantity(0),
        _phirasQuantity(0),
        _thystameQuantity(0)
    {

    }


    void Tile::setModel(std::shared_ptr<GUI::Graphic::Object::Model> model)
    {
        _model = model;
    }

    std::shared_ptr<GUI::Graphic::Object::Model> Tile::getModel(void) const
    {
        return _model;
    }

    void Tile::load(void)
    {
        _model = GUI::Graphic::Object::CreateCubeModel();
        _model->setPos(getPos());
        _model->setScale(getScale());
        _model->setRot(getRot());
        _model->update();
    }

    void Tile::draw(std::shared_ptr<GUI::Graphic::Object::Camera> camera)
    {
        _model->draw(camera);
    }

    void Tile::update(void)
    {
        Object::update();
        _model->setPos(getPos());
        _model->setScale(getScale());
        _model->setRot(getRot());
        _model->update();
    }

    void Tile::setProgram(std::shared_ptr<GUI::Graphic::Program> program)
    {
        _program = program;
        _model->setProgram(_program);
    }

    void Tile::loadProgram(void)
    {
        _model->loadProgram();
    }

    void Tile::setFoodQuantity(size_t quantity)
    {
        _foodQuantity = quantity;
    }

    void Tile::setLinemateQuantity(size_t quantity)
    {
        _linemateQuantity = quantity;
    }

    void Tile::setDeraumereQuantity(size_t quantity)
    {
        _deraumereQuantity = quantity;
    }

    void Tile::setSiburQuantity(size_t quantity)
    {
        _siburQuantity = quantity;
    }

    void Tile::setMendianeQuantity(size_t quantity)
    {
        _mendianeQuantity = quantity;
    }

    void Tile::setPhirasQuantity(size_t quantity)
    {
        _phirasQuantity = quantity;
    }

    void Tile::setThystameQuantity(size_t quantity)
    {
        _thystameQuantity = quantity;
    }

    size_t Tile::getFoodQuantity(void) const
    {
        return _foodQuantity;
    }

    size_t Tile::getLinemateQuantity(void) const
    {
        return _linemateQuantity;
    }

    size_t Tile::getDeraumereQuantity(void) const
    {
        return _deraumereQuantity;
    }

    size_t Tile::getSiburQuantity(void) const
    {
        return _siburQuantity;
    }

    size_t Tile::getMendianeQuantity(void) const
    {
        return _mendianeQuantity;
    }

    size_t Tile::getPhirasQuantity(void) const
    {
        return _phirasQuantity;
    }

    size_t Tile::getThystameQuantity(void) const
    {
        return _thystameQuantity;
    }
}
