/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** ExpulsionEvent
*/

#include "ExpulsionEvent.hpp"
#include <string>
#include <iostream>
#include "raymath.h"

namespace GUI::Game {
    ExpulsionEvent::ExpulsionEvent(Vector3 pos): _pos(pos), _timer(0.3)
    {
        std::string path = "assets/expulsionEvent/expulsionEvent.png";
        _texture = LoadTexture(path.c_str());
        if (!IsTextureReady(_texture)) {
            path = "../" + path;
            _texture = LoadTexture(path.c_str());
            if (!IsTextureReady(_texture))
                std::cerr << "Error: Could not load texture: " << path << std::endl;
        }
        _size = 1;
    }

    ExpulsionEvent::~ExpulsionEvent()
    {
        if (IsTextureReady(_texture))
            UnloadTexture(_texture);
    }

    void ExpulsionEvent::draw(std::shared_ptr<GUI::Graphic::Object::Camera> camera)
    {
        if (IsTextureReady(_texture)) {
            BeginMode3D(*camera->getCamera());
                DrawBillboard(*camera->getCamera(), _texture, _pos, _size, WHITE);
            EndMode3D();
        }
    }

    void ExpulsionEvent::update(const double &deltaTime)
    {
        if (_timer > 0) {
            _timer -= deltaTime;
        }
    }

    bool ExpulsionEvent::isEnded(void)
    {
        return _timer <= 0;
    }
}
