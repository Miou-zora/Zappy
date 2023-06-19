/*
** EPITECH PROJECT, 2023
** GUI
** File description:
** PhirasContainer
*/

#include "PhirasContainer.hpp"

namespace GUI::Game {
    void PhirasContainer::update(void)
    {
        Container::update();
    }

    void PhirasContainer::load()
    {
        Container::load();
    }

    void PhirasContainer::draw(std::shared_ptr<GUI::Graphic::Object::Camera> camera)
    {
        Container::draw(camera);
    }
}
