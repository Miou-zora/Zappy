/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** move_trantorians
*/

#include "server.h"
#include "trantorian.h"
#include "game.h"

static bool move_left_right(trantorian_t *trantorian,
    trantorian_t *trantorian2, map_t *map, vector_t vec)
{
    switch (trantorian->direction) {
    case LEFT:
        vec = check_edges((int)trantorian2->position.x - 1,
        trantorian2->position.y, map);
        trantorian2->position.x = vec.x;
        return true;
    case RIGHT:
        vec = check_edges((int)trantorian2->position.x + 1,
        trantorian2->position.y, map);
        trantorian2->position.x = vec.x;
        return true;
    default:
        return false;
    }
    return false;
}

static bool move_up_down(trantorian_t *trantorian,
    trantorian_t *trantorian2, map_t *map)
{
    vector_t vec = {0,0};

    switch (trantorian->direction) {
    case UP:
        vec = check_edges(trantorian2->position.x,
        (int)trantorian2->position.y - 1, map);
        trantorian2->position.y = vec.y;
        return true;
    case DOWN:
        vec = check_edges(trantorian2->position.x,
        (int)trantorian2->position.y + 1, map);
        trantorian2->position.y = vec.y;
        return true;
    default:
        move_left_right(trantorian, trantorian2, map, vec);
    }
    return false;
}

static response_t *send_eject_response(trantorian_t *client,
    trantorian_t *trantorian2)
{
    int direction[4][4] = {{5, 7, 1, 3},
                            {3, 5, 7, 1},
                            {1, 3, 5, 7},
                            {7, 1, 3, 5}};
    char *str = NULL;
    response_t *response = NULL;

    asprintf(&str, "eject: %d\n",
        direction[client->direction - 1][trantorian2->direction - 1]);
    response = create_response(str);
    add_client_to_response(response, trantorian2->client);
    return response;
}

bool push_player(client_t *client, zappy_t *zappy)
{
    clan_t *clan = NULL;
    clan_member_t *clan_member = NULL;
    int nb_trantorian_pushed = 0; response_t *response = NULL;

    LIST_FOREACH(clan, &zappy->game_struct->all_clans, next_clan) {
        LIST_FOREACH(clan_member, &clan->all_members, next_clan_member) {
            if (clan_member->trantorian->position.x ==
                client->trantorian->position.x
                && clan_member->trantorian->position.y
                == client->trantorian->position.y) {
                move_up_down(client->trantorian, clan_member->trantorian,
                    zappy->game_struct->map);
                nb_trantorian_pushed++;
                response = send_eject_response(client->trantorian,
                    clan_member->trantorian);
            }
        }
    }
    add_response_to_list(response, zappy);
    return (nb_trantorian_pushed > 0) ? true : false;
}
