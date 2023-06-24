/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** IncantationEvent
*/

#include "IncantationEvent.hpp"
#include <string>
#include <iostream>
#include "raymath.h"

namespace GUI::Game {
    IncantationEvent::IncantationEvent(int level, Vector3 pos): _pos(pos), _timer(_duration)
    {
        std::string path = "assets/incantation/incantation" + std::to_string(level + 1) + ".png";
        _texture = LoadTexture(path.c_str());
        if (!IsTextureReady(_texture)) {
            path = "../" + path;
            _texture = LoadTexture(path.c_str());
            if (!IsTextureReady(_texture))
                std::cerr << "Error: Could not load texture: " << path << std::endl;
        }
        _size = 1;
    }

    IncantationEvent::~IncantationEvent()
    {
        if (IsTextureReady(_texture))
            UnloadTexture(_texture);
    }

    void IncantationEvent::draw(std::shared_ptr<GUI::Graphic::Object::Camera> camera)
    {
        if (IsTextureReady(_texture)) {
            BeginMode3D(*camera->getCamera());
                DrawBillboard(*camera->getCamera(), _texture, _pos, _size, WHITE);
            EndMode3D();
        }
    }

    void IncantationEvent::update(const double &deltaTime)
    {
        if (_timer > 0) {
            _timer -= deltaTime;
            _size = Lerp(_minSize, _maxSize, _timer/_duration);
        }
    }

    bool IncantationEvent::isEnded(void)
    {
        return _timer <= 0;
    }
}
