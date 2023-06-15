/*
** EPITECH PROJECT, 2023
** GUI
** File description:
** IClient
*/

#pragma once
#include <string>

namespace GUI::Network {
    class IClient {
        public:
            /**
             * @brief Connect the Client to the server
             *
             * @param server_ip ip of the server
             * @param server_port port of the server
             */
            virtual void connect(const std::string &server_ip, const std::string &server_port) = 0;

            /**
             * @brief Disconnect the Client from the server
             */
            virtual void disconnect(void) = 0;
    };
}
