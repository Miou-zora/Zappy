/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** event
*/

#include "event.h"
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
