/*
** EPITECH PROJECT, 2023
** GUI
** File description:
** IRequest
*/

#pragma once
#include <string>

namespace GUI::Network {
    class IRequest {
        public:
            virtual const std::string &get() = 0;
    };
}
