/*
** EPITECH PROJECT, 2023
** GUI
** File description:
** Response
*/

#pragma once
#include <string>

namespace GUI::Network {
    class Response {
        public:
            Response(const std::string &response);
            Response(const Response &response);
            ~Response() = default;

            Response &operator=(const Response &response);
            void set(const std::string &response);
            const std::string &get(void) const;

        private:
            std::string _response;
    };
}
