/*
** EPITECH PROJECT, 2023
** GUI
** File description:
** DeraumereContainer
*/

#include "DeraumereContainer.hpp"

namespace GUI::Game {
    void DeraumereContainer::update(void)
    {
        Container::update();
    }

    void DeraumereContainer::load()
    {
        Container::load();
    }

    void DeraumereContainer::draw(std::shared_ptr<GUI::Graphic::Object::Camera> camera)
    {
        Container::draw(camera);
    }
}
