/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** KillButton
*/

#pragma once
#include "Camera.hpp"
#include "AButton.hpp"
#include "Player.hpp"
#include "IOPooledClient.hpp"

namespace GUI::Game::Button {
    class KillButton : public GUI::Graphic::AButton {
        public:
            KillButton(std::shared_ptr<GUI::Network::IOPooledClient> client, const std::shared_ptr<GUI::Game::ICatchable> &selected_entity, const Vector2 &pos = {0, 0}, const Vector2 &size = {0, 0}, const std::string &texturePath = "assets/button/quitButton.png"):
                AButton(texturePath, pos, size),
                _selected_entity(selected_entity),
                _client(client) {};
            ~KillButton(void) = default;

            void click(void) override;
            void draw(void);

        private:
            const std::shared_ptr<GUI::Game::ICatchable> &_selected_entity;
            std::shared_ptr<GUI::Network::IOPooledClient> _client;
    };
}
