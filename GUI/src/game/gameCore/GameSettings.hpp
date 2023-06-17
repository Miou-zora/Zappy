/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** GameSettings
*/

#pragma once
#include <cstddef>
#include <utility>

namespace GUI::Game {
    class GameSettings {
        public:
            GameSettings()
            {
                _timeUnit = 0;
                _mapSize = std::pair<std::size_t, std::size_t>(0, 0);
            }

            ~GameSettings() {}


            /**
             * @brief Set the Time Unit object
             *
             * @param timeUnit
             */
            void setTimeUnit(std::size_t timeUnit) { _timeUnit = timeUnit; };

            /**
             * @brief Get the Time Unit object
             *
             * @return std::size_t
             */
            std::size_t getTimeUnit(void) { return _timeUnit; };

            /**
             * @brief Set the Map Size object
             *
             * @param x
             * @param y
             */
            void setMapSize(std::size_t x, std::size_t y) { _mapSize.first = x; _mapSize.second = y; };

            /**
             * @brief Get the Map Size object
             *
             * @return std::pair<std::size_t, std::size_t>
             */ 
            std::pair<std::size_t, std::size_t> getMapSize(void) { return _mapSize; };

        private:
            std::size_t _timeUnit;
            std::pair<std::size_t, std::size_t> _mapSize;
    };
}
