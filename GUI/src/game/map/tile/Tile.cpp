/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** Tile
*/

#include "Tile.hpp"
#include <iostream>
#include <utility>

namespace GUI::Game {
    Tile::Tile(void):
        Object(),
        _model(std::make_shared<GUI::Graphic::Object::Model>(LoadModelFromMesh(GenMeshCube(1, 1, 1)), RED)),
        _foodContainer(std::make_shared<GUI::Game::FoodContainer>()),
        _linemateContainer(std::make_shared<GUI::Game::LinemateContainer>()),
        _deraumereContainer(std::make_shared<GUI::Game::DeraumereContainer>()),
        _siburContainer(std::make_shared<GUI::Game::SiburContainer>()),
        _mendianeContainer(std::make_shared<GUI::Game::MendianeContainer>()),
        _phirasContainer(std::make_shared<GUI::Game::PhirasContainer>()),
        _thystameContainer(std::make_shared<GUI::Game::ThystameContainer>())
    {
    }

    Tile::Tile(Vector2 tileIndexes, Vector3 pos):
        Object(pos),
        _model(std::make_shared<GUI::Graphic::Object::Model>(LoadModelFromMesh(GenMeshCube(1, 1, 1)), RED)),
        _foodContainer(std::make_shared<GUI::Game::FoodContainer>()),
        _linemateContainer(std::make_shared<GUI::Game::LinemateContainer>()),
        _deraumereContainer(std::make_shared<GUI::Game::DeraumereContainer>()),
        _siburContainer(std::make_shared<GUI::Game::SiburContainer>()),
        _mendianeContainer(std::make_shared<GUI::Game::MendianeContainer>()),
        _phirasContainer(std::make_shared<GUI::Game::PhirasContainer>()),
        _thystameContainer(std::make_shared<GUI::Game::ThystameContainer>()),
        _tileIndexes(tileIndexes)
    {
        srand(time(NULL));
        _model->setPos(pos.x, pos.y, pos.z);
        _foodContainer->getModel()->setPos(getPos().x - 0.4 * (static_cast<float>(rand()) / static_cast<float>((RAND_MAX))), getPos().y + 0.5, getPos().z);
        _foodContainer->getModel()->setScale(0.1, 0.1, 0.1);
        _linemateContainer->getModel()->setPos(getPos().x, getPos().y + 0.5, getPos().z + 0.4 * (static_cast<float>(rand()) / static_cast<float>((RAND_MAX))));
        _linemateContainer->getModel()->setScale(0.1, 0.1, 0.1);
        _deraumereContainer->getModel()->setPos(getPos().x + 0.4 * (static_cast<float>(rand()) / static_cast<float>((RAND_MAX))), getPos().y + 0.5, getPos().z + 0.4 * (static_cast<float>(rand()) / static_cast<float>((RAND_MAX))));
        _deraumereContainer->getModel()->setScale(0.1, 0.1, 0.1);
        _siburContainer->getModel()->setPos(getPos().x + 0.4 * (static_cast<float>(rand()) / static_cast<float>((RAND_MAX))), getPos().y + 0.5, getPos().z);
        _siburContainer->getModel()->setScale(0.1, 0.1, 0.1);
        _mendianeContainer->getModel()->setPos(getPos().x + 0.4 * (static_cast<float>(rand()) / static_cast<float>((RAND_MAX))), getPos().y + 0.5, getPos().z - 0.4 * (static_cast<float>(rand()) / static_cast<float>((RAND_MAX))));
        _mendianeContainer->getModel()->setScale(0.1, 0.1, 0.1);
        _phirasContainer->getModel()->setPos(getPos().x, getPos().y + 0.5, getPos().z - 0.4 * (static_cast<float>(rand()) / static_cast<float>((RAND_MAX))));
        _phirasContainer->getModel()->setScale(0.1, 0.1, 0.1);
        _thystameContainer->getModel()->setPos(getPos().x - 0.4 * (static_cast<float>(rand()) / static_cast<float>((RAND_MAX))), getPos().y + 0.5, getPos().z - 0.4 * (static_cast<float>(rand()) / static_cast<float>((RAND_MAX))));
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
        if (_model != nullptr) {
            BeginMode3D(*camera->getCamera());
                _model->draw(camera);
            EndMode3D();
        }
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

    void Tile::drawInfo(std::shared_ptr<GUI::Graphic::Object::Camera> _camera)
    {
        Vector3 scale = _model->getScale();
        if (_camera != nullptr) {
            scale.x += 0.01;
            scale.y += 0.01;
            scale.z += 0.01;
            BeginMode3D(*_camera->getCamera());
                DrawModelEx(*_model->getModel(), _model->getPos(), _model->getRot(), 1, scale, RAYWHITE);
            EndMode3D();
        }
        DrawText(("Tile: x=" + std::to_string(static_cast<int>(_tileIndexes.x)) + " y=" + std::to_string(static_cast<int>(_tileIndexes.y))).c_str(), 10, 10, 20, RAYWHITE);
        DrawText(("Food: " + std::to_string((_foodContainer->getQuantity()))).c_str(), 10, 30, 20, RAYWHITE);
        DrawText(("Linemate: " + std::to_string((_linemateContainer->getQuantity()))).c_str(), 10, 50, 20, RAYWHITE);
        DrawText(("Deraumere: " + std::to_string((_deraumereContainer->getQuantity()))).c_str(), 10, 70, 20, RAYWHITE);
        DrawText(("Sibur: " + std::to_string((_siburContainer->getQuantity()))).c_str(), 10, 90, 20, RAYWHITE);
        DrawText(("Mendiane: " + std::to_string((_mendianeContainer->getQuantity()))).c_str(), 10, 110, 20, RAYWHITE);
        DrawText(("Phiras: " + std::to_string((_phirasContainer->getQuantity()))).c_str(), 10, 130, 20, RAYWHITE);
        DrawText(("Thystame: " + std::to_string((_thystameContainer->getQuantity()))).c_str(), 10, 150, 20, RAYWHITE);
    }

    std::shared_ptr<BoundingBox> Tile::getBoundingBox(void)
    {
        if (_model == nullptr)
            return nullptr;
        return _model->getBoundingBox();
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
