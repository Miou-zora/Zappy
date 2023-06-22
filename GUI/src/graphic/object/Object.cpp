/*
** EPITECH PROJECT, 2023
** GUI
** File description:
** Object
*/

#include "Object.hpp"

namespace GUI::Graphic::Object {
    Object::Object(Vector3 pos)
    {
        _pos = pos;
        _rot = Vector3{0, 0, 0};
        _scale = Vector3{1, 1, 1};
    }

    Object::Object(const Object &obj)
    {
        _pos = obj._pos;
        _rot = obj._rot;
        _scale = obj._scale;
    }
}
