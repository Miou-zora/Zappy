/*
** EPITECH PROJECT, 2023
** GUI
** File description:
** ISocket
*/

#pragma once
#include <memory>
#include "SockaddrIn.hpp"

namespace GUI::Network {
    class ISocket {
        public:
            /**
             * @brief Bind the socket to the given address
             *
             * @param addr address to bind the socket to
             */
            virtual void bind(const std::shared_ptr<SockaddrIn> &addr) = 0;

            /**
             * @brief Connect the socket to the given address
             *
             * @param addr address to connect the socket to
             */
            virtual void connect(const std::shared_ptr<SockaddrIn> &addr) = 0;

            /**
             * @brief Accept a connection from the given address
             *
             * @param addr address to accept the connection from
             * @return Socket the socket that accepted the connection
             */
            virtual std::shared_ptr<ISocket> accept(std::shared_ptr<SockaddrIn> &addr) = 0;

            /**
             * @brief Make the socket listen for connections
             *
             * @param max max number of connections
             */
            virtual void listen(int max) = 0;

            /**
             * @brief Close the socket
             */
            virtual void close(void) = 0;

            /**
             * @brief Get the closed state of the socket
             *
             * @return true if the socket is closed, false otherwise
             */
            virtual bool isClosed(void) const = 0;
    };
}
