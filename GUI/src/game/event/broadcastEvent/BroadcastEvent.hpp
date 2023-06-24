/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** BroadcastEvent
*/

#pragma once
#include "IEvent.hpp"
#include "raylib.h"

namespace GUI::Game {
    class BroadcastEvent : public IEvent {
        public:
            BroadcastEvent(Vector3 pos, const std::string &message);
            ~BroadcastEvent();

            void draw(std::shared_ptr<GUI::Graphic::Object::Camera> camera);
            void update(const double &deltaTime);
            bool isEnded(void);
        private:
            Texture2D _texture;
            float _size;
            Vector3 _pos;
            float _timer;
            std::string _message;
    };
}
