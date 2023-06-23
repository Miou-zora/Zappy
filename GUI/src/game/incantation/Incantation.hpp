/*
** EPITECH PROJECT, 2023
** GUI
** File description:
** Incantation
*/

#pragma once
#include <vector>

namespace GUI::Game {
    class Incantation {
        public:
            Incantation(void);
            Incantation(std::size_t posX, std::size_t posY, std::size_t level, std::vector<std::size_t> &playersId);
            ~Incantation() = default;

            std::size_t getPosX(void) const { return _posX; }
            std::size_t getPosY(void) const { return _posY; }
            std::size_t getLevel(void) const { return _level; }
            const std::vector<std::size_t> &getPlayersId(void) const { return _playersId; }
            std::vector<std::size_t> &getPlayersId(void) { return _playersId; }

            void setPosX(std::size_t posX) { _posX = posX; }
            void setPosY(std::size_t posY) { _posY = posY; }
            void setLevel(std::size_t level) { _level = level; }
            void setPlayersId(std::vector<std::size_t> &playersId) { _playersId = playersId; }

            bool isFinished(void) const { return _finished; }
            void finish(bool result) { _finished = true; _result = result; }
            void setFinish(bool finished) { _finished = finished; }

            bool getResult(void) const { return _result; }
            void setResult(bool result) { _result = result; }

        private:
            bool _finished;
            bool _result;
            std::size_t _posX;
            std::size_t _posY;
            std::size_t _level;
            std::vector<std::size_t> _playersId;
    };
}
