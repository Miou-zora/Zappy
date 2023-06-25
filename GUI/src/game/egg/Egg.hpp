/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** Egg
*/

#pragma once
#include "Model.hpp"
#include <string>
#include "Camera.hpp"
#include "Team.hpp"

namespace GUI::Game {
    class Egg {
        public:
            Egg(std::shared_ptr<GUI::Game::Team> teamName, int id, Vector2 position);

            ~Egg(void) = default;

            void update(void);
            void render(std::shared_ptr<GUI::Graphic::Object::Camera> camera);

            void setPosition(Vector2 position) { _position = position; };
            void setPositionDiff(Vector2 positionDiff) { _positionDiff = positionDiff; };

            std::shared_ptr<GUI::Game::Team> &getTeam(void) { return _team; };
            const std::shared_ptr<GUI::Game::Team> &getTeam(void) const { return _team; };
            int getId(void) const { return _id; };
            Vector2 getPosition(void) const { return _position; };
            Vector2 getPositionDiff(void) const { return _positionDiff; };
            std::shared_ptr<GUI::Graphic::Object::Model> getModel(void) const { return _model; };

        private:
            const int _id;
            std::shared_ptr<GUI::Game::Team> _team;
            Vector2 _position;
            Vector2 _positionDiff;
            std::shared_ptr<GUI::Graphic::Object::Model> _model;
            float _randomValueX;
            float _randomValueY;
    };
}
