/*
** EPITECH PROJECT, 2023
** GUI
** File description:
** FoodContainer
*/

#include "FoodContainer.hpp"

namespace GUI::Game {
    void FoodContainer::update(void)
    {
        Container::update();
    }

    void FoodContainer::load()
    {
        Container::load();
    }

    void FoodContainer::draw(std::shared_ptr<GUI::Graphic::Object::Camera> camera)
    {
        Container::draw(camera);
    }
}
