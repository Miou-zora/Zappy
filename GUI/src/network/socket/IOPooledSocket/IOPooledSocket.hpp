/*
** EPITECH PROJECT, 2023
** GUI
** File description:
** IOPooledSocket
*/

#pragma once
#include "ISocket.hpp"
#include "IOPool.hpp"

namespace GUI::Network {
    class IOPooledSocket : virtual public ISocket {
        public:
            /**
             * @brief Construct a new IOPooledSocket object
             *
             * @param domain domain of the socket
             * @param type type of the socket
             * @param protocol protocol of the socket
             */
            IOPooledSocket(int domain, int type, int protocol);

            /**
             * @brief Construct a new IOPooledSocket object
             *
             * @param domain domain of the socket
             * @param type type of the socket
             * @param protocol protocol of the socket
             * @param fd fd of the socket
             */
            IOPooledSocket(int domain, int type, int protocol, int fd);

            /**
             * @brief Destroy the IOPooledSocket object
             */
            ~IOPooledSocket();

            /**
             * @brief Bind the socket to the given address
             *
             * @param addr address to bind the socket to
             */
            void bind(const std::shared_ptr<SockaddrIn> &addr);

            /**
             * @brief Connect the socket to the given address
             *
             * @param addr address to connect the socket to
             */
            void connect(const std::shared_ptr<SockaddrIn> &addr);

            /**
             * @brief Accept a connection from the given address
             *
             * @param addr address to accept the connection from
             * @return Socket the socket that accepted the connection
             */
            std::shared_ptr<ISocket> accept(std::shared_ptr<SockaddrIn> &addr);

            /**
             * @brief add request to send to the server, it will be sent on the next update
             *
             * @param request request to send
             */
            void addRequest(std::shared_ptr<GUI::Network::IRequest> request);

            /**
             * @brief update the socket, send the requests and receive the responses
             */
            void updatePool(void);

            /**
             * @brief Get the request object
             *
             * @return std::shared_ptr<GUI::Network::Request> the request
             */
            std::shared_ptr<GUI::Network::Response> getResponse(void);

            /**
             * @brief Make the socket listen for connections
             *
             * @param max max number of connections
             */
            void listen(int max);

            /**
             * @brief Close the socket
             */
            void close(void);

            /**
             * @brief Get the closed state of the socket
             *
             * @return true if the socket is closed, false otherwise
             */
            bool isClosed(void) const;

            /**
             * @brief Set the fd of the socket
             *
             * @param fd the fd
             */
            void setFd(int fd);

            /**
             * @brief Get the fd of the socket
             *
             * @return int the fd
             */
            int getFd(void) const;

            /**
             * @brief Set the domain of the socket
             *
             * @param domain the domain
             */
            void setDomain(int domain);

            /**
             * @brief Get the domain of the socket
             *
             * @return int the domain
             */
            int getDomain(void) const;

            /**
             * @brief Set the type of the socket
             *
             * @param type the type
             */
            void setType(int type);

            /**
             * @brief Get the type of the socket
             *
             * @return int the type
             */
            int getType(void) const;

            /**
             * @brief Set the protocol of the socket
             *
             * @param protocol the protocol
             */
            void setProtocol(int protocol);

            /**
             * @brief Get the protocol of the socket
             *
             * @return int the protocol
             */
            int getProtocol(void) const;

        private:

            void _getMessageFromServer(void);
            void _sendMessageToServer(void);

            int _fd;
            int _domain;
            int _type;
            int _protocol;
            bool _closed;
            std::shared_ptr<GUI::Network::IOPool> _pool;
    };
}
