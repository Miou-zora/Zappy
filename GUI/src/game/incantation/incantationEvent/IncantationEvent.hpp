/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** IncantationEvent
*/

#pragma once
#include "IEvent.hpp"
#include "raylib.h"

namespace GUI::Game {
    class IncantationEvent : public IEvent {
        public:
            IncantationEvent(int level, Vector3 pos);
            ~IncantationEvent();

            void draw(std::shared_ptr<GUI::Graphic::Object::Camera> camera);
            void update(const double &deltaTime);
            bool isEnded(void);
        private:
            Texture2D _texture;
            float _size;
            Vector3 _pos;
            float _timer;
            static constexpr float _maxSize = 1;
            static constexpr float _minSize = 0.5;
            static constexpr float _duration = 1;
    };
}
