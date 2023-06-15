/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** Client
*/

#pragma once

#include "Socket.hpp"
#include "IClient.hpp"

namespace GUI::Network {
    class Client : virtual public IClient{
        /**
         * @brief Client class that handle the client side of the GUI and the communication with the server
         */
        public:
            /**
             * @brief Construct a new Client object
             *
             * @param host hostname of the Client
             */
            Client(const std::string &host = "localhost");

            /**
             * @brief Destroy the Client object
             */
            ~Client() = default;

            /**
             * @brief Connect the Client to the server
             *
             * @param server_ip ip of the server
             * @param server_port port of the server
             */
            void connect(const std::string &server_ip, const std::string &server_port);

            /**
             * @brief Disconnect the Client from the server
             */
            void disconnect(void);

            /**
             * @brief Send a message to the server
             *
             * @param msg message to send
             */
            void send(const std::string &msg) const;

            /**
             * @brief Try to receive a message from the server
             *
             * @return std::string message received, empty string otherwise
             */
            std::string tryReceive(void) const;

            /**
             * @brief Get the Socket object
             *
             * @return const Socket& socket of the Client
             */
            const Socket &getSocket(void) { return _socket; };

            /**
             * @brief Get the Ip object
             *
             * @return const std::string& ip of the Client
             */
            const std::string &getIp(void) { return _host; };

            /**
             * @brief Set the Ip object
             *
             * @param host ip of the Client
             */
            void setIp(const std::string &host) { _host = host; };

        private:
            Socket _socket;
            std::string _host;
    };
}
