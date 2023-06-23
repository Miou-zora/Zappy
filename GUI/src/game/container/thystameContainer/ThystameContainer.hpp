/*
** EPITECH PROJECT, 2023
** GUI
** File description:
** ThystameContainer
*/

#pragma once
#include "Container.hpp"
#include <memory>

namespace GUI::Game {
    class ThystameContainer : virtual public Container {
        public:
            ThystameContainer(std::size_t quantity = 0, size_t maxSize = size_t(-1), std::shared_ptr<GUI::Graphic::Object::Model> model = std::make_shared<GUI::Graphic::Object::Model>(LoadModelFromMesh(GenMeshCube(1, 1, 1)), GOLD)): Container(quantity, maxSize, model) {};
            ThystameContainer(std::shared_ptr<GUI::Graphic::Object::Model> model): Container(0, size_t(-1), model) {};
            virtual ~ThystameContainer(void) = default;
    };
}
