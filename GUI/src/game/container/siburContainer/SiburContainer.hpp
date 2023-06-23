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
            SiburContainer(size_t quantity = 0, size_t maxSize = size_t(-1), ::Model model = LoadModelFromMesh(GenMeshCube(1, 1, 1))): Container(quantity, maxSize, model) {};
            SiburContainer(::Model model): Container(0, size_t(-1), model) {};
            virtual ~SiburContainer(void) = default;
    };
}
