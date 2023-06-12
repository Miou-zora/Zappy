/*
** EPITECH PROJECT, 2023
** GUI
** File description:
** Model
*/

#pragma once

#include "Object.hpp"
#include "Mesh.hpp"
#include "Camera.hpp"
#include <vector>
#include <string>
#include <memory>

namespace GUI::Graphic::Object {
    /**
     * @brief Model class that handle a model
     */
    class Model : virtual public Object {
        public:
            /**
             * @brief Construct a new Model object
             */
            Model(void);

            /**
             * @brief Construct a new Model object
             *
             * @param std::shared_ptr<Program> program to load
             */
            Model(std::shared_ptr<Program>program);

            /**
             * @brief Copy constructor of Model
             *
             * @param other model to copy
             */
            Model(const Model &model);

            /**
             * @brief Destroy the Model object
             */
            ~Model(void) = default;

            /**
             * @brief Copy operator of Model
             *
             * @param other model to copy
             * @return Model& reference of the model
             */
            Model &operator=(const Model &model);

            /**
             * @brief set the program of the model
             *
             * @param program program to set
             */
            void setProgram(std::shared_ptr<Program> program);

            /**
             * @brief get the program of the model
             *
             * @return std::shared_ptr<Program> reference of the program
             */
            std::shared_ptr<Program> getProgram(void) const;

            /**
             * @brief load the model
             */
            void load(void);

            /**
             * @brief update the model
             */
            void loadProgram(void);

            /**
             * @brief update the model
             */
            void update(void);

            /**
             * @brief draw the model
             *
             * @param camera camera to draw
             */
            void draw(std::shared_ptr<Camera> camera);

            /**
             * @brief unload the model
             */
            void unload(void);

            /**
             * @brief add a mesh to the model
             *
             * @param mesh mesh to add
             */
            void addMesh(std::shared_ptr<Mesh> mesh);

            /**
             * @brief add a mesh to the model
             *
             * @param path path of the mesh to add
             */
            void addMesh(const std::string &path);

            /**
             * @brief get the mesh of the model
             *
             * @param index index of the mesh
             * @return Mesh& reference of the mesh
             */
            std::shared_ptr<Mesh> getMesh(int index) const;

        private:
            std::vector<std::shared_ptr<Mesh>> _meshes;
            std::shared_ptr<Program> _program;
    };
}
