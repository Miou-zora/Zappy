/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** KillButton
*/

#include "KillButton.hpp"
#include <iostream>
#include "Request.hpp"

namespace GUI::Game::Button {
    void KillButton::click(void)
    {
        if (_selected_entity == nullptr)
            return;
        std::shared_ptr<GUI::Game::Player> player = std::dynamic_pointer_cast<GUI::Game::Player>(_selected_entity);
        if (player == nullptr)
            return;
        _client->addRequest(std::make_shared<GUI::Network::Request>("kil " + std::to_string(player->getId())));
    }

    void KillButton::draw(void)
    {
        if (_selected_entity == nullptr)
            return;
        std::shared_ptr<GUI::Game::Player> player = std::dynamic_pointer_cast<GUI::Game::Player>(_selected_entity);
        if (player == nullptr)
            return;
        AButton::draw();
    }
}
