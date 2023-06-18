/*
** EPITECH PROJECT, 2023
** GUI
** File description:
** FoodContainer
*/

#pragma once
#include "Container.hpp"
#include <memory>

namespace GUI::Game {
    class FoodContainer : virtual public Container {
        FoodContainer(size_t quantity = 0, size_t maxSize = size_t(-1)): Container(quantity, maxSize) {};
        virtual ~FoodContainer(void) = default;

        void update(void);
        void load(std::shared_ptr<GUI::Graphic::Program> _program);
        void draw(std::shared_ptr<GUI::Graphic::Object::Camera> camera);
    };
}