/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** game.h
*/

#pragma once
#include "server.h"

/**
 * @brief Set the func forward object
 *
 * @param event the event
 * @param zappy_s the struct containing every information about the server
 */
void set_func_forward(event_t *event, zappy_t *zappy);

/**
 * @brief forward move up
 *
 * @param client the client who is moving
 * @param zappy_s the struct containing every information about the server
 */
void forward_move_up(client_t *client, zappy_t *zappy);

/**
 * @brief forward move right
 *
 * @param client the client who is moving
 * @param zappy_s the struct containing every information about the server
 */
void forward_move_right(client_t *client, zappy_t *zappy);

/**
 * @brief forward move down
 *
 * @param client the client who is moving
 * @param zappy_s the struct containing every information about the server
 */
void forward_move_down(client_t *client, zappy_t *zappy);

/**
 * @brief forward move left
 *
 * @param client the client who is moving
 * @param zappy_s the struct containing every information about the server
 */
void forward_move_left(client_t *client, zappy_t *zappy);

/**
 * @brief Set the func look object
 *
 * @param event the event
 * @param zappy_s the struct containing every information about the server
 */
void set_func_left(event_t *event, zappy_t *zappy_s);

/**
 * @brief Set the func look object
 *
 * @param event the event
 * @param zappy_s the struct containing every information about the server
 */
void set_func_right(event_t *event, zappy_t *zappy_s);

/**
 * @brief Set the func look object
 *
 * @param event the event
 * @param zappy_s the struct containing every information about the server
 */
void move_right(client_t *client, zappy_t *zappy, char *param);

/**
 * @brief Set the func look object
 *
 * @param event the event
 * @param zappy_s the struct containing every information about the server
 */
void move_left(client_t *client, zappy_t *zappy, char *param);

/**
 * @brief Set the func look object
 *
 * @param event the event
 * @param zappy_s the struct containing every information about the server
 */
void set_func_inventory(event_t *event, zappy_t *zappy_s);

/**
 * @brief Set the func look object
 *
 * @param event the event
 * @param zappy_s the struct containing every information about the server
 */
void send_inventory(client_t *client, zappy_t *zappy, char *param);

/**
 * @brief connect nbr command function pointer
 *
 * @param client the client who is moving
 * @param zappy_s the struct containing every information about the server
 */
void connect_nbr(client_t *client, zappy_t *zappy, char *param);

/**
 * @brief Set the func connect nbr object (connect_nbr command)
 *
 * @param event the event
 * @param zappy_s the struct containing every information about the server
 */
void set_func_connect_nbr(event_t *event, zappy_t *zappy_s);
