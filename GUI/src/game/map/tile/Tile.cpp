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
        _foodContainer(std::make_shared<GUI::Game::FoodContainer>()),
        _linemateContainer(std::make_shared<GUI::Game::LinemateContainer>()),
        _deraumereContainer(std::make_shared<GUI::Game::DeraumereContainer>()),
        _siburContainer(std::make_shared<GUI::Game::SiburContainer>()),
        _mendianeContainer(std::make_shared<GUI::Game::MendianeContainer>()),
        _phirasContainer(std::make_shared<GUI::Game::PhirasContainer>()),
        _thystameContainer(std::make_shared<GUI::Game::ThystameContainer>())
    {

    }

    Tile::Tile(int x, int z):
        Object(glm::vec3(x, 0, z), glm::vec4(0, 0, 0, 0), glm::vec3(1, 1, 1)),
        _model(nullptr),
        _foodContainer(std::make_shared<GUI::Game::FoodContainer>()),
        _linemateContainer(std::make_shared<GUI::Game::LinemateContainer>()),
        _deraumereContainer(std::make_shared<GUI::Game::DeraumereContainer>()),
        _siburContainer(std::make_shared<GUI::Game::SiburContainer>()),
        _mendianeContainer(std::make_shared<GUI::Game::MendianeContainer>()),
        _phirasContainer(std::make_shared<GUI::Game::PhirasContainer>()),
        _thystameContainer(std::make_shared<GUI::Game::ThystameContainer>())
    {

    }

    Tile::Tile(int x, int y, int z):
        Object(glm::vec3(x, y, z), glm::vec4(0, 0, 0, 0), glm::vec3(1, 1, 1)),
        _model(nullptr),
        _foodContainer(std::make_shared<GUI::Game::FoodContainer>()),
        _linemateContainer(std::make_shared<GUI::Game::LinemateContainer>()),
        _deraumereContainer(std::make_shared<GUI::Game::DeraumereContainer>()),
        _siburContainer(std::make_shared<GUI::Game::SiburContainer>()),
        _mendianeContainer(std::make_shared<GUI::Game::MendianeContainer>()),
        _phirasContainer(std::make_shared<GUI::Game::PhirasContainer>()),
        _thystameContainer(std::make_shared<GUI::Game::ThystameContainer>())
    {

    }

    Tile::Tile(const glm::vec3 &pos):
        Object(pos, glm::vec4(0, 0, 0, 0), glm::vec3(1, 1, 1)), _model(nullptr),
        _foodContainer(std::make_shared<GUI::Game::FoodContainer>()),
        _linemateContainer(std::make_shared<GUI::Game::LinemateContainer>()),
        _deraumereContainer(std::make_shared<GUI::Game::DeraumereContainer>()),
        _siburContainer(std::make_shared<GUI::Game::SiburContainer>()),
        _mendianeContainer(std::make_shared<GUI::Game::MendianeContainer>()),
        _phirasContainer(std::make_shared<GUI::Game::PhirasContainer>()),
        _thystameContainer(std::make_shared<GUI::Game::ThystameContainer>())
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
        _foodContainer->load();
        _linemateContainer->load();
        _deraumereContainer->load();
        _siburContainer->load();
        _mendianeContainer->load();
        _phirasContainer->load();
        _thystameContainer->load();

        _foodContainer->getModel()->setPos(getPos() + glm::vec3(0.3, -0.5, 0));
        _linemateContainer->getModel()->setPos(getPos() + glm::vec3(0.3, -0.5, 0.3));
        _deraumereContainer->getModel()->setPos(getPos() + glm::vec3(0, -0.5, 0.3));
        _siburContainer->getModel()->setPos(getPos() + glm::vec3(-0.3, -0.5, 0.3));
        _mendianeContainer->getModel()->setPos(getPos() + glm::vec3(-0.3, -0.5, 0));
        _phirasContainer->getModel()->setPos(getPos() + glm::vec3(-0.3, -0.5, -0.3));
        _thystameContainer->getModel()->setPos(getPos() + glm::vec3(0, -0.5, -0.3));
    }

    void Tile::draw(std::shared_ptr<GUI::Graphic::Object::Camera> camera)
    {
        _model->draw(camera);
        if ((*_foodContainer) > 0)
            _foodContainer->draw(camera);
        if ((*_linemateContainer) > 0)
            _linemateContainer->draw(camera);
        if ((*_deraumereContainer) > 0)
            _deraumereContainer->draw(camera);
        if ((*_siburContainer) > 0)
            _siburContainer->draw(camera);
        if ((*_mendianeContainer) > 0)
            _mendianeContainer->draw(camera);
        if ((*_phirasContainer) > 0)
            _phirasContainer->draw(camera);
        if ((*_thystameContainer) > 0)
            _thystameContainer->draw(camera);
    }

    void Tile::update(void)
    {
        Object::update();
        _model->setPos(getPos());
        _model->setScale(getScale());
        _model->setRot(getRot());
        _model->update();
        _foodContainer->update();
        _linemateContainer->update();
        _deraumereContainer->update();
        _siburContainer->update();
        _mendianeContainer->update();
        _phirasContainer->update();
        _thystameContainer->update();
    }

    void Tile::setProgram(std::shared_ptr<GUI::Graphic::Program> program)
    {
        _program = program;
        _model->setProgram(_program);
        _foodContainer->setProgram(_program);
        _linemateContainer->setProgram(_program);
        _deraumereContainer->setProgram(_program);
        _siburContainer->setProgram(_program);
        _mendianeContainer->setProgram(_program);
        _phirasContainer->setProgram(_program);
        _thystameContainer->setProgram(_program);
    }

    void Tile::loadProgram(void)
    {
        _model->loadProgram();
        _foodContainer->loadProgram();
        _linemateContainer->loadProgram();
        _deraumereContainer->loadProgram();
        _siburContainer->loadProgram();
        _mendianeContainer->loadProgram();
        _phirasContainer->loadProgram();
        _thystameContainer->loadProgram();
    }

    void Tile::setFoodQuantity(size_t quantity)
    {
        (*_foodContainer) = quantity;
    }

    void Tile::setLinemateQuantity(size_t quantity)
    {
        (*_linemateContainer) = quantity;
    }

    void Tile::setDeraumereQuantity(size_t quantity)
    {
        (*_deraumereContainer) = quantity;
    }

    void Tile::setSiburQuantity(size_t quantity)
    {
        (*_siburContainer) = quantity;
    }

    void Tile::setMendianeQuantity(size_t quantity)
    {
        (*_mendianeContainer) = quantity;
    }

    void Tile::setPhirasQuantity(size_t quantity)
    {
        (*_phirasContainer) = quantity;
    }

    void Tile::setThystameQuantity(size_t quantity)
    {
        (*_thystameContainer) = quantity;
    }

    size_t Tile::getFoodQuantity(void) const
    {
        return _foodContainer->getQuantity();
    }

    size_t Tile::getLinemateQuantity(void) const
    {
        return _linemateContainer->getQuantity();
    }

    size_t Tile::getDeraumereQuantity(void) const
    {
        return _deraumereContainer->getQuantity();
    }

    size_t Tile::getSiburQuantity(void) const
    {
        return _siburContainer->getQuantity();
    }

    size_t Tile::getMendianeQuantity(void) const
    {
        return _mendianeContainer->getQuantity();
    }

    size_t Tile::getPhirasQuantity(void) const
    {
        return _phirasContainer->getQuantity();
    }

    size_t Tile::getThystameQuantity(void) const
    {
        return _thystameContainer->getQuantity();
    }
}
