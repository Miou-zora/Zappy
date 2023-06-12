/*
** EPITECH PROJECT, 2023
** GUI
** File description:
** Management
*/

#include "Management.hpp"

namespace GUI::Graphic {
    Management::Management(float width, float height, const std::string &title):
        _window(std::make_shared<Window>(width, height, title)),
        _camera(std::make_shared<GUI::Graphic::Object::Camera>(width / height, glm::vec3(0, 0, 5))),
        _models(std::make_shared<std::vector<std::shared_ptr<GUI::Graphic::Object::Model>>>())
    {

    }

    void Management::init(void)
    {
        _window->create();
    }

    void Management::pollEvent(void)
    {
        _window->pollEvent();
    }

    void Management::update(void)
    {
        _camera->update();
        for (auto &model : *_models)
            model->update();
    }

    void Management::render(void)
    {
        _window->clear();
        for (auto &model : *_models) {
            model->draw(_camera);
        }
        _window->display();
    }

    void Management::close(void)
    {
        _window->close();
    }

    bool Management::isRunning(void)
    {
        return _window->isOpen();
    }

    std::shared_ptr<GUI::Graphic::Object::Camera> Management::getCamera(void) const
    {
        return _camera;
    }

    std::shared_ptr<Window> Management::getWindow(void) const
    {
        return _window;
    }

    std::shared_ptr<std::vector<std::shared_ptr<GUI::Graphic::Object::Model>>> Management::getModels(void) const
    {
        return _models;
    }
}
