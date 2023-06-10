/*
** EPITECH PROJECT, 2023
** GUI
** File description:
** Camera
*/

#pragma once
#include "Object.hpp"

namespace GUI::Graphic::Object {
    /**
     * @brief Camera class that handle the camera object
     */
    class Camera : virtual public GUI::Graphic::Object::Object {
        public:
            /**
             * @brief Construct a new Camera object
             *
             * @param ratio ratio of the camera
             * @param pos position of the camera
             * @param fov fov of the camera
             * @param near near of the camera
             * @param far far of the camera
             */
            Camera(float ratio, const glm::vec3 &pos = glm::vec3(0, 0, 0), float fov = 80, float near = 0.01f, float far = 1000);

            /**
             * @brief Copy constructor of Camera
             *
             * @param other camera to copy
             */
            Camera(const Camera &other);

            /**
             * @brief Destroy the Camera object
             */
            ~Camera(void) = default;

            /**
             * @brief Copy operator of Camera
             *
             * @param other camera to copy
             * @return Camera& reference of the camera
             */
            Camera &operator=(const Camera &other);

            /**
             * @brief set the fov of the camera
             *
             * @param fov fov of the camera
             */
            void setFOV(float fov);

            /**
             * @brief set the near of the camera
             *
             * @param near near of the camera
             */
            void setNear(float near);

            /**
             * @brief set the far of the camera
             *
             * @param far far of the camera
             */
            void setFar(float far);

            /**
             * @brief get the fov of the camera
             *
             * @return fov of the camera
             */
            float getFOV(void);

            /**
             * @brief get the near of the camera
             *
             * @return near of the camera
             */
            float getNear(void);

            /**
             * @brief get the far of the camera
             *
             * @return far of the camera
             */
            float getFar(void);

            /**
             * @brief get the view matrix of the camera
             *
             * @return view matrix of the camera
             */
            const glm::mat4 &getViewMatrix(void) const;

            /**
             * @brief get the projection matrix of the camera
             *
             * @return projection matrix of the camera
             */
            const glm::mat4 &getProjectionMatrix(void) const;

            /**
             * @brief load the camera
             */
            void load(void);

            /**
             * @brief update the camera
             */
            void update(void);

            /**
             * @brief unload the camera
             */
            void unload(void);

        private:
            void _updateViewMatrix(void);
            void _updateProjectionMatrix(void);

            float _fov;
            float _near;
            float _far;
            float _ratio;

            glm::mat4 _viewMatrix;
            glm::mat4 _projectionMatrix;
    };
}
