/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** check_adjacent_position
*/

#include "game.h"

static const vector_t near_player[] = {
    {0, -1},
    {-1, -1},
    {-1, 0},
    {-1, 1},
    {0, 1},
    {1, 1},
    {1, 0},
    {1, -1}
};

bool is_not_near(trantorian_t *dest, vector_t *pos)
{
    for (int i = 0; i < 8; i++) {
        if (dest->position.x + near_player[i].x == pos->x
        && dest->position.y + near_player[i].y == pos->y)
            return (false);
    }
    return (true);
}

int get_index_direction(trantorian_t *dest, vector_t *pos)
{
    for (int i = 0; i < 8; i++) {
        if (dest->position.x + near_player[i].x == pos->x
            && dest->position.y + near_player[i].y == pos->y)
            return (i);
    }
    return (0);
}

int get_direction(trantorian_t *dest, vector_t *pos)
{
    int up[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int down[] = {5, 6, 7, 8, 1, 2, 3, 4};
    int left[] = {7, 8, 1, 2, 3, 4, 5, 6};
    int right[] = {3, 4, 5, 6, 7, 8, 1, 2};
    int idx = get_index_direction(dest, pos);

    if (dest->direction == UP)
        return (up[idx]);
    if (dest->direction == DOWN)
        return (down[idx]);
    if (dest->direction == LEFT)
        return (left[idx]);
    return (right[idx]);

}

void send_broadcast_response(zappy_t *zappy, trantorian_t *dest,
    vector_t *pos, char *message)
{
    char buffer[1024] = {0};
    response_t *response = NULL;

    sprintf(buffer, "message %d, %s\n", get_direction(dest, pos), message);
    response = create_response(buffer);
    add_client_to_response(response, dest->client);
    add_response_to_list(response, zappy);
}
