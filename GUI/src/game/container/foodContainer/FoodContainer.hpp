/*
** EPITECH PROJECT, 2023
** GUI
** File description:
** FoodContainer
*/

#pragma once
#include "Container.hpp"
#include <memory>

namespace GUI::Game {
    class FoodContainer : virtual public Container {
        public:
            FoodContainer(std::size_t quantity = 0, size_t maxSize = size_t(-1), std::shared_ptr<GUI::Graphic::Object::Model> model = std::make_shared<GUI::Graphic::Object::Model>(LoadModelFromMesh(GenMeshCube(1, 1, 1)), BROWN)): Container(quantity, maxSize, model) {};
            FoodContainer(std::shared_ptr<GUI::Graphic::Object::Model> model): Container(0, size_t(-1), model) {};
            virtual ~FoodContainer(void) = default;
    };
}
