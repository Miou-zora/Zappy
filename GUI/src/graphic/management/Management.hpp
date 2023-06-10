/*
** EPITECH PROJECT, 2023
** GUI
** File description:
** Management
*/

#pragma once
#include "Window.hpp"
#include "Model.hpp"
#include "Camera.hpp"
namespace GUI::Graphic {
    /**
     * @brief Management class that handle the graphic management
     */
    class Management {
        public:
            /**
             * @brief Construct a new Management object
             *
             * @param width width of the window
             * @param height height of the window
             * @param title title of the window
             */
            Management(float width = 800, float height = 600, const std::string &title = "GUI");
            /**
             * @brief Destroy the Management object
             */
            ~Management(void) = default;

            /**
             * @brief init the graphic management
             */
            void init(void);

            /**
             * @brief poll the event
             */
            void pollEvent(void);

            /**
             * @brief update the graphic management
             */
            void update(void);

            /**
             * @brief render the graphic management
             */
            void render(void);

            /**
             * @brief close the graphic management
             */
            void close(void);

            /**
             * @brief check if the graphic management is running
             *
             * @return true if the graphic management is running, false otherwise
             */
            bool isRunning(void);

        private:
            Window _window;
            GUI::Graphic::Object::Camera _camera;
            std::vector<GUI::Graphic::Object::Model> _models;
    };
}
