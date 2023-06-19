/*
** EPITECH PROJECT, 2023
** GUI
** File description:
** MendianeContainer
*/

#include "MendianeContainer.hpp"

namespace GUI::Game {
    void MendianeContainer::update(void)
    {
        Container::update();
    }

    void MendianeContainer::load()
    {
        Container::load();
    }

    void MendianeContainer::draw(std::shared_ptr<GUI::Graphic::Object::Camera> camera)
    {
        Container::draw(camera);
    }
}
