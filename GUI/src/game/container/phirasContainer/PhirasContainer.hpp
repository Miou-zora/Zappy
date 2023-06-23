/*
** EPITECH PROJECT, 2023
** GUI
** File description:
** PhirasContainer
*/

#pragma once
#include "Container.hpp"

namespace GUI::Game {
    class PhirasContainer : virtual public Container {
        public:
            PhirasContainer(size_t quantity = 0, size_t maxSize = size_t(-1), std::shared_ptr<GUI::Graphic::Object::Model> model = std::make_shared<GUI::Graphic::Object::Model>(LoadModelFromMesh(GenMeshCube(1, 1, 1)), PINK)): Container(quantity, maxSize, model) {};
            PhirasContainer(std::shared_ptr<GUI::Graphic::Object::Model> model): Container(0, size_t(-1), model) {};
            virtual ~PhirasContainer(void) = default;
    };
}
