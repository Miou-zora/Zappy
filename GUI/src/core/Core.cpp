/*
** EPITECH PROJECT, 2023
** GUI
** File description:
** Core
*/

#include "Core.hpp"
#include "ErrorManagement.hpp"
#include <iostream>
#include "Request.hpp"
#include "raylib.h"

namespace GUI {
    Core::Core(int ac, char **av):
        _client(std::make_shared<GUI::Network::IOPooledClient>()),
        _gui(std::make_shared<GUI::Graphic::Management>()),
        _game(std::make_shared<GUI::Game::GameCore>(_gui->getScene(), _client))
    {
        int portFlag = 0;
        int ipFlag = 0;

        if (ac != 5 && ac != 3) {
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
            throw CoreException("Error: Port isn't here");
        }
        ipFlag = _findArg(ac, av, "-h");
        if (ipFlag == -1) {
            _ip = "localhost";
        } else {
            _ip = av[ipFlag + 1];
        }
        _port = av[portFlag + 1];
        _game->setClient(_client);
        _game->getGameState()->setScene(_gui->getScene());
        SetTraceLogLevel(LOG_WARNING | LOG_ERROR | LOG_FATAL);
    }

    void Core::_updateElapsedTime(void)
    {
        static double lastTime = 0;
        double currentTime = GetTime();

        _elapsedTime = currentTime - lastTime;
        lastTime = currentTime;
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
        _client->connect(_ip, _port);
        _gui->init();
        _game->init();
        _running = true;
    }

    void Core::run(void)
    {
        while (_running) {
            _updateElapsedTime();
            _gui->pollEvent();
            _client->update();
            _game->update(_elapsedTime);
            _gui->update();
            BeginDrawing();
                _gui->getWindow()->clear();
                _game->render();
            EndDrawing();
            if (!_gui->isRunning())
                _running = false;
        }
        CloseWindow();
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
