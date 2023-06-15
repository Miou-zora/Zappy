/*
** EPITECH PROJECT, 2023
** GUI
** File description:
** IOPooledClient
*/

#pragma once
#include "IClient.hpp"
#include "IOPooledSocket.hpp"

namespace GUI::Network {
    class IOPooledClient : virtual public IClient {
        /**
         * @brief Client class that handle the client side of the GUI and the communication with the server
         */
        public:
            /**
             * @brief Construct a new Client object
             *
             * @param host hostname of the Client
             */
            IOPooledClient(const std::string &host = "localhost");

            /**
             * @brief Destroy the Client object
             */
            ~IOPooledClient() = default;

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
             * @brief add request to send to the server, it will be sent on the next update
             *
             * @param request request to send
             */
            void addRequest(std::shared_ptr<GUI::Network::IRequest> request);

            /**
             * @brief update the Client, send the requests and receive the responses
             */
            void update(void);

            /**
             * @brief get the response received from the server, if there is no response it will return nullptr
             *
             * @return std::shared_ptr<GUI::Network::Response> response received from the server
             */
            std::shared_ptr<GUI::Network::Response> getResponse(void);

            /**
             * @brief Get the Socket object
             *
             * @return const Socket& socket of the Client
             */
            const std::shared_ptr<IOPooledSocket> &getSocket(void) { return _socket; };

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
            std::shared_ptr<IOPooledSocket> _socket;
            std::string _host;
    };
}
