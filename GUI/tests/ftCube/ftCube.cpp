/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** ftCube
*/

#include "Cube.hpp"
#include "Management.hpp"
#include <iostream>

int main(int ac, char **av)
{
    (void)ac;
    (void)av;
    GUI::Graphic::Management management;
    std::shared_ptr<GUI::Graphic::Object::Model> cubeModel;
    std::shared_ptr<GUI::Graphic::Object::Model> cubeModel2;
    std::shared_ptr<GUI::Graphic::Program> program = std::make_shared<GUI::Graphic::Program>();

    management.init();
    management.getCamera()->setPos(glm::vec3(3.0f, 2.0f, 3.0f));

    cubeModel = GUI::Graphic::Object::CreateCubeModel();
    cubeModel2 = GUI::Graphic::Object::CreateCubeModel();
    cubeModel2->setPos(glm::vec3(0.0f, 2.0f, 0.0f));
    cubeModel2->setRot(glm::vec3(-45.0f, 0.0f, -45.0f));
    cubeModel2->setScale(glm::vec3(0.5f, 0.5f, 0.5f));
    program->load("tests/ftCube/vertexShader.vertexshader", "tests/ftCube/fragmentShader.fragmentshader");
    cubeModel->setProgram(program);
    cubeModel2->setProgram(program);
    cubeModel->getMesh(0)->loadProgram(program);
    cubeModel2->getMesh(0)->loadProgram(program);
    management.getModels()->push_back(cubeModel);
    management.getModels()->push_back(cubeModel2);
    while (management.isRunning()) {
        management.pollEvent();
        management.update();
        management.render();
    }

    management.close();
}
