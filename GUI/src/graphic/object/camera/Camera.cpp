/*
** EPITECH PROJECT, 2023
** GUI
** File description:
** Camera
*/

#include "Camera.hpp"
#include <glm/gtx/transform.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/string_cast.hpp>
#include <iostream>

namespace GUI::Graphic::Object {
    Camera::Camera(float ratio, const glm::vec3 &pos, float fov, float near, float far):
        Object(),
        _fov(fov),
        _near(near),
        _far(far),
        _ratio(ratio),
        _targetType(Camera::TARGET_TYPE::FORWARD),
        _target(glm::vec3(0, 0, 0))
    {
        setPos(pos);

        Object::update();
        update();
    }

    Camera::Camera(const Camera &other): Object(other)
    {
        _ratio = other._ratio;
        setPos(other.getPos());
        _fov = other._fov;
        _near = other._near;
        _far = other._far;

        Object::update();
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
        if (_targetType == Camera::TARGET_TYPE::FORWARD) {
            glm::vec3 center = glm::vec3(getPos().x, getPos().y, getPos().z) + glm::vec3(0, 0, 1);
            glm::mat4 rot = glm::mat4(1);
            rot = glm::rotate(rot, getRot().x, glm::vec3(1, 0, 0));
            rot = glm::rotate(rot, getRot().y, glm::vec3(0, 1, 0));
            rot = glm::rotate(rot, getRot().z, glm::vec3(0, 0, 1));
            _viewMatrix = rot * glm::lookAt(getPos(), center, glm::vec3(0, 1, 0));
        } else if (_targetType == Camera::TARGET_TYPE::POINT_AT) {
            _viewMatrix = glm::lookAt(getPos(), _target, glm::vec3(0, 1, 0));
        }
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

    void Camera::setTargetType(Camera::TARGET_TYPE targetType)
    {
        _targetType = targetType;
    }

    Camera::TARGET_TYPE Camera::getTargetType(void)
    {
        return _targetType;
    }

    void Camera::pointAt(const glm::vec3 &target)
    {
        _target = target;
    }
}
