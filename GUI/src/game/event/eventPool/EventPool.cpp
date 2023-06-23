/*
** EPITECH PROJECT, 2023
** GUI
** File description:
** EventPool
*/

#include "EventPool.hpp"
#include "IEvent.hpp"

namespace GUI::Game {
    void EventPool::drawEvents(std::shared_ptr<GUI::Graphic::Object::Camera> camera)
    {
        for (auto &event : _events)
            event->draw(camera);
    }

    void EventPool::updateEvents(void)
    {
        for (auto &event : _events)
            event->update();
        for (std::size_t index = 0; index < _events.size(); index++) {
            if (_events[index]->isEnded()) {
                _events.erase(_events.begin() + index);
                index--;
            }
        }
    }

    void EventPool::addEvent(std::shared_ptr<IEvent> event)
    {
        _events.push_back(event);
    }
}
