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
            PhirasContainer(size_t quantity = 0, size_t maxSize = size_t(-1), ::Model model = LoadModelFromMesh(GenMeshCube(1, 1, 1))): Container(quantity, maxSize, model) {};
            PhirasContainer(::Model model): Container(0, size_t(-1), model) {};
            virtual ~PhirasContainer(void) = default;

            void update(void);
            void draw(void);
    };
}
