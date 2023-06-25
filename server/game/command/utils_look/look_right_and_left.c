/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** look_right_and_left
*/

#include "server.h"
#include "game.h"
#include "look.h"

static vector_t recalculate_vector(look_t *look, int i, int j, map_t *map)
{
    vector_t coef = {1, 1};
    if (look->direction == DOWN) {
        return (check_edges(look->ppos.x + j, look->ppos.y + i, map));
    } else if (look->direction == UP) {
        return (check_edges(look->ppos.x + j, look->ppos.y - i, map));
    }
    if (look->direction == RIGHT) {
        return (check_edges(look->ppos.x + i, look->ppos.y + j, map));
    } else if (look->direction == LEFT) {
        return (check_edges(look->ppos.x - i, look->ppos.y - j, map));
    }
    return (coef);
}

static char *look_at_line(look_t *look, int i, zappy_t *zappy)
{
    char *tile = NULL;
    vector_t correction = {0, 0};

    for (int j = 0; j < 1 + (2 * i); j++) {
        correction = recalculate_vector(look, i, j, zappy->game_struct->map);
        tile = look_at_tile(correction.x, correction.y, zappy);
        strcat(look->res, tile);
        free(tile);
    }
    return (look->res);
}

char *send_look(client_t *client, zappy_t *zappy, vector_t cpos)
{
    look_t look = {0};
    look.cpos = cpos;
    look.ppos = client->trantorian->position;
    look.direction = client->trantorian->direction;
    look.res = calloc(size_to_alloc_look(client, zappy, cpos), sizeof(char));

    for (size_t i = 0; i <= (size_t)client->trantorian->level; i++) {
        look.res = look_at_line(&look, i, zappy);
        look.ppos.y += look.cpos.y;
        look.ppos.x += look.cpos.x;
    }
    return (add_hook(look.res));
}
