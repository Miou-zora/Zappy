/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** Tile
*/

#pragma once
#include "Model.hpp"
#include "Object.hpp"
#include "FoodContainer.hpp"
#include "LinemateContainer.hpp"
#include "DeraumereContainer.hpp"
#include "SiburContainer.hpp"
#include "MendianeContainer.hpp"
#include "PhirasContainer.hpp"
#include "ThystameContainer.hpp"
#include "ICatchable.hpp"
#include "Player.hpp"

namespace GUI::Game {
    class Tile : virtual public GUI::Graphic::Object::Object, virtual public GUI::Game::ICatchable {
        public:
            Tile(const std::vector<std::shared_ptr<GUI::Game::Player>> &players);
            Tile(Vector2 tileIndexes, Vector3 pos, const std::vector<std::shared_ptr<GUI::Game::Player>> &players);
            ~Tile(void) = default;

            void draw(std::shared_ptr<GUI::Graphic::Object::Camera> camera);
            void update(void);

            void drawInfo(std::shared_ptr<GUI::Graphic::Object::Camera> camera);
            std::shared_ptr<BoundingBox> getBoundingBox(void);

            void setModel(std::shared_ptr<GUI::Graphic::Object::Model> model);
            std::shared_ptr<GUI::Graphic::Object::Model> getModel(void) const;

            void setFoodQuantity(size_t foodQuantity);
            void setLinemateQuantity(size_t linemateQuantity);
            void setDeraumereQuantity(size_t deraumereQuantity);
            void setSiburQuantity(size_t siburQuantity);
            void setMendianeQuantity(size_t mendianeQuantity);
            void setPhirasQuantity(size_t phirasQuantity);
            void setThystameQuantity(size_t thystameQuantity);

            size_t getFoodQuantity(void) const;
            size_t getLinemateQuantity(void) const;
            size_t getDeraumereQuantity(void) const;
            size_t getSiburQuantity(void) const;
            size_t getMendianeQuantity(void) const;
            size_t getPhirasQuantity(void) const;
            size_t getThystameQuantity(void) const;

            std::shared_ptr<GUI::Game::FoodContainer> getFoodContainer(void) const;
            std::shared_ptr<GUI::Game::LinemateContainer> getLinemateContainer(void) const;
            std::shared_ptr<GUI::Game::DeraumereContainer> getDeraumereContainer(void) const;
            std::shared_ptr<GUI::Game::SiburContainer> getSiburContainer(void) const;
            std::shared_ptr<GUI::Game::MendianeContainer> getMendianeContainer(void) const;
            std::shared_ptr<GUI::Game::PhirasContainer> getPhirasContainer(void) const;
            std::shared_ptr<GUI::Game::ThystameContainer> getThystameContainer(void) const;

            void setTileIndexes(const Vector2 &tileIndexes) { _tileIndexes = tileIndexes; };
            Vector2 getTileIndexes(void) const { return _tileIndexes; };

            std::shared_ptr<std::vector<std::shared_ptr<GUI::Game::Player>>> getPlayerOnTile(void) const;

        private:
            std::shared_ptr<GUI::Graphic::Object::Model> _model;
            std::shared_ptr<GUI::Game::FoodContainer> _foodContainer;
            std::shared_ptr<GUI::Game::LinemateContainer> _linemateContainer;
            std::shared_ptr<GUI::Game::DeraumereContainer> _deraumereContainer;
            std::shared_ptr<GUI::Game::SiburContainer> _siburContainer;
            std::shared_ptr<GUI::Game::MendianeContainer> _mendianeContainer;
            std::shared_ptr<GUI::Game::PhirasContainer> _phirasContainer;
            std::shared_ptr<GUI::Game::ThystameContainer> _thystameContainer;
            Vector2 _tileIndexes;
            const std::vector<std::shared_ptr<GUI::Game::Player>> &_players;
    };
}
