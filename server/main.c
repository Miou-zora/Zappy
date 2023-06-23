/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** main
*/

#include "server.h"
#include <signal.h>

bool running = true;

void sigint_handler(int sig)
{
    printf("\n");
    display_log("SIGINT received, exiting...\n");
    running = false;
    sig++;
    exit(0);
}

void display_usage(void)
{
    printf("USAGE: ./zappy_server -p port -x width -y height -n name1 name2 ");
    printf("... -c clientsNb -f freq\n");
    printf("\tport\t\tis the port number\n");
    printf("\twidth\t\tis the width of the world\n");
    printf("\theight\t\tis the height of the world\n");
    printf("\tnameX\t\tis the name of the team X\n");
    printf("\tclientsNb\tis the number of authorized clients per team\n");
    printf("\tfreq\t\tis the reciprocal of time unit for execution of ");
    printf("actions\n");
}

int main(int ac, char **av)
{
    zappy_t *zappy = NULL;
    setbuf(stdout, NULL);

    if (ac == 2 && strncmp(av[1], "-help", 5) == 0) {
        display_usage();
        return (0);
    }
    display_log("Building server...\n");
    zappy = build_server(ac, av);
    if (!zappy) {
        display_log("Failed to build server\n");
        return (84);
    }
    signal(SIGINT, sigint_handler);
    run(zappy);
    destroy_zappy(zappy);
}
