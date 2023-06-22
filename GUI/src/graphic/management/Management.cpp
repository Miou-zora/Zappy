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
        _scene(std::make_shared<GUI::Graphic::Scene>())
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
        _scene->update();
    }

    void Management::render(void)
    {
        _scene->draw();
    }

    void Management::close(void)
    {
        _window->close();
    }

    bool Management::isRunning(void)
    {
        return _window->isOpen();
    }

    std::shared_ptr<Window> Management::getWindow(void) const
    {
        return _window;
    }

    std::shared_ptr<GUI::Graphic::Scene> Management::getScene(void) const
    {
        return _scene;
    }
}
