/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** Client
*/

#include "Client.hpp"
#include "ErrorManagement.hpp"
#include <iostream>

namespace GUI::Network {
    Client::Client(const std::string &host):
        _socket(AF_INET, SOCK_STREAM, 0),
        _host(host)
    {
        _socket.bind(SockaddrIn(host, "0"));
    }

    void Client::connect(const std::string &server_ip, const std::string &server_port) {
        _socket.connect(SockaddrIn(server_ip, server_port));
    }

    void Client::disconnect(void)
    {
        if (!_socket.isClosed()) {
            _socket.close();
        }
    }

    void Client::send(const std::string &msg) const
    {
        try {
            _socket.send(msg);
        } catch (GUI::NetworkServerException &e) {
            std::cerr << e.what() << std::endl;
        }
    }

    std::string Client::tryReceive(void) const
    {
        return _socket.tryReceive();
    }
}
