/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** gui_pgt
*/

#include "server.h"
#include "game.h"

int get_id_ressource_by_name(char *param)
{
    char *all_ressources[] = {"food", "linemate", "deraumere", "sibur",
        "mendiane", "phiras", "thystame", NULL};

    for (int i = 0; all_ressources[i]; i++) {
        if (strcmp(all_ressources[i], param) == 0)
            return i;
    }
    return -1;
}

void send_gui_pgt(client_t *client, zappy_t *zappy, char *param)
{
    char buffer[1024];
    response_t *response = NULL;
    client_t *gui_client = NULL;
    int ressource_nb = get_id_ressource_by_name(param);

    if (sprintf(buffer, "pgt %d %d\n", client->trantorian->id,
        ressource_nb) < 0)
        return;
    response = create_response(buffer);
    if (!response)
        return;
    LIST_FOREACH(gui_client, &zappy->clients, next) {
        if (gui_client->is_graphic)
            add_client_to_response(response, gui_client);
    }
    add_response_to_list(response, zappy);
}
