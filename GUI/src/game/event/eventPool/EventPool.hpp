/*
** EPITECH PROJECT, 2023
** GUI
** File description:
** EventPool
*/

#pragma once
#include <vector>
#include "IEvent.hpp"

namespace GUI::Game {
    class EventPool {
        public:
            EventPool(void) = default;
            ~EventPool(void) = default;

            void drawEvents(std::shared_ptr<GUI::Graphic::Object::Camera> camera);
            void updateEvents(const double &deltaTime);

            void addEvent(std::shared_ptr<IEvent> event);

        private:
            std::vector<std::shared_ptr<IEvent>> _events;
    };
}
