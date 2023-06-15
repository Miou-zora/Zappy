/*
** EPITECH PROJECT, 2023
** GUI
** File description:
** IOPooledClient
*/

#include "IOPooledClient.hpp"
#include "ErrorManagement.hpp"
#include <iostream>
#include <memory>

namespace GUI::Network
{
    IOPooledClient::IOPooledClient(const std::string &host):
        _socket(std::make_shared<IOPooledSocket>(AF_INET, SOCK_STREAM, 0)),
        _host(host)
    {
        _socket->bind(std::make_shared<SockaddrIn>(host, "0"));
    }

    void IOPooledClient::connect(const std::string &server_ip, const std::string &server_port)
    {
        _socket->connect(std::make_shared<SockaddrIn>(server_ip, server_port));
    }

    void IOPooledClient::disconnect(void)
    {
        if (!_socket->isClosed()) {
            _socket->close();
        }
    }

    void IOPooledClient::addRequest(std::shared_ptr<GUI::Network::IRequest> request)
    {
        _socket->addRequest(request);
    }

    void IOPooledClient::update(void)
    {
        _socket->updatePool();
    }

    std::shared_ptr<GUI::Network::Response> IOPooledClient::getResponse(void)
    {
        return _socket->getResponse();
    }
}
