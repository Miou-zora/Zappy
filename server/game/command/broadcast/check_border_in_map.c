/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** update distance for all clients
*/

#include "server.h"
#include "trantorian.h"
#include "game.h"

int safe_x(int x, int max_x)
{
    x = x % max_x;
    if (x < 0)
        x = max_x + x;
    return (x);
}

int safe_y(int y, int max_y)
{
    y = y % max_y;
    if (y < 0)
        y = max_y + y;
    return (y);

}
