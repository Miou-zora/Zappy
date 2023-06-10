/*
** EPITECH PROJECT, 2023
** GUI
** File description:
** Core
*/

#pragma once

#include <string>
#include "Client.hpp"
#include "Management.hpp"

namespace GUI {
    class Core {
        /**
         * @brief Core class that handle the client side of the GUI and the communication with the server
         */
        public:
            /**
             * @brief Construct a new Core object
             *
             * @param ac ac of main
             * @param av av of main
             */
            Core(int ac, char **av);

            /**
             * @brief Destroy the Core object
             */
            ~Core() = default;

            /**
             * @brief Load the Core object and connect the client to the server, and load the GUI
             */
            void load(void);

            /**
             * @brief Run the Core object and handle the communication with the server
             */
            void run(void);

            /**
             * @brief Unload the Core object and disconnect the client from the server
             */
            void unload(void);

            /**
             * @brief Ask if the Core object is running
             *
             * @return true if the Core object is running, false otherwise
             */
            bool isRunning(void) const { return _running; };

            /**
             * @brief Set the Running object
             *
             * @param running true if the Core object is running, false otherwise
             */
            void setRunning(bool running) { _running = running; };

        private:
            void _help(void);
            int _findArg(int ac, char **av, const std::string &arg);

            std::string _ip;
            std::string _port;
            Network::Client _client;
            bool _running;
            GUI::Graphic::Management _gui;
    };
}
