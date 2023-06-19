/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** gui_protocol
*/

#pragma once
#include "server.h"

/**
 * @brief handle the GUI client event
 *
 * @param event  the event generated by the GUI client
 * @param zappy  the struct containing all the informations about the server
 * @return true  if the event was handled
 * @return false if the event was not handled
 */
bool handle_gui_event(event_t *event, zappy_t *zappy);

/**
 * @brief notifie all GUI clients of a new player connection
 *
 * @param new_client the new client
 * @param zappy the struct containing all the informations about the server
 * @return ** void
 */
void gui_pnw(client_t *new_client, zappy_t *zappy);

/**
 * @brief respond to the GUI client with the map size
 * should be called when the GUI client sends "msz\n"
 * or when a new GUI client connects
 *
 * @param event generated by the GUI client
 * @param zappy the struct containing all the informations about the server
 * @return ** void
 */
void gui_msz(event_t *event, zappy_t *zappy);
