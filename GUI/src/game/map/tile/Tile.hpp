/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** Tile
*/

#pragma once
#include <glm/vec3.hpp>
#include "Model.hpp"
#include "Object.hpp"
#include "FoodContainer.hpp"
#include "LinemateContainer.hpp"
#include "DeraumereContainer.hpp"
#include "SiburContainer.hpp"
#include "MendianeContainer.hpp"
#include "PhirasContainer.hpp"
#include "ThystameContainer.hpp"

namespace GUI::Game {
    class Tile : virtual public GUI::Graphic::Object::Object {
        public:
            Tile(void);
            Tile(int x, int z);
            Tile(int x, int y, int z);
            Tile(const glm::vec3 &pos);
            Tile(const Tile &tile) = default;
            ~Tile(void) = default;

            void load(void);
            void draw(std::shared_ptr<GUI::Graphic::Object::Camera> camera);
            void update(void);

            void setProgram(std::shared_ptr<GUI::Graphic::Program> program);
            void loadProgram(void);

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

        private:
            std::shared_ptr<GUI::Graphic::Object::Model> _model;
            std::shared_ptr<GUI::Graphic::Program> _program;
            std::shared_ptr<GUI::Game::FoodContainer> _foodContainer;
            std::shared_ptr<GUI::Game::LinemateContainer> _linemateContainer;
            std::shared_ptr<GUI::Game::DeraumereContainer> _deraumereContainer;
            std::shared_ptr<GUI::Game::SiburContainer> _siburContainer;
            std::shared_ptr<GUI::Game::MendianeContainer> _mendianeContainer;
            std::shared_ptr<GUI::Game::PhirasContainer> _phirasContainer;
            std::shared_ptr<GUI::Game::ThystameContainer> _thystameContainer;
    };
}
