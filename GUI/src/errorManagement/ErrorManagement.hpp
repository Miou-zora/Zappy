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

    class ShaderException : public std::exception {
        /**
         * @brief ShaderException class that handle the shader exceptions
         * @param message message to display
         */
        public:
            /**
             * @brief Construct a new Shader Exception object
             *
             * @param message message to display
             */
            ShaderException(const std::string &message) : _message(message) {};
            /**
             * @brief Destroy the Shader Exception object
             */
            ~ShaderException() throw() {}
            /**
             * @brief Get the message object
             *
             * @return const char* message to display
             */
            const char *what() const throw() { return _message.c_str(); };

        private:
            std::string _message;
    };

    class FileException : public std::exception {
        /**
         * @brief FileException class that handle the file exceptions
         * @param message message to display
         */
        public:
            /**
             * @brief Construct a new File Exception object
             *
             * @param message message to display
             */
            FileException(const std::string &message) : _message(message) {};
            /**
             * @brief Destroy the File Exception object
             */
            ~FileException() throw() {}
            /**
             * @brief Get the message object
             *
             * @return const char* message to display
             */
            const char *what() const throw() { return _message.c_str(); };

        private:
            std::string _message;
    };

    class WindowCreationException : public std::exception {
        /**
         * @brief WindowCreationException class that handle the window creation exceptions
         * @param message message to display
         */
        public:
            /**
             * @brief Construct a new Window Creation Exception object
             *
             * @param message message to display
             */
            WindowCreationException(const std::string &message) : _message(message) {};
            /**
             * @brief Destroy the Window Creation Exception object
             */
            ~WindowCreationException() throw() {}
            /**
             * @brief Get the message object
             *
             * @return const char* message to display
             */
            const char *what() const throw() { return _message.c_str(); };

        private:
            std::string _message;
    };

    class IOPoolBufferOverflowException : public std::exception {
        /**
         * @brief IOPoolBufferOverflowException class that handle the IOPool buffer overflow exceptions
         * @param message message to display
         */
        public:
            /**
             * @brief Construct a new IOPool Buffer Overflow Exception object
             *
             * @param message message to display
             */
            IOPoolBufferOverflowException(const std::string &message) : _message(message) {};
            /**
             * @brief Destroy the IOPool Buffer Overflow Exception object
             */
            ~IOPoolBufferOverflowException() throw() {}
            /**
             * @brief Get the message object
             *
             * @return const char* message to display
             */
            const char *what() const throw() { return _message.c_str(); };

        private:
            std::string _message;
    };

    class GameException : public std::exception {
        /**
         * @brief GameException class that handle the game core exceptions
         * @param message message to display
         */
        public:
            /**
             * @brief Construct a new Game Core Exception object
             *
             * @param message message to display
             */
            GameException(const std::string &message) : _message(message) {};
            /**
             * @brief Destroy the Game Core Exception object
             */
            ~GameException() throw() {}
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
