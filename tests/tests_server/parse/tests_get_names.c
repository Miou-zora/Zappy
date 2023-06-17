/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** tests_get_names
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "server.h"
#include <string.h>

Test(getnames_is_true, get_names)
{
    char *av[] = {"./zappy_server", "-p", "4242", "-x", "10", "-y", "10",
        "-n", "toto", "-c", "10", "-f", "2", NULL};
    int ac = 15;
    char **value = get_names(ac, av);
    cr_assert(strcmp("toto", value[0]) == 0);
}

Test(getnames_is_true_multi, get_names)
{
    char *av[] = {"./zappy_server", "-p", "4242", "-x", "10", "-y", "10",
        "-n", "toto", "tata", "-c", "10", "-f", "2", NULL};
    int ac = 15;
    int start_index = 0;
    char **value = NULL;
    int j = 0;
    for (int i = 0; i < ac; i++) {
        if (strcmp(av[i], "-n") == 0) {
            start_index = i + 1;
            break;
        }
    }

    value = get_names(ac, av);
    j = start_index;
    for (int i = 0; value[i] != NULL; i++) {
        cr_assert(strcmp(av[j], value[i]) == 0);
        j++;
    }
}
