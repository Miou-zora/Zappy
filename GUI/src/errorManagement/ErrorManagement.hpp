/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** ErrorManagement
*/

#pragma once

#include <exception>
#include <string>

namespace GUI {
    class NetworkException : public std::exception {
        /**
         * @brief NetworkException class that handle the network exceptions
         * @param message message to display
         */
        public:
            /**
             * @brief Construct a new Network Exception object
             *
             * @param message message to display
             */
            NetworkException(const std::string &message) : _message(message) {};
            /**
             * @brief Destroy the Network Exception object
             */
            ~NetworkException() throw() {}
            /**
             * @brief Get the message object
             *
             * @return const char* message to display
             */
            const char *what() const throw() { return _message.c_str(); };

        private:
            std::string _message;
    };

    class NetworkServerException : public std::exception {
        /**
         * @brief NetworkServerException class that handle the network server exceptions
         * @param message message to display
         */
        public:
            /**
             * @brief Construct a new Network Server Exception object
             *
             * @param message message to display
             */
            NetworkServerException(const std::string &message) : _message(message) {};
            /**
             * @brief Destroy the Network Server Exception object
             */
            ~NetworkServerException() throw() {}
            /**
             * @brief Get the message object
             *
             * @return const char* message to display
             */
            const char *what() const throw() { return _message.c_str(); };

        private:
            std::string _message;
    };

    class CoreException : public std::exception {
        /**
         * @brief CoreException class that handle the core exceptions
         * @param message message to display
         */
        public:
            /**
             * @brief Construct a new Core Exception object
             *
             * @param message message to display
             */
            CoreException(const std::string &message) : _message(message) {};
            /**
             * @brief Destroy the Core Exception object
             */
            ~CoreException() throw() {}
            /**
             * @brief Get the message object
             *
             * @return const char* message to display
             */
            const char *what() const throw() { return _message.c_str(); };

        private:
            std::string _message;
    };

    class ObjLoadException : public std::exception {
        /**
         * @brief ObjLoadException class that handle the obj loading exceptions
         * @param message message to display
         */
        public:
            /**
             * @brief Construct a new Obj Load Exception object
             *
             * @param message message to display
             */
            ObjLoadException(const std::string &message) : _message(message) {};
            /**
             * @brief Destroy the Obj Load Exception object
             */
            ~ObjLoadException() throw() {}
            /**
             * @brief Get the message object
             *
             * @return const char* message to display
             */
            const char *what() const throw() { return _message.c_str(); };

        private:
            std::string _message;
    };
}
