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

    void ThystameContainer::load(std::shared_ptr<GUI::Graphic::Program> _program)
    {
        Container::load(_program);
    }

    void ThystameContainer::draw(std::shared_ptr<GUI::Graphic::Object::Camera> camera)
    {
        Container::draw(camera);
    }
}
