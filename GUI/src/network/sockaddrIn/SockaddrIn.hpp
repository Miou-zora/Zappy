/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** SockaddrIn
*/

#pragma once

#include <string>
#include <arpa/inet.h>

namespace GUI::Network {
    class SockaddrIn {
        /**
         * @brief SockaddrIn class that handle the address of a socket. It can be used to bind, connect, accept, etc. a socket
         */
        public:
            /**
             * @brief Construct a new Sockaddr In object
             */
            SockaddrIn(void) = default;

            /**
             * @brief Construct a new Sockaddr In object
             *
             * @param host host of the SockAddrIn
             * @param port port of the SockAddrIn
             * @param addressFamily address family of the SockAddrIn
             */
            SockaddrIn(const std::string &host, const std::string &port, int addressFamily = AF_INET);

            /**
             * @brief Construct a new Sockaddr In object
             *
             * @param addr address of the SockAddrIn
             */
            virtual ~SockaddrIn() = default;

            /**
             * @brief Set the Addr object
             *
             * @param addr address to set
             */
            void setAddr(struct sockaddr_in addr) { _addr = addr; };

            /**
             * @brief Set the Addr Sin Family object
             *
             * @param sin_family address family to set
             */
            void setAddrSinFamily(in_addr sin_family) { _addr.sin_addr = sin_family; };

            /**
             * @brief Set the Addr Sin Addr S Addr object
             *
             * @param s_addr address to set
             */
            void setAddrSinAddrSAddr(in_addr_t s_addr) { _addr.sin_addr.s_addr = s_addr; };

            /**
             * @brief Set the Addr Sin Port object
             *
             * @param sin_port port to set
             */
            void setAddrSinPort(in_port_t sin_port) { _addr.sin_port = sin_port; };

            /**
             * @brief Get the Addr object
             *
             * @return struct sockaddr_in
             */
            const struct sockaddr_in *getAddr(void) const { return &_addr; };

            /**
             * @brief Get the Addr Sin Family object
             *
             * @return in_addr
             */
            in_addr getAddrSinFamily(void) const { return _addr.sin_addr; };

            /**
             * @brief Get the Addr Sin Addr S Addr object
             *
             * @return in_addr_t
             */
            in_addr_t getAddrSinAddrSAddr(void) const { return _addr.sin_addr.s_addr; };

            /**
             * @brief Get the Addr Sin Port object
             *
             * @return in_port_t
             */
            in_port_t getAddrSinPort(void) const { return _addr.sin_port; };


        private:
            struct sockaddr_in _addr;
    };
}
