/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** event
*/

#include "event.h"
#include "server.h"
#include "network.h"
#include <criterion/criterion.h>

Test(create_event, create_event)
{
    client_t *client = calloc(1, sizeof(client_t));
    event_t *event = create_event("Forward", client);

    cr_assert_not_null(event);
    cr_assert_str_eq(event->request, "Forward");
    cr_assert_eq(event->client, client);
}

Test(destroy_event, destroy_event)
{
    client_t *client = calloc(1, sizeof(client_t));
    event_t *event = create_event("Forward", client);

    destroy_event(event);
    cr_assert_not_null(client);
}

Test(connection_function, connection_function)
{
    client_t *client = calloc(1, sizeof(client_t));
    char *av[] = {"./zappy_server", "-p", "12347", "-x", "10", "-y", "10", "-n",
    "toto", "-c", "10", "-f", "10", NULL};
    zappy_t *zappy = build_server(13, av);
    event_t *event = create_event(NULL, client);

    client->is_connected = false;
    client->is_logged = false;

    client->is_connected = true;
    client->is_logged = false;

    event_connection(event, zappy);
    cr_assert_not_null(zappy->responses.lh_first);
    response_t *response = get_last_response(zappy);
    cr_assert_str_eq(response->content, "WELCOME\n");
}
