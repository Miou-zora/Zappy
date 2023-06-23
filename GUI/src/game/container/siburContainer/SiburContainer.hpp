/*
** EPITECH PROJECT, 2023
** GUI
** File description:
** SiburContainer
*/

#pragma once
#include "Container.hpp"

namespace GUI::Game {
    class SiburContainer : virtual public Container {
        public:
            SiburContainer(size_t quantity = 0, size_t maxSize = size_t(-1), std::shared_ptr<GUI::Graphic::Object::Model> model = std::make_shared<GUI::Graphic::Object::Model>(LoadModelFromMesh(GenMeshCube(1, 1, 1)), PURPLE)): Container(quantity, maxSize, model) {};
            SiburContainer(std::shared_ptr<GUI::Graphic::Object::Model> model): Container(0, size_t(-1), model) {};
            virtual ~SiburContainer(void) = default;
    };
}
