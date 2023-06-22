/*
** EPITECH PROJECT, 2023
** GUI
** File description:
** FoodContainer
*/

#pragma once
#include "Container.hpp"
#include <memory>

namespace GUI::Game {
    class FoodContainer : virtual public Container {
        public:
            FoodContainer(size_t quantity = 0, size_t maxSize = size_t(-1), ::Model model = LoadModelFromMesh(GenMeshCube(1, 1, 1))): Container(quantity, maxSize, model) {};
            FoodContainer(::Model model): Container(0, size_t(-1), model) {};
            virtual ~FoodContainer(void) = default;

            void update(void);
            void draw(void);
    };
}
