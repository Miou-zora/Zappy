/*
** EPITECH PROJECT, 2023
** GUI
** File description:
** Player
*/

#pragma once
#include "Model.hpp"
#include <string>
#include "Camera.hpp"
#include "FoodContainer.hpp"
#include "LinemateContainer.hpp"
#include "DeraumereContainer.hpp"
#include "SiburContainer.hpp"
#include "MendianeContainer.hpp"
#include "PhirasContainer.hpp"
#include "ThystameContainer.hpp"

namespace GUI::Game {
    enum Orientation {
        NORTH = 1,
        EAST,
        SOUTH,
        WEST
    };
    class Player {
        public:
            Player(const std::string &teamName, int id, Vector2 position, Orientation orientation, size_t level = 1);

            ~Player(void) = default;

            void update(void);
            void render(std::shared_ptr<GUI::Graphic::Object::Camera> camera);

            void setPosition(Vector2 position) { _position = position; };
            void setOrientation(Orientation orientation) { _orientation = orientation; };
            void setLevel(size_t level) { _level = level; };
            void setPositionDiff(Vector2 positionDiff) { _positionDiff = positionDiff; };

            const std::string &getTeamName(void) const { return _teamName; };
            int getId(void) const { return _id; };
            Vector2 getPosition(void) const { return _position; };
            Orientation getOrientation(void) const { return _orientation; };
            size_t getLevel(void) const { return _level; };
            Vector2 getPositionDiff(void) const { return _positionDiff; };

            std::shared_ptr<GUI::Game::FoodContainer> getFoodContainer(void) const { return _foodContainer; };
            std::shared_ptr<GUI::Game::LinemateContainer> getLinemateContainer(void) const { return _linemateContainer; };
            std::shared_ptr<GUI::Game::DeraumereContainer> getDeraumereContainer(void) const { return _deraumereContainer; };
            std::shared_ptr<GUI::Game::SiburContainer> getSiburContainer(void) const { return _siburContainer; };
            std::shared_ptr<GUI::Game::MendianeContainer> getMendianeContainer(void) const { return _mendianeContainer; };
            std::shared_ptr<GUI::Game::PhirasContainer> getPhirasContainer(void) const { return _phirasContainer; };
            std::shared_ptr<GUI::Game::ThystameContainer> getThystameContainer(void) const { return _thystameContainer; };

        private:
            const int _id;
            const std::string _teamName;
            Vector2 _position;
            Vector2 _positionDiff;
            size_t _level;
            Orientation _orientation;
            std::shared_ptr<GUI::Graphic::Object::Model> _model;

            std::shared_ptr<GUI::Game::FoodContainer> _foodContainer;
            std::shared_ptr<GUI::Game::LinemateContainer> _linemateContainer;
            std::shared_ptr<GUI::Game::DeraumereContainer> _deraumereContainer;
            std::shared_ptr<GUI::Game::SiburContainer> _siburContainer;
            std::shared_ptr<GUI::Game::MendianeContainer> _mendianeContainer;
            std::shared_ptr<GUI::Game::PhirasContainer> _phirasContainer;
            std::shared_ptr<GUI::Game::ThystameContainer> _thystameContainer;
    };
}
