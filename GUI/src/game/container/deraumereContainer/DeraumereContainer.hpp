/*
** EPITECH PROJECT, 2023
** GUI
** File description:
** DeraumereContainer
*/

#pragma once
#include "Container.hpp"

namespace GUI::Game {
    class DeraumereContainer : virtual public Container {
        public:
            DeraumereContainer(size_t quantity = 0, size_t maxSize = size_t(-1)): Container(quantity, maxSize) {};
            virtual ~DeraumereContainer(void) = default;

            void update(void);
            void load();
            void draw(std::shared_ptr<GUI::Graphic::Object::Camera> camera);
    };
}
