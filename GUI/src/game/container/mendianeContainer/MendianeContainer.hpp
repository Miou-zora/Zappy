/*
** EPITECH PROJECT, 2023
** GUI
** File description:
** MendianeContainer
*/

#pragma once
#include "Container.hpp"

namespace GUI::Game {
    class MendianeContainer : virtual public Container {
        public:
            MendianeContainer(size_t quantity = 0, size_t maxSize = size_t(-1), std::shared_ptr<GUI::Graphic::Object::Model> model = std::make_shared<GUI::Graphic::Object::Model>(LoadModelFromMesh(GenMeshCube(1, 1, 1)), BEIGE)): Container(quantity, maxSize, model) {};
            MendianeContainer(std::shared_ptr<GUI::Graphic::Object::Model> model): Container(0, size_t(-1), model) {};
            virtual ~MendianeContainer(void) = default;
    };
}
