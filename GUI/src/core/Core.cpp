/*
** EPITECH PROJECT, 2023
** GUI
** File description:
** Core
*/

#include "Core.hpp"
#include "ErrorManagement.hpp"
#include <iostream>

namespace GUI {
    Core::Core(int ac, char **av)
    {
        int portFlag = 0;
        int ipFlag = 0;

        if (ac != 5) {
            _help();
            throw CoreException("Error: invalid number of arguments");
        }
        if (_findArg(ac, av, "-help") != -1) {
            _help();
            exit(0);
        }
        portFlag = _findArg(ac, av, "-p");
        if (portFlag == -1) {
            _help();
            throw CoreException("Error: invalid port");
        }
        ipFlag = _findArg(ac, av, "-h");
        if (ipFlag == -1) {
            _help();
            throw CoreException("Error: invalid ip");
        }
        _ip = av[ipFlag + 1];
        _port = av[portFlag + 1];
    }


    int Core::_findArg(int ac, char **av, const std::string &arg)
    {
        for (int i = 0; i < ac; i++) {
            if (arg == av[i])
                return i;
        }
        return -1;
    }

    void Core::load(void)
    {
        _client.connect(_ip, _port);
    }

    void Core::run(void)
    {
        while (_running) {
            std::string msg = _client.tryReceive();
            if (!msg.empty()) {
                if (msg.back() == '\n')
                    msg.pop_back();
                time_t now = time(0);
                tm *ltm = localtime(&now);
                std::printf("[%02d:%02d-%02d/%02d/%04d] %s\n",
                    ltm->tm_hour, ltm->tm_min, ltm->tm_mday, ltm->tm_mon + 1, ltm->tm_year + 1900, msg.c_str());
            }
        }
    }

    void Core::unload(void)
    {

    }

    void Core::_help(void)
    {
        std::string helpMessage = "USAGE: ./zappy_ai -p port -h machine\n"
                                "\tport\t\tis the port number\n"
                                "\tmachine\t\tis the name of the machine; localhost by default";
        std::cout << helpMessage << std::endl;
    }
}
