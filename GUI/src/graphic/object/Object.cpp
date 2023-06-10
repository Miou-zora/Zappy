/*
** EPITECH PROJECT, 2023
** GUI
** File description:
** Object
*/

#include "Object.hpp"
#include <glm/gtc/matrix_transform.hpp>

namespace GUI::Graphic::Object {
    Object::Object(const glm::vec3 &pos, const glm::vec4 &rot, const glm::vec3 &scale)
    {
        _pos = pos;
        _rot = rot;
        _scale = scale;
        _model = glm::mat4(1);
        _updateModelMatrix();
    }

    Object::Object(const Object &obj)
    {
        _pos = obj._pos;
        _rot = obj._rot;
        _scale = obj._scale;
        _model = obj._model;
    }

    void Object::_updateModelMatrix(void)
    {
        _model = glm::mat4(1);
        _model = glm::translate(_model, _pos);
        _model = glm::rotate(_model, _rot.x, glm::vec3(1, 0, 0));
        _model = glm::rotate(_model, _rot.y, glm::vec3(0, 1, 0));
        _model = glm::rotate(_model, _rot.z, glm::vec3(0, 0, 1));
        _model = glm::scale(_model, _scale);
    }

    void Object::setPos(float x, float y, float z)
    {
        _pos = glm::vec3(x, y, z);
    }

    void Object::setPos(const glm::vec3 &pos)
    {
        _pos = pos;
    }

    void Object::setRot(float x, float y, float z)
    {
        _rot = glm::vec3(x, y, z);
    }

    void Object::setRot(const glm::vec3 &rot)
    {
        _rot = rot;
    }
    void Object::setRot(float x, float y, float z, float w)
    {
        _rot = glm::vec4(x, y, z, w);
    }

    void Object::setRot(const glm::vec4 &rot)
    {
        _rot = rot;
    }

    void Object::setScale(float x, float y, float z)
    {
        _scale = glm::vec3(x, y, z);
    }

    void Object::setScale(const glm::vec3 &scale)
    {
        _scale = scale;
    }

    const glm::vec3 &Object::getPos(void) const
    {
        return _pos;
    }

    const glm::vec3 &Object::getRot(void) const
    {
        return _rot;
    }

    const glm::vec3 &Object::getScale(void) const
    {
        return _scale;
    }

    const glm::mat4 &Object::getModelMatrix(void) const
    {
        return _model;
    }

    void Object::update(void)
    {
        _updateModelMatrix();
    }
}
