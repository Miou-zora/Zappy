/*
** EPITECH PROJECT, 2023
** GUI
** File description:
** LinemateContainer
*/

#pragma once
#include "Container.hpp"

namespace GUI::Game {
    class LinemateContainer : virtual public Container {
        public:
            LinemateContainer(size_t quantity = 0, size_t maxSize = size_t(-1), std::shared_ptr<GUI::Graphic::Object::Model> model = std::make_shared<GUI::Graphic::Object::Model>(LoadModelFromMesh(GenMeshCube(1, 1, 1)), GREEN)): Container(quantity, maxSize, model) {};
            LinemateContainer(std::shared_ptr<GUI::Graphic::Object::Model> model): Container(0, size_t(-1), model) {};
            virtual ~LinemateContainer(void) = default;
    };
}
