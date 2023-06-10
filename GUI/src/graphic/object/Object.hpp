/*
** EPITECH PROJECT, 2023
** GUI
** File description:
** AObject
*/

#pragma once
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>

namespace GUI::Graphic::Object {
    /**
     * @brief Object class that handle an object in the scene. This is not always a drawable object. This represent only
     * an entity in the scene.
     */
    class Object {
        public:
            /**
             * @brief Construct a new Object object
             *
             * @param pos position of the object
             * @param rot rotation of the object
             * @param scale scale of the object
             */
            Object(const glm::vec3 &pos = glm::vec3(0, 0, 0), const glm::vec4 &rot = glm::vec4(0, 0, 0, 0), const glm::vec3 &scale = glm::vec3(1, 1, 1));

            /**
             * @brief Copy constructor of Object
             *
             * @param other object to copy
             */
            Object(const Object &obj);

            /**
             * @brief Destroy the Object object
             */
            ~Object(void) = default;

            /**
             * @brief Copy operator of Object
             *
             * @param other object to copy
             * @return Object& reference of the object
             */
            void setPos(float x, float y, float z);

            /**
             * @brief Set the Pos object
             *
             * @param pos new position
             */
            void setPos(const glm::vec3 &pos);

            /**
             * @brief Set the Rot object
             *
             * @param x rotation on x axis
             * @param y rotation on y axis
             * @param z rotation on z axis
             */
            void setRot(float x, float y, float z);

            /**
             * @brief Set the Rot object
             *
             * @param rot new rotation
             */
            void setRot(const glm::vec3 &rot);

            /**
             * @brief Set the Scale object
             *
             * @param x scale on x axis
             * @param y scale on y axis
             * @param z scale on z axis
             */
            void setRot(float x, float y, float z, float w);

            /**
             * @brief Set the Scale object
             *
             * @param scale new scale
             */
            void setRot(const glm::vec4 &rot);

            /**
             * @brief Set the Scale object
             *
             * @param x scale on x axis
             * @param y scale on y axis
             * @param z scale on z axis
             */
            void setScale(float x, float y, float z);

            /**
             * @brief Set the Scale object
             *
             * @param scale new scale
             */
            void setScale(const glm::vec3 &scale);

            /**
             * @brief Get the Pos object
             *
             * @return const glm::vec3& position of the object
             */
            const glm::vec3 &getPos(void) const;

            /**
             * @brief Get the Rot object
             *
             * @return const glm::vec3& rotation of the object
             */
            const glm::vec3 &getRot(void) const;

            /**
             * @brief Get the Scale object
             *
             * @return const glm::vec3& scale of the object
             */
            const glm::vec3 &getScale(void) const;

            /**
             * @brief Get the Model Matrix object
             *
             * @return const glm::mat4& model matrix of the object
             */
            const glm::mat4 &getModelMatrix(void) const;

            /**
             * @brief Update the object, this will update the model matrix
             */
            void update(void);

        private:
            void _updateModelMatrix(void);

            glm::vec3 _pos;
            glm::vec3 _rot;
            glm::vec3 _scale;
            glm::mat4 _model;
    };
}
