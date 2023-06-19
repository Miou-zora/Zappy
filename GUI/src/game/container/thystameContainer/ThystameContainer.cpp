/*
** EPITECH PROJECT, 2023
** GUI
** File description:
** ThystameContainer
*/

#include "ThystameContainer.hpp"

namespace GUI::Game {
    void ThystameContainer::update(void)
    {
        Container::update();
    }

    void ThystameContainer::load()
    {
        Container::load();
    }

    void ThystameContainer::draw(std::shared_ptr<GUI::Graphic::Object::Camera> camera)
    {
        Container::draw(camera);
    }
}
