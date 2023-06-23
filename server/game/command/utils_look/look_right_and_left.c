/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** look_right_and_left
*/

#include "server.h"
#include "game.h"

void add_comma_to_buffer(char *buffer)
{
    buffer[strlen(buffer)] = ',';
}

char *look_right(client_t *client, zappy_t *zappy)
{
    vector_t ppos = {client->trantorian->position.x,
    client->trantorian->position.y};
    char *res = calloc(1, sizeof(char));
    char *tile = NULL;

    for (size_t i = 0; i <= (size_t)client->trantorian->level; i++) {
        for (size_t j = 0; j < 1 + (2 * i); j++) {
            vector_t tmp_vector = check_edges((int)(ppos.x + (int)i),
            (int)(ppos.y + (int)j), zappy->game_struct->map);
            tile = look_at_tile(tmp_vector.x, tmp_vector.y, zappy);
            res = realloc(res, (strlen(res) + strlen(tile) + 2) * sizeof(char));
            strcat(res, tile);
            add_comma_to_buffer(res);
        }
        ppos.y--;
    }
    return (add_hook(rm_spaces_before_coma(res)));
}

char *look_left(client_t *client, zappy_t *zappy)
{
    vector_t ppos = {client->trantorian->position.x,
    client->trantorian->position.y};
    char *res = calloc(1, sizeof(char));
    char *tile = NULL;

    for (size_t i = 0; i <= (size_t)client->trantorian->level; i++) {
        for (size_t j = 0; j < 1 + (2 * i); j++) {
            vector_t tmp_vector = check_edges((int)(ppos.x - (int)i),
            (int)(ppos.y - (int)j), zappy->game_struct->map);
            tile = look_at_tile(tmp_vector.x, tmp_vector.y, zappy);
            res = realloc(res, (strlen(res) + strlen(tile) + 2) * sizeof(char));
            strcat(res, tile);
            add_comma_to_buffer(res);
        }
        ppos.y++;
    }
    return (add_hook(rm_spaces_before_coma(res)));
}
