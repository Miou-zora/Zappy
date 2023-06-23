/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** build
*/

#include "server.h"
#include <criterion/criterion.h>

// Test(build_server, build_server)
// {
//     char *av[] = {"./zappy_server", "-p", "12345", "-x", "10", "-y", "10",
//     "-n", "toto", "tata", "-c", "10", "-f", "2", NULL};
//     int ac = 15;
//     zappy_t *zappy = build_server(ac, av);

//     cr_assert_not_null(zappy);
//     cr_assert_not_(zappy->socket == -1);
// }

// Test(build_server, build_server_invalid_port)
// {
//     char *av[] = {"./zappy_server", "-p", "-12345", "-x", "10", "-y", "10",
//     "-n", "toto", "tata", "-c", "10", "-f", "2", NULL};
//     int ac = 15;
//     zappy_t *zappy = build_server(ac, av);

//     cr_assert_null(zappy);
// }
