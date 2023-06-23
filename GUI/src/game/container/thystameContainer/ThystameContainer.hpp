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
            ThystameContainer(size_t quantity = 0, size_t maxSize = size_t(-1), ::Model model = LoadModelFromMesh(GenMeshCube(1, 1, 1))): Container(quantity, maxSize, model) {};
            ThystameContainer(::Model model): Container(0, size_t(-1), model) {};
            virtual ~ThystameContainer(void) = default;
    };
}
