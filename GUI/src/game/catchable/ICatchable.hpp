/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** ICatchable
*/

#pragma once
#include "raylib.h"

namespace GUI::Game {
    class ICatchable {
        public:
            virtual ~ICatchable(void) = default;
            virtual void drawInfo(void) = 0;
            virtual BoundingBox getBoundingBox(void) = 0;
    };
}
