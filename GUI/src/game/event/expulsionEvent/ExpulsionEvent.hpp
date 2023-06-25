/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** ExpulsionEvent
*/

#pragma once
#include "IEvent.hpp"
#include "raylib.h"

namespace GUI::Game {
    class ExpulsionEvent : public IEvent {
        public:
            ExpulsionEvent(Vector3 pos);
            ~ExpulsionEvent();

            void draw(std::shared_ptr<GUI::Graphic::Object::Camera> camera);
            void update(const double &deltaTime);
            bool isEnded(void);
        private:
            Texture2D _texture;
            float _size;
            Vector3 _pos;
            float _timer;
    };
}
