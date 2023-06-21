/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** tests_read
*/

#include "network.h"
#include <criterion/criterion.h>
#include <fcntl.h>

bool running = true; //this is for the run function

Test(is_buffer_valid, should_return_0)
{
    char buffer[BUFFER_SIZE] = {0};

    cr_assert_eq(is_buffer_valid(buffer), -1);
}

Test(is_buffer_valid, should_return_4)
{
    char buffer[BUFFER_SIZE] = "test\n";

    cr_assert_eq(is_buffer_valid(buffer), 4);
}

Test(is_buffer_valid, should_return_0_2)
{
    char buffer[BUFFER_SIZE] = "\n";

    cr_assert_eq(is_buffer_valid(buffer), 0);
}

Test(read_client, should_return_null)
{
    client_t *client = calloc(1, sizeof(client_t));
    client->fd = open("/dev/null", O_RDONLY);
    cr_assert_eq(read_client(client), NULL);
    close(client->fd);
}

// Test(read_client, should_return_hello)
// {
//     int fd = open("tests/tests_server//server/network/hello.txt", O_RDONLY);
//     cr_assert_str_eq(read_client(fd), "hello\n");
//     close(fd);
// }
