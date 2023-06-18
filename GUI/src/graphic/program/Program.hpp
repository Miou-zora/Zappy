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
             * @param vertexShaderCode path to the vertex shader
             * @param fragmentShaderCode path to the fragment shader
             */
            Program(const std::string &vertexShaderCode = DEFAULT_VERTEX_SHADER, const std::string &fragmentShaderCode = DEFAULT_FRAGMENT_SHADER);

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
             * @param vertexShaderCode path to the vertex shader
             * @param fragmentShaderCode path to the fragment shader
             */
            void load(const std::string &vertexShaderCode, const std::string &fragmentShaderCode);

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

            void _compileShader(const std::string &shaderCode, unsigned int shaderID, int &result);
            void _linkProgram(int &result, unsigned int VertexShaderID, unsigned int FragmentShaderID);

            std::string _vertexShaderCode;
            std::string _fragmentShaderCode;
            unsigned int _id;
            bool _loaded;

            static constexpr char DEFAULT_FRAGMENT_SHADER[] = "#version 330 core\n"
                "in vec3 vNormal;\n"
                "in vec3 vLightPos;\n"
                "out vec3 color;\n"
                "\n"
                "void main() {\n"
                // "    float ambientStrength = 0.1;\n"
                // "    vec3 ambient = ambientStrength * vec3(1, 1, 1);\n"
                // "    vec3 norm = normalize(vNormal);\n"
                // "    vec3 lightDir = normalize(vLightPos);\n"
                // "    float diff = max(dot(norm, lightDir), 0.0);\n"
                // "    vec3 diffuse = diff * vec3(1, 1, 1);\n"
                // "    vec3 result = (ambient + diffuse) * vec3(1, 1, 1);\n"
                "    color = vNormal;\n"
                "}\n";

            static constexpr char DEFAULT_VERTEX_SHADER[] = "#version 330 core\n"
                "layout(location = 0) in vec3 vertexPosition_modelspace;\n"
                "layout(location = 1) in vec3 normal;\n"
                "uniform mat4 MVP;\n"
                "uniform vec3 lightPos;\n"
                "out vec3 vNormal;\n"
                "out vec3 vLightPos;\n"
                "\n"
                "void main(){\n"
                "    gl_Position = MVP * vec4(vertexPosition_modelspace,1);\n"
                "    vNormal = normal;\n"
                "    vLightPos = lightPos;\n"
                "}\n";
    };
}
