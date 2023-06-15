/*
** EPITECH PROJECT, 2023
** GUI
** File description:
** Response
*/

#include "Response.hpp"

namespace GUI::Network {
    Response::Response(const std::string &response): _response(response)
    {

    }

    const std::string &Response::get(void)const
    {
        return (_response);
    }

    Response::Response(const Response &response)
    {
        _response = response.get();
    }

    Response &Response::operator=(const Response &response)
    {
        _response = response.get();
        return *this;
    }

    void Response::set(const std::string &response)
    {
        _response = response;
    }
}
