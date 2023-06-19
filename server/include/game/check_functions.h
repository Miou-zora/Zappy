/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** check_functions
*/

#pragma once

#include "game_struct.h"

/**
 * @brief return true if trantorian is alive
 *
 * @param trantorian
 * @return true
 * @return false
 */
void update_trantorian_life(trantorian_t *trantorian);

/**
 * @brief call for all trantorian the check alive function
 *
 * @param trantorian
 */
void update_all_trantorians_life(struct clan_head *all_clans);
