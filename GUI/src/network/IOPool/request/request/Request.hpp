/*
** EPITECH PROJECT, 2023
** GUI
** File description:
** Request
*/

#pragma once
#include "IRequest.hpp"

namespace GUI::Network {
    class Request : virtual public IRequest {
        public:
            Request(const std::string &request): _request(request) {};
            ~Request() = default;

            const std::string &get(void) { return _request; };

        private:
            std::string _request;
    };
}
