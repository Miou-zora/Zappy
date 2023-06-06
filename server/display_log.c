/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** display_log
*/

#include "server.h"
#include <stdarg.h>
#include <time.h>

void display_log(const char* format, ...)
{
    va_list arglist;
    va_start(arglist, format);
    time_t rawtime;
    struct tm* timeinfo;
    char buffer[22] = {0};

    time(&rawtime);
    timeinfo = localtime(&rawtime);
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", timeinfo);
    vprintf(format, arglist);
    printf("[%s] Log: ", buffer);
    va_end(arglist);
}
