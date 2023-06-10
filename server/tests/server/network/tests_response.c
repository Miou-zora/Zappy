/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** tests_response
*/

#include "response.h"
#include <criterion/criterion.h>

Test(create_response, fail_and_sucess)
{
    response_t *response = create_response("test");

    cr_assert_str_eq(response->content, "test");
    destroy_response(response);
}

Test(add_client_to_response, fail_and_success)
{
    response_t *response = create_response("test");
    client_t *client = calloc(1, sizeof(client_t));

    add_client_to_response(response, client);
    cr_assert_eq(response->clients.lh_first, client);
    destroy_response(response);
    cr_assert_eq(add_client_to_response(NULL, NULL), 84);
}

Test(remove_client_from_response, fail_and_succeed)
{
    response_t *response = create_response("test");
    client_t *client = calloc(1, sizeof(client_t));

    add_client_to_response(response, client);
    remove_client_from_response(response, client);
    cr_assert_null(response->clients.lh_first);
    destroy_response(response);
    cr_assert_eq(remove_client_from_response(NULL, NULL), 84);
}

Test(destroy_response, fail_and_succeed)
{
    response_t *response = create_response("test");

    cr_assert_eq(destroy_response(response), 0);
    cr_assert_eq(destroy_response(NULL), 84);
}
