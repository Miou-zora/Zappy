/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** Tile
*/

#include "Tile.hpp"
#include <iostream>

namespace GUI::Game {
    Tile::Tile(void):
        Object(),
        _model(nullptr),
        _foodContainer(std::make_shared<GUI::Game::FoodContainer>(LoadModelFromMesh(GenMeshCube(1, 1, 1)))),
        _linemateContainer(std::make_shared<GUI::Game::LinemateContainer>(LoadModelFromMesh(GenMeshCube(1, 1, 1)))),
        _deraumereContainer(std::make_shared<GUI::Game::DeraumereContainer>(LoadModelFromMesh(GenMeshCube(1, 1, 1)))),
        _siburContainer(std::make_shared<GUI::Game::SiburContainer>(LoadModelFromMesh(GenMeshCube(1, 1, 1)))),
        _mendianeContainer(std::make_shared<GUI::Game::MendianeContainer>(LoadModelFromMesh(GenMeshCube(1, 1, 1)))),
        _phirasContainer(std::make_shared<GUI::Game::PhirasContainer>(LoadModelFromMesh(GenMeshCube(1, 1, 1)))),
        _thystameContainer(std::make_shared<GUI::Game::ThystameContainer>(LoadModelFromMesh(GenMeshCube(1, 1, 1))))
    {

    }

    Tile::Tile(Vector2 tileIndexes, Vector3 pos):
        Object(pos),
        _model(nullptr),
        _foodContainer(std::make_shared<GUI::Game::FoodContainer>(LoadModelFromMesh(GenMeshCube(1, 1, 1)))),
        _linemateContainer(std::make_shared<GUI::Game::LinemateContainer>(LoadModelFromMesh(GenMeshCube(1, 1, 1)))),
        _deraumereContainer(std::make_shared<GUI::Game::DeraumereContainer>(LoadModelFromMesh(GenMeshCube(1, 1, 1)))),
        _siburContainer(std::make_shared<GUI::Game::SiburContainer>(LoadModelFromMesh(GenMeshCube(1, 1, 1)))),
        _mendianeContainer(std::make_shared<GUI::Game::MendianeContainer>(LoadModelFromMesh(GenMeshCube(1, 1, 1)))),
        _phirasContainer(std::make_shared<GUI::Game::PhirasContainer>(LoadModelFromMesh(GenMeshCube(1, 1, 1)))),
        _thystameContainer(std::make_shared<GUI::Game::ThystameContainer>(LoadModelFromMesh(GenMeshCube(1, 1, 1)))),
        _tileIndexes(tileIndexes)
    {
        _foodContainer->getModel()->setPos(getPos().x - 0.4, getPos().y + 0.5, getPos().z);
        _foodContainer->getModel()->setScale(0.1, 0.1, 0.1);
        _linemateContainer->getModel()->setPos(getPos().x, getPos().y + 0.5, getPos().z + 0.4);
        _linemateContainer->getModel()->setScale(0.1, 0.1, 0.1);
        _deraumereContainer->getModel()->setPos(getPos().x + 0.4, getPos().y + 0.5, getPos().z + 0.4);
        _deraumereContainer->getModel()->setScale(0.1, 0.1, 0.1);
        _siburContainer->getModel()->setPos(getPos().x + 0.4, getPos().y + 0.5, getPos().z);
        _siburContainer->getModel()->setScale(0.1, 0.1, 0.1);
        _mendianeContainer->getModel()->setPos(getPos().x + 0.4, getPos().y + 0.5, getPos().z - 0.4);
        _mendianeContainer->getModel()->setScale(0.1, 0.1, 0.1);
        _phirasContainer->getModel()->setPos(getPos().x, getPos().y + 0.5, getPos().z - 0.4);
        _phirasContainer->getModel()->setScale(0.1, 0.1, 0.1);
        _thystameContainer->getModel()->setPos(getPos().x - 0.4, getPos().y + 0.5, getPos().z - 0.4);
        _thystameContainer->getModel()->setScale(0.1, 0.1, 0.1);
    }

    void Tile::setModel(std::shared_ptr<GUI::Graphic::Object::Model> model)
    {
        _model = model;
    }

    std::shared_ptr<GUI::Graphic::Object::Model> Tile::getModel(void) const
    {
        return _model;
    }

    void Tile::draw(std::shared_ptr<GUI::Graphic::Object::Camera> camera)
    {
        BeginMode3D(*camera->getCamera());
            DrawCube(getPos(), 0.95, 0.95, 0.95, RED);
            DrawCubeWires(getPos(), 0.95, 0.95, 0.95, BLACK);
        EndMode3D();
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
        _model->update();
        _foodContainer->update();
        _linemateContainer->update();
        _deraumereContainer->update();
        _siburContainer->update();
        _mendianeContainer->update();
        _phirasContainer->update();
        _thystameContainer->update();
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

    std::shared_ptr<GUI::Game::FoodContainer> Tile::getFoodContainer(void) const
    {
        return _foodContainer;
    }

    std::shared_ptr<GUI::Game::LinemateContainer> Tile::getLinemateContainer(void) const
    {
        return _linemateContainer;
    }

    std::shared_ptr<GUI::Game::DeraumereContainer> Tile::getDeraumereContainer(void) const
    {
        return _deraumereContainer;
    }

    std::shared_ptr<GUI::Game::SiburContainer> Tile::getSiburContainer(void) const
    {
        return _siburContainer;
    }

    std::shared_ptr<GUI::Game::MendianeContainer> Tile::getMendianeContainer(void) const
    {
        return _mendianeContainer;
    }

    std::shared_ptr<GUI::Game::PhirasContainer> Tile::getPhirasContainer(void) const
    {
        return _phirasContainer;
    }

    std::shared_ptr<GUI::Game::ThystameContainer> Tile::getThystameContainer(void) const
    {
        return _thystameContainer;
    }
}
