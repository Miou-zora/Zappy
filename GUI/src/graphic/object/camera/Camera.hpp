/*
** EPITECH PROJECT, 2023
** GUI
** File description:
** Camera
*/

#pragma once
#include "Object.hpp"
#include <memory>
#include "raylib.h"

namespace GUI::Graphic::Object {
    /**
     * @brief Camera class that handle the camera object
     */
    class Camera : virtual public GUI::Graphic::Object::Object {
        public:
            /**
             * @brief Enum of the target of the camera
             */
            enum TARGET_TYPE {
                FORWARD,
                POINT_AT
            };

            /**
             * @brief Construct a new Camera object
             *
             * @param ratio ratio of the camera
             * @param pos position of the camera
             * @param fov fov of the camera
             * @param near near of the camera
             * @param far far of the camera
             */
            Camera(float fov = 80);

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
             * @brief get the fov of the camera
             *
             * @return fov of the camera
             */
            float getFOV(void);

            /**
             * @brief update the camera
             */
            void update(void);

            std::shared_ptr<::Camera> getCamera(void) const;

            void setCamera(std::shared_ptr<::Camera> camera);

        private:
            float _fov;
            std::shared_ptr<::Camera> _camera;
            int _cameraMode;
    };
}
