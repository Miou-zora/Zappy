/*
** EPITECH PROJECT, 2023
** GUI
** File description:
** MendianeContainer
*/

#pragma once
#include "Container.hpp"

namespace GUI::Game {
    class MendianeContainer : virtual public Container {
        public:
            MendianeContainer(size_t quantity = 0, size_t maxSize = size_t(-1)): Container(quantity, maxSize) {};
            virtual ~MendianeContainer(void) = default;

            void update(void);
            void load();
            void draw(std::shared_ptr<GUI::Graphic::Object::Camera> camera);
    };
}
