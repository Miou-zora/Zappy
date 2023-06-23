/*
** EPITECH PROJECT, 2023
** GUI
** File description:
** IOPooledSocket
*/

#include "IOPooledSocket.hpp"
#include "ErrorManagement.hpp"
#include "unistd.h"
#include <cstring>
#include <iostream>

namespace GUI::Network {
    IOPooledSocket::IOPooledSocket(int domain, int type, int protocol):
        _fd(-1),
        _domain(domain),
        _type(type),
        _protocol(protocol),
        _closed(true),
        _pool(std::make_shared<IOPool>())
    {
        _fd = ::socket(domain, type, protocol);
        if (_fd < 0)
            throw GUI::NetworkException("Error: socket creation failed");
        _closed = false;
    }

    IOPooledSocket::IOPooledSocket(int domain, int type, int protocol, int fd):
        _fd(fd),
        _domain(domain),
        _type(type),
        _protocol(protocol),
        _closed(false),
        _pool(std::make_shared<IOPool>())
    {

    }

    IOPooledSocket::~IOPooledSocket()
    {
        if (!_closed) {
            ::close(_fd);
        }
        _closed = true;
    }

    void IOPooledSocket::bind(const std::shared_ptr<SockaddrIn> &addr)
    {
        if (_closed) {
            throw GUI::NetworkException("Error: trying to bind a closed socket");
        }
        if (::bind(_fd, (struct sockaddr *)addr->getAddr(), sizeof(*addr->getAddr())) != 0) {
            throw GUI::NetworkException("Error: socket bind failed");
        }
    }

    void IOPooledSocket::connect(const std::shared_ptr<SockaddrIn> &addr)
    {
        if (_closed) {
            throw GUI::NetworkException("Error: trying to connect a closed socket");
        }
        if (::connect(_fd, (struct sockaddr *)addr->getAddr(), sizeof(*addr->getAddr())) != 0) {
            throw GUI::NetworkException("Error: socket connect failed");
        }
    }

    std::shared_ptr<ISocket> IOPooledSocket::accept(std::shared_ptr<SockaddrIn> &addr)
    {
        int newSocket = 0;
        socklen_t addrlen = sizeof(*addr->getAddr());

        if (_closed) {
            throw GUI::NetworkException("Error: trying to accept a connection with a closed socket");
        }
        newSocket = ::accept(_fd, (struct sockaddr *)addr->getAddr(), &addrlen);
        if (newSocket < 0) {
            throw GUI::NetworkException("Error: accept failed");
        }
        return std::make_shared<IOPooledSocket>(_domain, _type, _protocol, newSocket);
    }

    void IOPooledSocket::addRequest(std::shared_ptr<GUI::Network::IRequest> request)
    {
        _pool->addRequest(request);
    }

    void IOPooledSocket::_getMessageFromServer(void)
    {
        char buffer[1025] = {0};

        if (::recv(_fd, buffer, 1024, 0) < 0) {
            throw GUI::NetworkException("Error: recv failed: " + std::string(strerror(errno)));
        }
        if (strlen(buffer) == 0) {
            _closed = true;
            return;
        }
        _pool->addResponse(std::make_shared<GUI::Network::Response>(buffer));
    }

    void IOPooledSocket::_sendMessageToServer(void)
    {
        std::string request = _pool->popRequest()->get() + "\n";
        if (::send(_fd, request.c_str(), request.size(), 0) < 0)
            throw GUI::NetworkException("Error: send failed: " + std::string(strerror(errno)));
    }

    void IOPooledSocket::updatePool(void)
    {
        struct timeval tv;
        fd_set readfds;
        fd_set writefds;
        int max_fd = _fd + 1;
        int activity = 1;
        tv.tv_sec = 0;
        tv.tv_usec = 0;

        if (_closed) {
            return;
        }
        FD_ZERO(&readfds);
        FD_SET(_fd, &readfds);
        FD_ZERO(&writefds);
        FD_SET(_fd, &writefds);
        do {
            activity = select(max_fd, &readfds, &writefds, NULL, &tv);
            if (activity < 0)
                throw GUI::NetworkException("Error: select failed");
            if (activity > 0) {
                if (FD_ISSET(_fd, &readfds)) {
                    _getMessageFromServer();
                } else if (FD_ISSET(_fd, &writefds) && _pool->getRequests().size() > 0) {
                    _sendMessageToServer();
                } else {
                    activity = 0;
                }
            }
        } while (activity > 0 && !_closed);
    }

    std::shared_ptr<GUI::Network::Response> IOPooledSocket::getResponse(void)
    {
        return _pool->popResponse();
    }

    void IOPooledSocket::listen(int max)
    {
        if (_closed) {
            throw GUI::NetworkException("Error: trying to listen a closed socket");
        }
        if (::listen(_fd, max) < 0) {
            throw GUI::NetworkException("Error: socket listen failed");
        }
    }

    void IOPooledSocket::close(void)
    {
        if (_closed) {
            throw GUI::NetworkException("Error: socket already closed");
        }
        if (::close(_fd) < 0) {
            throw GUI::NetworkException("Error: socket close failed");
        }
        _closed = true;
    }

    bool IOPooledSocket::isClosed(void) const
    {
        return _closed;
    }

    void IOPooledSocket::setFd(int fd)
    {
        _fd = fd;
    }

    int IOPooledSocket::getFd(void) const
    {
        return _fd;
    }

    void IOPooledSocket::setDomain(int domain)
    {
        _domain = domain;
    }

    int IOPooledSocket::getDomain(void) const
    {
        return _domain;
    }

    void IOPooledSocket::setType(int type)
    {
        _type = type;
    }

    int IOPooledSocket::getType(void) const
    {
        return _type;
    }

    void IOPooledSocket::setProtocol(int protocol)
    {
        _protocol = protocol;
    }

    int IOPooledSocket::getProtocol(void) const
    {
        return _protocol;
    }
}
