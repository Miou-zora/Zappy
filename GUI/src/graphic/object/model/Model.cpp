/*
** EPITECH PROJECT, 2023
** GUI
** File description:
** Model
*/

#include "Model.hpp"
#include "ErrorManagement.hpp"


namespace GUI::Graphic::Object {
    Model::Model(::Model model)
    {
        _model = std::make_shared<::Model>(model);
    }


    Model::Model(const Model &model): Object()
    {
        this->_model = model._model;
    }

    Model &Model::operator=(const Model &model)
    {
        this->_model = model._model;
        return *this;
    }

    void Model::update(void)
    {

    }

    void Model::draw(void)
    {
        DrawModelEx(*_model, getPos(), (Vector3){0, 0, 0}, 0, getScale(), BLUE);
    }
}
