/*
** EPITECH PROJECT, 2023
** GUI
** File description:
** LinemateContainer
*/

#include "LinemateContainer.hpp"

namespace GUI::Game {
    void LinemateContainer::update(void)
    {
        Container::update();
    }

    void LinemateContainer::load()
    {
        Container::load();
    }

    void LinemateContainer::draw(std::shared_ptr<GUI::Graphic::Object::Camera> camera)
    {
        Container::draw(camera);
    }
}
