/*
** EPITECH PROJECT, 2023
** GUI
** File description:
** Incantation
*/

#pragma once
#include <vector>
#include <cstddef>

namespace GUI::Game {
    class Incantation {
        public:
            Incantation(void);
            Incantation(size_t posX, size_t posY, size_t level, std::vector<size_t> &playersId);
            ~Incantation() = default;

            size_t getPosX(void) const { return _posX; }
            size_t getPosY(void) const { return _posY; }
            size_t getLevel(void) const { return _level; }
            const std::vector<size_t> &getPlayersId(void) const { return _playersId; }
            std::vector<size_t> &getPlayersId(void) { return _playersId; }

            void setPosX(size_t posX) { _posX = posX; }
            void setPosY(size_t posY) { _posY = posY; }
            void setLevel(size_t level) { _level = level; }
            void setPlayersId(std::vector<size_t> &playersId) { _playersId = playersId; }

            bool isFinished(void) const { return _finished; }
            void finish(void) { _finished = true; }
            void finish(bool finished) { _finished = finished; }

        private:
            bool _finished;
            size_t _posX;
            size_t _posY;
            size_t _level;
            std::vector<size_t> _playersId;
    };
}
