/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** gui_ppo
*/

#include "server.h"
#include "trantorian.h"
#include "gui_protocol.h"

trantorian_t *get_trantorian_by_id(zappy_t *zappy, int id)
{
    client_t *client = NULL;

    LIST_FOREACH(client, &zappy->clients, next) {
        if (client->trantorian != NULL && client->trantorian->id == id) {
            return (client->trantorian);
        }
    }
    return (NULL);
}

void notifie_gui_ppo(trantorian_t *trantorian, zappy_t *zappy)
{
    response_t *response = NULL;
    client_t *client = NULL;
    char buffer[1024] = {0};

    if (sprintf(buffer, "ppo %d %d %d %d\n", trantorian->id,
        trantorian->position.x,
        trantorian->position.y, trantorian->direction) < 0)
        return;

    response = create_response(buffer);
    LIST_FOREACH(client, &zappy->clients, next) {
        if (client->is_graphic == true) {
            add_client_to_response(response, client);
        }
    }
    add_response_to_list(response, zappy);
}

void send_gui_ppo(trantorian_t *trantorian, zappy_t *zappy)
{
    response_t *response = NULL;
    char buffer[1024] = {0};

    if (sprintf(buffer, "ppo %d %d %d %d\n", trantorian->id,
        trantorian->position.x,
        trantorian->position.y, trantorian->direction) < 0)
        return;
    response = create_response(buffer);
    send_response_to_all_gui_clients(response, zappy);
}

static void notifie_one_gui_ppo(trantorian_t *trantorian, zappy_t *zappy)
{
    response_t *response = NULL;
    char buffer[1024] = {0};

    if (sprintf(buffer, "ppo %d %d %d %d\n", trantorian->id,
        trantorian->position.x, trantorian->position.y,
        trantorian->direction) < 0)
        return;
    response = create_response(buffer);
    if (response == NULL)
        return;
    send_response_to_all_gui_clients(response, zappy);
}

void handle_gui_ppo(event_t *event, zappy_t *zappy)
{
    trantorian_t *trantorian = NULL;
    int id = 0;

    if (strlen(event->request) < 7)
        return;
    if (sscanf(event->request, "ppo %d\n", &id) != 1)
        return;
    trantorian = get_trantorian_by_id(zappy, id);
    if (trantorian == NULL)
        return;
    notifie_one_gui_ppo(trantorian, zappy);
}
