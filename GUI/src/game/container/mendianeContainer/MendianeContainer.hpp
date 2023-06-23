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
            MendianeContainer(size_t quantity = 0, size_t maxSize = size_t(-1), ::Model model = LoadModelFromMesh(GenMeshCube(1, 1, 1))): Container(quantity, maxSize, model) {};
            MendianeContainer(::Model model): Container(0, size_t(-1), model) {};
            virtual ~MendianeContainer(void) = default;
    };
}
