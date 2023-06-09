/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** main
*/

#include "Core.hpp"
#include "ErrorManagement.hpp"
#include <iostream>

int main(int ac, char **av)
{
    try {
        GUI::Core core(ac, av);
        core.load();
        core.run();
        core.unload();
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return (84);
    }
    return (0);
}
