/*
** EPITECH PROJECT, 2023
** GUI
** File description:
** Window
*/

#pragma once

#include <string>
#include <GL/glew.h>
#include <GL/glut.h>
#include <GLFW/glfw3.h>

namespace GUI::Graphic {
    /**
     * @brief Window class that handle a window
     */
    class Window {
        public:
            /**
             * @brief Construct a new Window object
             *
             * @param width width of the window
             * @param height height of the window
             * @param title title of the window
             */
            Window(float width, float height, const std::string &title);

            /**
             * @brief Destroy the Window object
             */
            ~Window(void);

            /**
             * @brief Create the window
             */
            void create(void);

            /**
             * @brief Poll the event of the window
             */
            void pollEvent(void);

            /**
             * @brief Clear the window
             */
            void clear(void);

            /**
             * @brief Display the window
             */
            void display(void);

            /**
             * @brief Get the status of the window
             *
             * @return bool true if the window is open, false otherwise
             */
            bool isOpen(void);

            /**
             * @brief Close the window
             */
            void close(void);

            /**
             * @brief Set the status of the window
             *
             * @param open new status of the window
             */
            void setOpen(bool open);

        private:
            bool _open;
            float _width;
            float _height;
            std::string _title;
            GLFWwindow *_window;
            unsigned int _vertexArrayID;
    };
}