/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** gui_protocol
*/

#pragma once
#include "server.h"

/**
 * @brief notifie all GUI clients of a new player connection
 *
 * @param new_client the new client
 * @param zappy the struct containing all the informations about the server
 * @return ** void
 */
void gui_pnw(client_t *new_client, zappy_t *zappy);
