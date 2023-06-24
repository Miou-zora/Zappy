/*
** EPITECH PROJECT, 2023
** Zappy-Mirror [WSL : Ubuntu]
** File description:
** utils_look
*/

#include "server.h"
#include "look.h"

size_t nb_of_trantorians_at_pos(int x, int y, zappy_t *zappy)
{
    clan_t *clan = NULL;
    game_struct_t *game = zappy->game_struct;
    clan_member_t *member = NULL;
    size_t count_nb_of_trantorians = 0;

    LIST_FOREACH(clan, &game->all_clans, next_clan) {
        LIST_FOREACH(member, &clan->all_members, next_clan_member) {
            if (member->trantorian->position.x == x &&
                member->trantorian->position.y == y)
                count_nb_of_trantorians++;
        }
    }
    return (count_nb_of_trantorians);
}

size_t nb_of_eggs_at_pos(int x, int y, zappy_t *zappy)
{
    game_struct_t *game = zappy->game_struct;
    egg_t *egg = NULL;
    size_t count_nb_of_eggs = 0;

    LIST_FOREACH(egg, &game->all_eggs, next_egg) {
        if (egg->pos.x == x && egg->pos.y == y)
            count_nb_of_eggs++;
    }
    return (count_nb_of_eggs);
}

char *rm_spaces_before_coma(char *str)
{
    char *res = strdup(str);
    char *tmp = NULL;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ' && str[i + 1] == '\0') {
            res[i] = '\0';
        }
    }
    if (res[strlen(res) - 1] == ',')
        res[strlen(res) - 1] = '\0';
    for (size_t i = 0; i < strlen(res); i++) {
        if (res[i] == ',' && res[i + 1] != ',') {
            tmp = strdup(res + i + 1);
            res[i + 1] = ' ';
            res [i + 2] = '\0';
            strcat(res, tmp);
        }
    }
    return (res);
}

char *look_at_tile(size_t x, size_t y, zappy_t *zappy)
{
    char *elements = all_elements_at_tile(x, y, zappy);
    int nb_of_trantorians = nb_of_trantorians_at_pos(x, y, zappy);
    size_t size_alloc = strlen(elements) + 4 + (nb_of_trantorians * 7 + 4);
    char *res = calloc(size_alloc, sizeof(char));

    if (res == NULL || elements == NULL)
        return (NULL);
    res = strcat(res, elements);
    for (int i = 0; i < nb_of_trantorians; i++) {
        res = strcat(res, "player");
        if (i != nb_of_trantorians - 1)
            res = strcat(res, " ");
    }
    res = strcat(res, ", ");
    free(elements);
    return (res);
}
