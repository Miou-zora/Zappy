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
            LinemateContainer(size_t quantity = 0, size_t maxSize = size_t(-1), ::Model model = LoadModelFromMesh(GenMeshCube(1, 1, 1))): Container(quantity, maxSize, model) {};
            LinemateContainer(::Model model): Container(0, size_t(-1), model) {};
            virtual ~LinemateContainer(void) = default;

            void update(void);
            void draw(void);
    };
}
