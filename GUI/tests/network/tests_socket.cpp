/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** tests_socket
*/

#include <criterion/criterion.h>

#include "Socket.hpp"
#include "ErrorManagement.hpp"

Test(Socket, constructor) {
    GUI::Network::Socket socket(AF_INET, SOCK_STREAM, 0);

    cr_assert_neq(socket.getFd(), -1);
    cr_assert_eq(socket.getDomain(), AF_INET);
    cr_assert_eq(socket.getType(), SOCK_STREAM);
    cr_assert_eq(socket.getProtocol(), 0);
}

Test(Socket, invalidConstructor) {
    try {
        GUI::Network::Socket socket(0, 0, 0);
        cr_assert_fail();
    } catch (GUI::NetworkException &e) {
        cr_assert_str_eq(e.what(), "Error: socket creation failed");
    }
}
