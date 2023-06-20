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
    management.getScene()->getCamera()->setPos(glm::vec3(0.0f, 4.0f, -8.0f));
    management.getScene()->getCamera()->setFOV(90.0f);
    program->load();

    std::cout << "Loading model..." << std::endl;
    model = GUI::Utils::ObjLoader::createModelFromObjFilePath("model/Senpai.obj");
    std::cout << "Model loaded" << std::endl;
    model->setRot(glm::vec3(-M_PI/2, 0, 0));
    model->setProgram(program);
    model->getMesh(0)->loadProgram(program);
    model->setProgram(program);
    management.getScene()->addModel(model);
    while (management.isRunning()) {
        management.pollEvent();
        management.update();
        model->setRot(glm::vec3(model->getRot().x, model->getRot().y, model->getRot().z + 0.01f));
        management.getWindow()->clear();
        management.render();
    }

    management.close();
}
