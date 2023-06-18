/*
** EPITECH PROJECT, 2023
** GUI
** File description:
** PhirasContainer
*/

#pragma once
#include "Container.hpp"

namespace GUI::Game {
    class PhirasContainer : virtual public Container {
        public:
            PhirasContainer(size_t quantity = 0, size_t maxSize = size_t(-1)): Container(quantity, maxSize) {};
            virtual ~PhirasContainer(void) = default;

            void update(void);
            void load(std::shared_ptr<GUI::Graphic::Program> _program);
            void draw(std::shared_ptr<GUI::Graphic::Object::Camera> camera);
    };
}
