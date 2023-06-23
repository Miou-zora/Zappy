/*
** EPITECH PROJECT, 2023
** GUI
** File description:
** DeraumereContainer
*/

#pragma once
#include "Container.hpp"

namespace GUI::Game {
    class DeraumereContainer : virtual public Container {
        public:
            DeraumereContainer(size_t quantity = 0, size_t maxSize = size_t(-1), std::shared_ptr<GUI::Graphic::Object::Model> model = std::make_shared<GUI::Graphic::Object::Model>(LoadModelFromMesh(GenMeshCube(1, 1, 1)), BLUE)): Container(quantity, maxSize, model) {};
            DeraumereContainer(std::shared_ptr<GUI::Graphic::Object::Model> model): Container(0, size_t(-1), model) {};
            virtual ~DeraumereContainer(void) = default;
    };
}
