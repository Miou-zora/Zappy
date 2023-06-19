/*
** EPITECH PROJECT, 2023
** GUI
** File description:
** SiburContainer
*/

#include "SiburContainer.hpp"

namespace GUI::Game {
    void SiburContainer::update(void)
    {
        Container::update();
    }

    void SiburContainer::load()
    {
        Container::load();
    }

    void SiburContainer::draw(std::shared_ptr<GUI::Graphic::Object::Camera> camera)
    {
        Container::draw(camera);
    }
}
