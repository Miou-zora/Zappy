/*
** EPITECH PROJECT, 2023
** GUI
** File description:
** IEvent
*/

#pragma once
#include <memory>
#include "Camera.hpp"

namespace GUI::Game {
    class IEvent {
        public:
            virtual void draw(std::shared_ptr<GUI::Graphic::Object::Camera>) = 0;
            virtual void update(void) = 0;
            virtual bool isEnded(void) = 0;
    };
}
