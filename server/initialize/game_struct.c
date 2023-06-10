/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** game_struct
*/

#include "server.h"
#include "game_struct.h"

game_struct_t *init_game_struct(argv_t *args)
{
    game_struct_t *game_struct = calloc(1, sizeof(game_struct_t));

    if (game_struct == NULL)
        return (NULL);
    game_struct->map = create_map(args->width, args->height);
    game_struct->all_clans = create_clan_chained_list();
    game_struct->all_eggs = create_egg_chained_list();
    game_struct->time_unit = args->freq;
    return (game_struct);
}
