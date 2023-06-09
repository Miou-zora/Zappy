/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** Socket
*/

#pragma once

#include <arpa/inet.h>
#include <string>
#include "SockaddrIn.hpp"

namespace GUI::Network {
    class Socket {
        /**
         * @brief Socket class that handle the socket creation and communication with the server
         */
        public:
            /**
             * @brief Construct a new Socket object
             *
             * @param domain domain of the socket
             * @param type type of the socket
             * @param protocol protocol of the socket
             */
            Socket(int domain, int type, int protocol);

            /**
             * @brief Construct a new Socket object
             *
             * @param domain domain of the socket
             * @param type type of the socket
             * @param protocol protocol of the socket
             * @param fd fd of the socket
             */
            Socket(int domain, int type, int protocol, int fd);

            /**
             * @brief Destroy the Socket object
             */
            ~Socket();

            /**
             * @brief Bind the socket to the given address
             *
             * @param addr address to bind the socket to
             */
            void bind(const SockaddrIn &addr);

            /**
             * @brief Connect the socket to the given address
             *
             * @param addr address to connect the socket to
             */
            void connect(const SockaddrIn &addr);

            /**
             * @brief Accept a connection from the given address
             *
             * @param addr address to accept the connection from
             * @return Socket the socket that accepted the connection
             */
            Socket accept(SockaddrIn &addr);

            /**
             * @brief Send a message to the server
             *
             * @param msg message to send
             */
            void send(const std::string &msg) const;

            /**
             * @brief Try to receive a message from the server
             *
             * @return std::string the message received, empty string if no message received
             */
            std::string tryReceive(void) const;

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
             * @brief Get the fd of the socket
             *
             * @return int the fd of the socket
             */
            int getFd(void) const { return _fd; };

            /**
             * @brief Get the domain of the socket
             *
             * @return int the domain of the socket
             */
            int getDomain(void) const { return _domain; };

            /**
             * @brief Get the type of the socket
             *
             * @return int the type of the socket
             */
            int getType(void) const { return _type; };

            /**
             * @brief Get the protocol of the socket
             *
             * @return int the protocol of the socket
             */
            int getProtocol(void) const { return _protocol; };

            /**
             * @brief Get the closed state of the socket
             *
             * @return true if the socket is closed, false otherwise
             */
            bool isClosed(void) const { return _closed; };

            /**
             * @brief Set the fd of the socket
             *
             * @param fd fd of the socket
             */
            void setFd(int fd) { _fd = fd; };

            /**
             * @brief Set the domain of the socket
             *
             * @param domain domain of the socket
             */
            void setDomain(int domain) { _domain = domain; };

            /**
             * @brief Set the type of the socket
             *
             * @param type type of the socket
             */
            void setType(int type) { _type = type; };

            /**
             * @brief Set the protocol of the socket
             *
             * @param protocol protocol of the socket
             */
            void setProtocol(int protocol) { _protocol = protocol; };

            /**
             * @brief Set the closed state of the socket
             *
             * @param closed true if the socket is closed, false otherwise
             */
            void setClosed(bool closed) { _closed = closed; };

        private:
            int _fd;
            int _domain;
            int _type;
            int _protocol;
            bool _closed;
    };
}
