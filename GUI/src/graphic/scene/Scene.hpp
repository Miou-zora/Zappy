/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** Scene
*/

#pragma once
#include <vector>
#include <memory>
#include "Model.hpp"

namespace GUI::Graphic {
    class Scene {
        /**
         * @brief Scene class is a container of models and a camera
         */
        public:
            /**
             * @brief Construct a new Scene object
             */
            Scene(void);

            /**
             * @brief Construct a new Scene object
             *
             * @param scene
             */
            Scene(const Scene &scene);

            /**
             * @brief Destroy the Scene object
             */
            ~Scene() = default;

            /**
             * @brief Overload of the = operator
             *
             * @param scene
             * @return Scene&
             */
            Scene &operator=(const Scene &scene);

            /**
             * @brief Add a model to the scene
             *
             * @param model
             */
            void addModel(std::shared_ptr<Object::Model> model);

            /**
             * @brief Add a model to the scene
             *
             * @param name
             * @param model
             */
            void addModel(std::string name, std::shared_ptr<Object::Model> model);

            /**
             * @brief Remove a model from the scene
             *
             * @param name
             */
            void removeModel(std::string name);

            /**
             * @brief Remove all models with the same name
             *
             * @param name
             */
            void removeModels(std::string name);

            /**
             * @brief Get a model from the scene
             *
             * @param name
             * @return std::shared_ptr<Object::Model>
             */
            std::shared_ptr<Object::Model> getModel(std::string name);

            /**
             * @brief Get all models from the scene
             *
             * @return std::vector<std::pair<std::string, std::shared_ptr<Object::Model>>>
             */
            const std::vector<std::pair<std::string, std::shared_ptr<Object::Model>>> &getModels(void);

            /**
             * @brief Set the Camera object
             *
             * @param camera
             */
            void setCamera(std::shared_ptr<Object::Camera> camera);

            /**
             * @brief Get the Camera object
             *
             * @return std::shared_ptr<Object::Camera>
             */
            std::shared_ptr<Object::Camera> getCamera(void);

            /**
             * @brief Update all models
             */
            void update(void);

            /**
             * @brief Draw all models
             */
            void draw(void);

        private:
            std::vector<std::pair<std::string, std::shared_ptr<Object::Model>>> _models;
            std::shared_ptr<Object::Camera> _camera;

            const std::string _DEFAULT_NAME_MODEL = "default";
    };
}
