/*
** EPITECH PROJECT, 2023
** GUI
** File description:
** Incantation
*/

#include "Incantation.hpp"

namespace GUI::Game {
    Incantation::Incantation(void):
        _finished(true), _posX(-1), _posY(-1), _level(-1)
    {

    }

    Incantation::Incantation(size_t posX, size_t posY, size_t level, std::vector<size_t> &playersId):
        _finished(false), _posX(posX), _posY(posY), _level(level), _playersId(playersId)
    {

    }
}
