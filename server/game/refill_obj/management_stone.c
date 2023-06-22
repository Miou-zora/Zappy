/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** refill_stones
*/

#include "refill.h"
#include "trantorian.h"
#include "game_struct.h"
#include "server.h"

static int **calculate_total_stones_in_inventory(int **tmp,
    trantorian_t *trantorian)
{
    while (LIST_NEXT(trantorian, next_trantorian) != NULL) {
        tmp[0][1] += (trantorian->inventory->nb_of_objects[LINEMATE] > 0)
            ? trantorian->inventory->nb_of_objects[LINEMATE] : 0;
        tmp[1][1] += (trantorian->inventory->nb_of_objects[DERAUMERE] > 0)
            ? trantorian->inventory->nb_of_objects[DERAUMERE] : 0;
        tmp[2][1] += (trantorian->inventory->nb_of_objects[SIBUR] > 0)
            ? trantorian->inventory->nb_of_objects[SIBUR] : 0;
        tmp[3][1] += (trantorian->inventory->nb_of_objects[MENDIANE] > 0)
            ? trantorian->inventory->nb_of_objects[MENDIANE] : 0;
        tmp[4][1] += (trantorian->inventory->nb_of_objects[PHIRAS] > 0)
            ? trantorian->inventory->nb_of_objects[PHIRAS] : 0;
        tmp[5][1] += (trantorian->inventory->nb_of_objects[THYSTAME] > 0)
            ? trantorian->inventory->nb_of_objects[THYSTAME] : 0;
    }
    return (tmp);
}

static int **calculate_total_stones_in_map(int **tmp,
    game_struct_t *game_struct)
{
    tmp[0][1] += game_struct->map->tile[0]->nb_of_objects[LINEMATE];
    tmp[1][1] += game_struct->map->tile[0]->nb_of_objects[DERAUMERE];
    tmp[2][1] += game_struct->map->tile[0]->nb_of_objects[SIBUR];
    tmp[3][1] += game_struct->map->tile[0]->nb_of_objects[MENDIANE];
    tmp[4][1] += game_struct->map->tile[0]->nb_of_objects[PHIRAS];
    tmp[5][1] += game_struct->map->tile[0]->nb_of_objects[THYSTAME];
    return (tmp);
}

static int **calculate_diff_stones(int **list_need_stones, int **list_stones)
{
    for (int i = 0; i < 6; i++) {
        list_need_stones[i][1] -= list_stones[i][1];
    }
    return (list_need_stones);
}

static void refill_stone_in_map(int **list_need_stones,
    game_struct_t *game_struct, int i, int pos[2])
{
    int stone = 0;

    for (int j = list_need_stones[i][1]; j != 0; j--) {
        stone = get_stone_from_list(list_need_stones, i);
        add_object_at_tile(game_struct->map, stone,
            rand() % pos[0], rand() % pos[1]);
    }
}

void check_and_add_stones_to_tiles(int pos[2], game_struct_t *game_struct,
trantorian_t *trantorian)
{
    int **list_stones = generate_stone_list(pos[0], pos[1]);
    int **list_need_stones = malloc_tab_array();

    list_need_stones =
        calculate_total_stones_in_inventory(list_need_stones,
        trantorian);
    list_need_stones =
        calculate_total_stones_in_map(list_need_stones, game_struct);
    list_need_stones = calculate_diff_stones(list_need_stones, list_stones);

    for (int i = 0; i < 6; i++) {
        if (list_need_stones[i][1] != 0) {
            refill_stone_in_map(list_need_stones, game_struct, i, pos);
        }
    }
}
