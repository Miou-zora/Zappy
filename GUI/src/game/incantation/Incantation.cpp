/*
** EPITECH PROJECT, 2023
** GUI
** File description:
** Incantation
*/

#include "Incantation.hpp"

namespace GUI::Game {
    Incantation::Incantation(void):
        _finished(true), _result(false), _posX(-1), _posY(-1), _level(-1)
    {

    }

    Incantation::Incantation(std::size_t posX, std::size_t posY, std::size_t level, std::vector<std::size_t> &playersId):
        _finished(false), _result(false), _posX(posX), _posY(posY), _level(level), _playersId(playersId)
    {

    }
}
