/*
** EPITECH PROJECT, 2023
** GUI
** File description:
** Model
*/

#include "Model.hpp"
#include "ErrorManagement.hpp"


namespace GUI::Graphic::Object {
    Model::Model(::Model model, Color color): _color(color)
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
            DrawModelEx(*_model, getPos(), getRot(), 0, getScale(), _color);
        EndMode3D();
    }

    std::shared_ptr<BoundingBox> Model::getBoundingBox(void)
    {
        if (_model->meshCount == 0)
            return nullptr;
        std::shared_ptr<BoundingBox> box = std::make_shared<BoundingBox>(::GetMeshBoundingBox(_model->meshes[0]));
        box->min.x *= getScale().x;
        box->min.y *= getScale().y;
        box->min.z *= getScale().z;
        box->max.x *= getScale().x;
        box->max.y *= getScale().y;
        box->max.z *= getScale().z;
        box->min.x += getPos().x;
        box->min.y += getPos().y;
        box->min.z += getPos().z;
        box->max.x += getPos().x;
        box->max.y += getPos().y;
        box->max.z += getPos().z;
        return box;
    }
}
