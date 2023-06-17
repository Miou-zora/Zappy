/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** tests
*/

#include "server.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <signal.h>


bool runningtest = true; //this is for the run function

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(server_connection, connection)
{
    char *av[] = {"./zappy_server", "-p", "12347", "-x", "10", "-y", "10", "-n",
        "toto", "-c", "10", "-f", "10", NULL};
    zappy_t *zappy = build_server(13, av);
    int fd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in addr = {0};
    socklen_t addr_len = sizeof(addr);

    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    addr.sin_port = htons(12347);

    int pid = fork();

    if (pid == 0) {
        run(zappy);
    } else {
        sleep(0.2);
        cr_assert_eq(connect(fd, (struct sockaddr *)&addr, addr_len), 0);
        kill(pid, SIGINT);
        close(fd);
        runningtest = false;
    }
}

// Test(check_client_handling, simple_write)
// {
//     char *av[] = {"./zappy_server", "-p", "12346", "-x", "10", "-y", "10", "-n",
//         "toto", "-c", "10", "-f", "10", NULL};
//     zappy_t *zappy = build_server(13, av);
//     int fd = socket(AF_INET, SOCK_STREAM, 0);
//     struct sockaddr_in addr = {0};
//     socklen_t addr_len = sizeof(addr);

//     addr.sin_family = AF_INET;
//     addr.sin_addr.s_addr = inet_addr("127.0.0.1");
//     addr.sin_port = htons(12346);

//     int pid = fork();

//     if (pid == 0) {
//         listen_sockets(zappy);
//         handle_activity(zappy);
//         sleep(0.2);
//         //cr_assert_eq(zappy->clients.lh_first->is_connected, true);
//     } else {
//         sleep(0.1);
//         cr_assert_eq(connect(fd, (struct sockaddr *)&addr, addr_len), 0);
//         close(fd);
        
//         runningtest = false;
//         kill(pid, SIGINT);
//     }

// }