/*
** EPITECH PROJECT, 2023
** GUI
** File description:
** LinemateContainer
*/

#pragma once
#include "Container.hpp"

namespace GUI::Game {
    class LinemateContainer : virtual public Container {
        public:
            LinemateContainer(size_t quantity = 0, size_t maxSize = size_t(-1)): Container(quantity, maxSize) {};
            virtual ~LinemateContainer(void) = default;

            void update(void);
            void load(std::shared_ptr<GUI::Graphic::Program> _program);
            void draw(std::shared_ptr<GUI::Graphic::Object::Camera> camera);
    };
}
