/*
** EPITECH PROJECT, 2023
** GUI
** File description:
** Player
*/

#pragma once
#include <glm/vec2.hpp>
#include "Model.hpp"
#include <string>
#include "Camera.hpp"

namespace GUI::Game {
    enum Orientation {
        NORTH = 1,
        EAST,
        SOUTH,
        WEST
    };
    class Player {
        public:
            Player(const std::string &teamName, int id, glm::ivec2 position, Orientation orientation, size_t level = 1);

            ~Player(void) = default;

            void load(std::shared_ptr<GUI::Graphic::Program> _program);
            void update(void);
            void render(std::shared_ptr<GUI::Graphic::Object::Camera> camera);

            void setPosition(glm::ivec2 position) { _position = position; };
            void setOrientation(Orientation orientation) { _orientation = orientation; };
            void setLevel(size_t level) { _level = level; };

            const std::string &getTeamName(void) const { return _teamName; };
            int getId(void) const { return _id; };
            glm::ivec2 getPosition(void) const { return _position; };
            Orientation getOrientation(void) const { return _orientation; };
            size_t getLevel(void) const { return _level; };

        private:
            const int _id;
            const std::string _teamName;
            glm::uvec2 _position;
            size_t _level;
            Orientation _orientation;
            std::shared_ptr<GUI::Graphic::Object::Model> _model;
    };
}
