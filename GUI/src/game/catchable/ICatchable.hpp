/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** ICatchable
*/

#pragma once
#include "raylib.h"
#include <memory>
#include "Camera.hpp"

namespace GUI::Game {
    class ICatchable {
        public:
            virtual ~ICatchable(void) = default;
            virtual void drawInfo(std::shared_ptr<GUI::Graphic::Object::Camera> _camera) = 0;
            virtual std::shared_ptr<BoundingBox> getBoundingBox(void) = 0;
    };
}
