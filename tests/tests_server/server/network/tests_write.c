/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** tests_write
*/

#include "network.h"
#include <criterion/criterion.h>
#include <fcntl.h>

Test(is_socket_ready, should_return_1)
{
    int fd = open("tests_write.ignore", O_RDWR | O_CREAT, 0666);
    cr_assert_eq(is_socket_ready(fd), 1);
    close(fd);
}

Test(is_socket_ready, should_return_minus_1)
{
    cr_assert_eq(is_socket_ready(-1), -1);
}
/*
Test(write_socket, should_return_0)
{
    int fd = open("tests_write.ignore", O_RDWR | O_CREAT, 0666);
    client_t client = {0};
    client.fd = fd;
    cr_assert_eq(send_client(NULL, &client, "test"), 0);
    close(fd);
}

Test(write_socket, should_return_84)
{
    client_t client = {0};
    client.fd = -1;
    cr_assert_eq(send_client(NULL, &client, "test"), 84);
}

Test(write_socket, should_read_before)
{
    int fd = open("tests_write.ignore", O_RDWR | O_CREAT, 0666);
    write(fd, "test", 4);
    client_t client = {0};
    client.fd = fd;
    cr_assert_eq(send_client(NULL, &client, "test"), 0);
    close(fd);
}*/