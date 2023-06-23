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

    void Model::draw(std::shared_ptr<GUI::Graphic::Object::Camera> camera)
    {
        BeginMode3D(*camera->getCamera());
            DrawModelEx(*_model, getPos(), getRot(), 0, getScale(), BLUE);
            DrawModelWiresEx(*_model, getPos(), getRot(), 0, getScale(), BLACK);
        EndMode3D();
    }
}
