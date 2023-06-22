/*
** EPITECH PROJECT, 2023
** Zappy-Mirror [WSL : Ubuntu]
** File description:
** utils_look
*/

#include "server.h"
#include "look.h"

size_t nb_of_trantorians_at_pos(size_t x, size_t y, zappy_t *zappy)
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
    return count_nb_of_trantorians;
}

size_t nb_of_eggs_at_pos(size_t x, size_t y, zappy_t *zappy)
{
    game_struct_t *game = zappy->game_struct;
    egg_t *egg = NULL;
    size_t count_nb_of_eggs = 0;

    LIST_FOREACH(egg, &game->all_eggs, next_egg) {
        if (egg->pos.x == x && egg->pos.y == y)
            count_nb_of_eggs++;
    }
    return count_nb_of_eggs;
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
    return res;
}

char *look_at_tile(size_t x, size_t y, zappy_t *zappy)
{
    char *tmp = strdup(all_elements_at_tile(x, y, zappy));
    char *res = calloc(1, sizeof(char) * (strlen(tmp)));
    size_t len = 0;
    size_t res_len = 0;

    strcpy(res, tmp);
    free(tmp);
    for (size_t i = 0; i < nb_of_trantorians_at_pos(x, y, zappy); i++) {
        tmp = strdup("player");
        len = strlen(res) + strlen(tmp) + 1;
        res = realloc(res, sizeof(char) * len);
        strcat(res, tmp);
        free(tmp);
    }
    res_len = strlen(res);
    if (res_len > 0 && res[res_len - 1] == ' ')
        res[res_len - 1] = '\0';
    if (res[0] == ' ')
        memmove(res, res + 1, strlen(res));
    return res;
}
