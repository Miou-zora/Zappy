/*
** EPITECH PROJECT, 2023
** GUI
** File description:
** Program
*/

#pragma once

#include <string>

namespace GUI::Graphic {
    /**
     * @brief Program class that handle a program. A program is a vertex shader and a fragment shader.
     */
    class Program {
        public:
            /**
             * @brief Construct a new Program object
             *
             * @param vertexShaderPath path to the vertex shader
             * @param fragmentShaderPath path to the fragment shader
             */
            Program(const std::string &vertexShaderPath = "", const std::string &fragmentShaderPath = "");

            /**
             * @brief Copy constructor of program
             *
             * @param program program to copy
             */
            Program(const Program &program);

            /**
             * @brief Destroy the Program object
             */
            ~Program(void);

            /**
             * @brief Copy operator of Program
             *
             * @param program program to copy
             * @return Program& program
             */
            Program &operator=(const Program &program);

            /**
             * @brief Load the program
             *
             * @param vertexShaderPath path to the vertex shader
             * @param fragmentShaderPath path to the fragment shader
             */
            void load(const std::string &vertexShaderPath, const std::string &fragmentShaderPath);

            /**
             * @brief Load the program
             */
            void load(void);

            /**
             * @brief Unload the program
             */
            void unload(void);

            /**
             * @brief set the ID of the program
             *
             * @param id new id
             */
            void setID(unsigned int id) { _id = id; };

            /**
             * @brief Get the ID of the program
             *
             * @return unsigned int id of the program
             */
            unsigned int getID() const { return _id; };

            /**
             * @brief Get the vertex shader path
             *
             * @return std::string path to the vertex shader
             */
            bool isLoaded() const { return _loaded; };

        private:

            void _compileShader(const std::string &shaderPath, unsigned int shaderID, int &result);
            void _linkProgram(int &result, unsigned int VertexShaderID, unsigned int FragmentShaderID);

            std::string _vertexShaderPath;
            std::string _fragmentShaderPath;
            unsigned int _id;
            bool _loaded;
    };
}
