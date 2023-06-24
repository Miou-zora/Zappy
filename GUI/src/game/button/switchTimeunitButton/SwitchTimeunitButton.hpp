/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** SwitchTimeunitButton
*/

#pragma once
#include "Camera.hpp"
#include "AButton.hpp"
#include "IOPooledClient.hpp"
#include <functional>

namespace GUI::Game::Button {
    class SwitchTimeunitButton : public GUI::Graphic::AButton {
        public:
            SwitchTimeunitButton(std::shared_ptr<GUI::Network::IOPooledClient> client, std::size_t timeunit, const Vector2 &pos = {0, 0}, const Vector2 &size = {0, 0}, const std::string &texturePath = "assets/button/quitButton.png"): AButton(texturePath, pos, size), _client(client), _timeunit(timeunit) {};
            ~SwitchTimeunitButton(void) = default;

            void click(void) override;
        private:
            std::shared_ptr<GUI::Network::IOPooledClient> _client;
            std::size_t _timeunit;
    };
}
