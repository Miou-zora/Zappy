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
        public:
            NetworkException(const std::string &message) : _message(message) {};
            ~NetworkException() throw() {}
            const char *what() const throw() { return _message.c_str(); };

        private:
            std::string _message;
    };

    class NetworkServerException : public std::exception {
        public:
            NetworkServerException(const std::string &message) : _message(message) {};
            ~NetworkServerException() throw() {}
            const char *what() const throw() { return _message.c_str(); };

        private:
            std::string _message;
    };

    class CoreException : public std::exception {
        public:
            CoreException(const std::string &message) : _message(message) {};
            ~CoreException() throw() {}
            const char *what() const throw() { return _message.c_str(); };

        private:
            std::string _message;
    };
}
