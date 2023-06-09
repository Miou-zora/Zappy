/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** SockaddrIn
*/

#include "SockaddrIn.hpp"
#include "ErrorManagement.hpp"

#include <iostream>

#include <netdb.h>

namespace GUI::Network {

    SockaddrIn::SockaddrIn(const std::string &host, const std::string &port, int addressFamily)
    {
        _addr.sin_family = addressFamily;
        hostent* hostname = gethostbyname(host.c_str());
        if (hostname == nullptr)
            throw NetworkException("Error: invalid hostname");
        _addr.sin_addr.s_addr = inet_addr(inet_ntoa(**(in_addr**)hostname->h_addr_list));
        if (_addr.sin_addr.s_addr == INADDR_NONE)
            throw NetworkException("Error: invalid ip");
        _addr.sin_port = htons(atoi(port.c_str()));
        if (_addr.sin_port == 0 && port != "0")
            throw NetworkException("Error: invalid port");
    }
}
