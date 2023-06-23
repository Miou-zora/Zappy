/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** Scene
*/

#include "Scene.hpp"
#include <iostream>

namespace GUI::Graphic {
    Scene::Scene(void) : _models(), _camera(std::make_shared<Graphic::Object::Camera>())
    {

    }

    Scene::Scene(const Scene &scene)
    {
        _models = scene._models;
        _camera = scene._camera;
    }

    Scene &Scene::operator=(const Scene &scene)
    {
        _models = scene._models;
        _camera = scene._camera;
        return *this;
    }

    void Scene::addModel(std::shared_ptr<Object::Model> model)
    {
        _models.push_back(std::pair<std::string, std::shared_ptr<Object::Model>>(_DEFAULT_NAME_MODEL , model));
    }

    void Scene::addModel(std::string name, std::shared_ptr<Object::Model> model)
    {
        _models.push_back(std::pair<std::string, std::shared_ptr<Object::Model>>(name, model));
    }

    void Scene::removeModel(std::string name)
    {
        for (size_t i = 0; i < _models.size(); i++) {
            if (_models[i].first == name) {
                _models.erase(_models.begin() + i);
                return;
            }
        }
    }

    void Scene::removeModels(std::string name)
    {
        for (size_t i = 0; i < _models.size(); i++) {
            if (_models[i].first == name) {
                _models.erase(_models.begin() + i);
                i--;
            }
        }
    }

    std::shared_ptr<Object::Model> Scene::getModel(std::string name)
    {
        for (size_t i = 0; i < _models.size(); i++) {
            if (_models[i].first == name) {
                return _models[i].second;
            }
        }
        return nullptr;
    }

    const std::vector<std::pair<std::string, std::shared_ptr<Object::Model>>> &Scene::getModels(void)
    {
        return _models;
    }

    void Scene::setCamera(std::shared_ptr<Object::Camera> camera)
    {
        _camera = camera;
    }

    std::shared_ptr<Object::Camera> Scene::getCamera(void)
    {
        return _camera;
    }

    void Scene::draw()
    {
        for (auto &model : _models) {
            model.second->draw(_camera);
        }
    }

    void Scene::update(void)
    {
        if (_camera)
            _camera->update();
        for (auto &model : _models) {
            if (model.second)
                model.second->update();
        }
    }
}
