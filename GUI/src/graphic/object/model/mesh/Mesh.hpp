/*
** EPITECH PROJECT, 2023
** GUI
** File description:
** Mesh
*/

#pragma once
#include <vector>
#include "Program.hpp"
#include <memory>

namespace GUI::Graphic::Object {
    /**
     * @brief Mesh class that handle a mesh
     */
    class Mesh {
        public:
            /**
             * @brief Construct a new Mesh object
             */
            Mesh(void);

            /**
             * @brief Copy constructor of Mesh
             *
             * @param other mesh to copy
             */
            Mesh(const Mesh &other);

            /**
             * @brief Destroy the Mesh object
             */
            ~Mesh(void) = default;

            /**
             * @brief Copy operator of Mesh
             *
             * @param other mesh to copy
             * @return Mesh& reference of the mesh
             */
            Mesh &operator=(const Mesh &other);

            /**
             * @brief load the mesh
             */
            void load(void);

            /**
             * @brief load the program
             *
             * @param program program to load
             */
            void loadProgram(std::shared_ptr<Program> program);

            /**
             * @brief render the mesha using the program and the mvp
             *
             * @param mvp mvp of the mesh
             */
            void render(float *mvp) const;

            /**
             * @brief add a vertex to the mesh
             *
             * @param x x of the vertex
             * @param y y of the vertex
             * @param z z of the vertex
             */
            void addVertex(float x, float y, float z);

            /**
             * @brief add a normal to the mesh
             *
             * @param x x of the normal
             * @param y y of the normal
             * @param z z of the normal
             */
            void addNormal(float x, float y, float z);

            /**
             * @brief add a uv to the mesh
             *
             * @param x x of the uv
             * @param y y of the uv
             */
            void addUV(float x, float y);

            /**
             * @brief Get the Vertices object
             *
             * @return const std::vector<float>&
             */
            const std::vector<float> &getVertices(void) const;

            /**
             * @brief Get the Normals object
             *
             * @return const std::vector<float>&
             */
            const std::vector<float> &getNormals(void) const;

            /**
             * @brief Get the UVs object
             *
             * @return const std::vector<float>&
             */
            const std::vector<float> &getUVs(void) const;

            /**
             * @brief Set the Vertices object
             *
             * @param vertices vertices to set
             */
            void setVertices(const std::vector<float> &vertices);

            /**
             * @brief Set the Normals object
             *
             * @param normals normals to set
             */
            void setNormals(const std::vector<float> &normals);

            /**
             * @brief Set the UVs object
             *
             * @param uvs uvs to set
             */
            void setUVs(const std::vector<float> &uvs);

        private:
            std::vector<float> _vertices;
            std::vector<float> _normals;
            std::vector<float> _uvs;
            unsigned int _vertexBuffer;
            unsigned int _normalBuffer;
            unsigned int _uvBuffer;
            std::shared_ptr<Program> _program;
    };
}
