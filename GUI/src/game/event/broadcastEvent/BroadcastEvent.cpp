/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** BroadcastEvent
*/

#include "BroadcastEvent.hpp"
#include "IncantationEvent.hpp"
#include <string>
#include <iostream>
#include "raymath.h"

namespace GUI::Game {
    BroadcastEvent::BroadcastEvent(Vector3 pos, const std::string &message): _pos(pos), _timer(0.3), _message(message)
    {
        std::string path = "assets/broadcastEvent/broadcastEvent.png";
        _texture = LoadTexture(path.c_str());
        if (!IsTextureReady(_texture)) {
            path = "../" + path;
            _texture = LoadTexture(path.c_str());
            if (!IsTextureReady(_texture))
                std::cerr << "Error: Could not load texture: " << path << std::endl;
        }
        _size = 1;
    }

    BroadcastEvent::~BroadcastEvent()
    {
        if (IsTextureReady(_texture))
            UnloadTexture(_texture);
    }

    void BroadcastEvent::draw(std::shared_ptr<GUI::Graphic::Object::Camera> camera)
    {
        if (IsTextureReady(_texture)) {
            BeginMode3D(*camera->getCamera());
                DrawBillboard(*camera->getCamera(), _texture, _pos, _size, WHITE);
            EndMode3D();
        }
    }

    void BroadcastEvent::update(const double &deltaTime)
    {
        if (_timer > 0) {
            _timer -= deltaTime;
        }
    }

    bool BroadcastEvent::isEnded(void)
    {
        return _timer <= 0;
    }
}
