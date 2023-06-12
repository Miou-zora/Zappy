/*
** EPITECH PROJECT, 2023
** GUI
** File description:
** Camera
*/

#include "Camera.hpp"
#include <glm/gtx/transform.hpp>

namespace GUI::Graphic::Object {
    Camera::Camera(float ratio, const glm::vec3 &pos, float fov, float near, float far)
    {
        _ratio = ratio;
        setPos(pos);
        _fov = fov;
        _near = near;
        _far = far;

        update();
    }

    Camera::Camera(const Camera &other): Object(other)
    {
        _ratio = other._ratio;
        setPos(other.getPos());
        _fov = other._fov;
        _near = other._near;
        _far = other._far;

        update();
    }

    Camera &Camera::operator=(const Camera &other)
    {
        Object::setPos(other.getPos());
        Object::setRot(other.getRot());
        Object::setScale(other.getScale());
        _ratio = other._ratio;
        setPos(other.getPos());
        _fov = other._fov;
        _near = other._near;
        _far = other._far;

        update();
        return *this;
    }

    void Camera::_updateViewMatrix(void)
    {
        _viewMatrix = glm::lookAt(getPos(), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
    }

    void Camera::_updateProjectionMatrix(void)
    {
        _projectionMatrix = glm::perspective(_fov, _ratio, _near, _far);
    }

    void Camera::setFOV(float fov)
    {
        _fov = fov;
    }

    void Camera::setNear(float near)
    {
        _near = near;
    }

    void Camera::setFar(float far)
    {
        _far = far;
    }

    float Camera::getFOV(void)
    {
        return _fov;
    }

    float Camera::getNear(void)
    {
        return _near;
    }

    float Camera::getFar(void)
    {
        return _far;
    }

    const glm::mat4 &Camera::getViewMatrix(void) const
    {
        return _viewMatrix;
    }

    const glm::mat4 &Camera::getProjectionMatrix(void) const
    {
        return _projectionMatrix;
    }

    void Camera::load(void)
    {

    }

    void Camera::update(void)
    {
        Object::update();
        _updateViewMatrix();
        _updateProjectionMatrix();
    }

    void Camera::unload(void)
    {

    }
}