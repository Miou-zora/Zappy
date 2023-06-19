/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** ftObjLoader
*/

#include "Cube.hpp"
#include "Management.hpp"
#include "ObjLoader.hpp"
#include <iostream>

int main(int ac, char **av)
{
    (void)ac;
    (void)av;
    GUI::Graphic::Management management;
    std::shared_ptr<GUI::Graphic::Object::Model> model;
    std::shared_ptr<GUI::Graphic::Program> program = std::make_shared<GUI::Graphic::Program>();

    management.init();
    management.getScene()->getCamera()->setPos(glm::vec3(0.0f, 70.0f, -70.0f));
    management.getScene()->getCamera()->setFOV(70.0f);
    program->load();

    std::cout << "Loading model..." << std::endl;
    model = GUI::Utils::ObjLoader::createModelFromObjFilePath("tests/ftObjLoader/test.obj");
    std::cout << "Model loaded" << std::endl;
    model->setProgram(program);
    model->getMesh(0)->loadProgram(program);
    model->setProgram(program);
    management.getScene()->addModel(model);
    while (management.isRunning()) {
        management.pollEvent();
        management.update();
        model->setRot(glm::vec3(0, model->getRot().y + 0.01, 0));
        management.getWindow()->clear();
        management.render();
    }

    management.close();
}
