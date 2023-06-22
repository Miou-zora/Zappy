/*
** EPITECH PROJECT, 2023
** GUI
** File description:
** Camera
*/

#include "Camera.hpp"
#include <iostream>

#include "raylib.h"

namespace GUI::Graphic::Object {
    Camera::Camera(float fov):
        Object(),
        _fov(fov)
    {
        _camera = std::make_shared<::Camera>();

        (*_camera).position = (Vector3){ -7.0f, 5.0f, 0.0f };
        (*_camera).target = (Vector3){ 0.0f, 0.0f, 0.0f };
        (*_camera).up = (Vector3){ 0.0f, 1.0f, 0.0f };
        (*_camera).fovy = 80.0f;
        (*_camera).projection = CAMERA_PERSPECTIVE;

        _cameraMode = CAMERA_ORBITAL;
    }

    Camera::Camera(const Camera &other): Object(other)
    {
        _fov = other._fov;

        update();
    }

    Camera &Camera::operator=(const Camera &other)
    {
        _fov = other._fov;

        update();
        return *this;
    }

    void Camera::setFOV(float fov)
    {
        _fov = fov;
    }

    float Camera::getFOV(void)
    {
        return _fov;
    }

    void Camera::update(void)
    {
        UpdateCamera(&(*_camera), _cameraMode);
    }

    std::shared_ptr<::Camera> Camera::getCamera(void) const
    {
        return _camera;
    }

    void Camera::setCamera(std::shared_ptr<::Camera> camera)
    {
        _camera = camera;
    }
}
