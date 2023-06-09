/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** Socket
*/

#include "Socket.hpp"
#include "ErrorManagement.hpp"
#include <unistd.h>
#include <cstring>
#include <iostream>

namespace GUI::Network {
    Socket::Socket(int domain, int type, int protocol):
        _fd(-1),
        _domain(domain),
        _type(type),
        _protocol(protocol),
        _closed(true)
    {
        _fd = ::socket(domain, type, protocol);
        if (_fd < 0)
            throw GUI::NetworkException("Error: socket creation failed");
        _closed = false;
    }


    Socket::Socket(int domain, int type, int protocol, int fd):
        _fd(fd),
        _domain(domain),
        _type(type),
        _protocol(protocol),
        _closed(false)
    {

    }

    Socket::~Socket()
    {
        if (!_closed) {
            ::close(_fd);
        }
        _closed = true;
    }

    void Socket::bind(const SockaddrIn &addr)
    {
        if (_closed) {
            throw GUI::NetworkException("Error: trying to bind a closed socket");
        }
        if (::bind(_fd, (struct sockaddr *)addr.getAddr(), sizeof(*addr.getAddr())) != 0) {
            throw GUI::NetworkException("Error: socket bind failed");
        }
    }

    void Socket::connect(const SockaddrIn &addr)
    {
        if (_closed) {
            throw GUI::NetworkException("Error: trying to connect a closed socket");
        }
        if (::connect(_fd, (struct sockaddr *)addr.getAddr(), sizeof(*addr.getAddr())) != 0) {
            throw GUI::NetworkException("Error: socket connect failed");
        }
    }

    void Socket::listen(int max)
    {
        if (_closed) {
            throw GUI::NetworkException("Error: trying to listen a closed socket");
        }
        if (::listen(_fd, max) < 0) {
            throw GUI::NetworkException("Error: socket listen failed");
        }
    }

    void Socket::close(void)
    {
        if (_closed) {
            throw GUI::NetworkException("Error: socket already closed");
        }
        if (::close(_fd) < 0) {
            throw GUI::NetworkException("Error: socket close failed");
        }
        _closed = true;
    }

    void Socket::send(const std::string &msg) const
    {
        if (_closed) {
            throw GUI::NetworkException("Error: trying to send a message with a closed socket");
        }
        if (::send(_fd, msg.c_str(), msg.length(), 0) < 0) {
            throw GUI::NetworkServerException("Error: send failed: " + std::string(strerror(errno)));
        }
    }

    std::string Socket::tryReceive(void) const
    {
        int activity = 0;
        char buffer[1024] = {0};
        struct timeval tv;
        fd_set readfds;
        tv.tv_sec = 0;
        tv.tv_usec = 0;

        FD_ZERO(&readfds);
        FD_SET(_fd, &readfds);
        activity = select(_fd + 1, &readfds, NULL, NULL, &tv);
        if (activity < 0) {
            throw GUI::NetworkException("Error: select failed");
        }
        if (activity == 0) {
            return "";
        }
        if (FD_ISSET(_fd, &readfds)) {
            if (::recv(_fd, buffer, 1024, 0) < 0) {
                throw GUI::NetworkException("Error: recv failed: " + std::string(strerror(errno)));
            }
            return buffer;
        }
        return "";
    }


    Socket Socket::accept(SockaddrIn &addr)
    {
        int newSocket = 0;
        socklen_t addrlen = sizeof(*addr.getAddr());

        if (_closed) {
            throw GUI::NetworkException("Error: trying to accept a connection with a closed socket");
        }
        newSocket = ::accept(_fd, (struct sockaddr *)addr.getAddr(), &addrlen);
        if (newSocket < 0) {
            throw GUI::NetworkException("Error: accept failed");
        }
        return Socket(_domain, _type, _protocol, newSocket);
    }
}
