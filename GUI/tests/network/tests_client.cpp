/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** tests_client
*/

#include <criterion/criterion.h>

#include "Client.hpp"
#include "ErrorManagement.hpp"

Test(Client, constructor) {
    GUI::Network::Client client("localhost");

    cr_assert_str_eq(client.getIp().c_str(), "localhost");
    cr_assert_neq(client.getSocket().getFd(), -1);
}

Test(Client, constructorInvalidIp) {
    try {
        GUI::Network::Client client("invalid ip");
        cr_assert_fail();
    } catch (GUI::NetworkException &e) {
        cr_assert_str_eq(e.what(), "Error: invalid hostname");
    }
}

Test(Client, invalidConnectIp) {
    GUI::Network::Client client("localhost");
    try {
        client.connect("invalid ip", "4242");
        cr_assert_fail();
    } catch (GUI::NetworkException &e) {
        cr_assert_str_eq(e.what(), "Error: invalid hostname");
    }
}

Test(Client, invalidConnectPort) {
    GUI::Network::Client client("localhost");
    try {
        client.connect("localhost", "invalid port");
        cr_assert_fail();
    } catch (GUI::NetworkException &e) {
        cr_assert_str_eq(e.what(), "Error: invalid port");
    }
}

Test(Client, invalidConnectNoServer) {
    GUI::Network::Client client("localhost");
    try {
        client.connect("127.0.0.10", "16969");
        cr_assert_fail();
    } catch (GUI::NetworkException &e) {
        cr_assert_str_eq(e.what(), "Error: socket connect failed");
    }
}

#include <iostream>

std::string tryReceiveForServer(int clientFd)
{
    int activity = 0;
    char buffer[1024] = {0};
    struct timeval tv;
    fd_set readfds;
    tv.tv_sec = 0;
    tv.tv_usec = 0;

    FD_ZERO(&readfds);
    FD_SET(clientFd, &readfds);
    activity = select(clientFd + 1, &readfds, NULL, NULL, &tv);
    if (activity < 0) {
        throw GUI::NetworkException("Error: select failed");
    }
    if (activity == 0) {
        return "";
    }
    if (FD_ISSET(clientFd, &readfds)) {
        if (::recv(clientFd, buffer, 1024, 0) < 0) {
            throw GUI::NetworkException("Error: recv failed: " + std::string(strerror(errno)));
        }
        return buffer;
    }
    return "";
}

Test(Client, goodConnection) {
    GUI::Network::Client client;
    GUI::Network::Socket socket(AF_INET, SOCK_STREAM, 0);
    int randomPort = 0;
    bool binded = false;
    srand(time(NULL));
    while(!binded) {
        try {
            randomPort = rand() % 10000 + 10000;
            socket.bind(GUI::Network::SockaddrIn("localhost", std::to_string(randomPort)));
            binded = true;
        } catch (GUI::NetworkException &e) {
        }
    }
    socket.listen(1);
    client.connect("localhost", std::to_string(randomPort));
    GUI::Network::SockaddrIn addr;
    GUI::Network::Socket clientSocket = socket.accept(addr);
    client.send("test");
    std::string msg = "";
    while (msg == "") {
        msg = tryReceiveForServer(clientSocket.getFd());
    }
    cr_assert_str_eq(msg.c_str(), "test");
    socket.close();
    clientSocket.close();
}
