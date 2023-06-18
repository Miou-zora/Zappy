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

    void SiburContainer::load(std::shared_ptr<GUI::Graphic::Program> _program)
    {
        Container::load(_program);
    }

    void SiburContainer::draw(std::shared_ptr<GUI::Graphic::Object::Camera> camera)
    {
        Container::draw(camera);
    }
}
