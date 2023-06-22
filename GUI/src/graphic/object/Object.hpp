/*
** EPITECH PROJECT, 2023
** GUI
** File description:
** AObject
*/

#pragma once
#include "raylib.h"

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
            Object(Vector3 pos = Vector3{0, 0, 0});

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
            void setPos(float x, float y, float z) { _pos = Vector3{x, y, z}; };

            /**
             * @brief Set the Rot object
             *
             * @param x rotation on x axis
             * @param y rotation on y axis
             * @param z rotation on z axis
             */
            void setRot(float x, float y, float z) { _rot = Vector3{x, y, z}; }

            /**
             * @brief Set the Scale object
             *
             * @param x scale on x axis
             * @param y scale on y axis
             * @param z scale on z axis
             */
            void setScale(float x, float y, float z) { _scale = Vector3{x, y, z}; }

            /**
             * @brief Get the Pos object
             *
             * @return Vector3 position of the object
             */
            Vector3 getPos(void) const { return _pos; };

            /**
             * @brief Get the Rot object
             *
             * @return const glm::vec3& rotation of the object
             */
            Vector3 getRot(void) const { return _rot; };

            /**
             * @brief Get the Scale object
             *
             * @return Vector3 scale of the object
             */
            Vector3 getScale(void) const { return _scale; };

        private:
            Vector3 _pos;
            Vector3 _rot;
            Vector3 _scale;
    };
}
