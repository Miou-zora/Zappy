/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** SwitchTimeunitButton
*/

#include "SwitchTimeunitButton.hpp"
#include "Request.hpp"
#include <iostream>

namespace GUI::Game::Button {
    void SwitchTimeunitButton::click(void)
    {
        std::shared_ptr<GUI::Network::Request> request = std::make_shared<GUI::Network::Request>("sst " + std::to_string(_timeunit) + "\n");
        _client->addRequest(request);
    }
}
