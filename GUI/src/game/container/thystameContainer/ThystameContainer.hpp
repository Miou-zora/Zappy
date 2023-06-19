/*
** EPITECH PROJECT, 2023
** GUI
** File description:
** ThystameContainer
*/

#pragma once
#include "Container.hpp"
#include <memory>

namespace GUI::Game {
    class ThystameContainer : virtual public Container {
        public:
            ThystameContainer(size_t quantity = 0, size_t maxSize = size_t(-1)): Container(quantity, maxSize) {};
            virtual ~ThystameContainer(void) = default;

            void update(void);
            void load();
            void draw(std::shared_ptr<GUI::Graphic::Object::Camera> camera);
    };
}
