/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** ftScene
*/

#include "Cube.hpp"
#include "Management.hpp"
#include "Scene.hpp"
#include <iostream>

int main(int ac, char **av)
{
    (void)ac;
    (void)av;
    GUI::Graphic::Management management;
    std::shared_ptr<GUI::Graphic::Program> program = std::make_shared<GUI::Graphic::Program>();

    management.init();
    program->load();

    for (size_t y = 0; y < 10; y++) {
        for (size_t x = 0; x < 10; x++) {
            std::shared_ptr<GUI::Graphic::Object::Model> cube = GUI::Graphic::Object::CreateCubeModel();
            cube->setPos(glm::vec3(x, 0, y));
            cube->setScale(glm::vec3(0.5, 0.5, 0.5));
            cube->setProgram(program);
            cube->load();
            cube->loadProgram();
            management.getScene()->addModel(std::to_string(x) + " " + std::to_string(y), cube);
        }
    }
    management.getScene()->getCamera()->setPos(glm::vec3(-2, -3, -3));
    management.getScene()->getCamera()->setRot(glm::vec3(0, - M_PI / 4, 0));

    // if you want test the point_at target type, uncomment this line, it will set the target of the camera to the center of the scene
    // management.getScene()->getCamera()->setTargetType(GUI::Graphic::Object::Camera::TARGET_TYPE::POINT_AT);

    while (management.isRunning()) {
        management.pollEvent();
        management.update();
        management.getWindow()->clear();
        management.render();
    }

    management.close();
}
