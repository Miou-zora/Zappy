/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** Bct
*/

#pragma once
#include "IUpdate.hpp"
#include "IOPooledClient.hpp"
#include "Request.hpp"
#include "Cube.hpp"
#include "StringUtils.hpp"

namespace GUI::Game {
    /**
     * @brief Bct class is used to update the map
     * 
     */
    class Bct : public IUpdate{
        public:
            Bct(std::shared_ptr<GUI::Game::GameSettings> settings,
                std::shared_ptr<GUI::Network::IOPooledClient> client,
                std::shared_ptr<GUI::Graphic::Scene> scene,
                std::string command)
            {
                _settings = settings;
                _client = client;
                _command = command;
                _scene = scene;
            }
            ~Bct() = default;

            /**
             * @brief update the map
             * 
             * @return ** void 
             */
            void update()
            {
                std::shared_ptr<GUI::Graphic::Object::Model> cubeModel;
                std::shared_ptr<GUI::Graphic::Program> program = std::make_shared<GUI::Graphic::Program>();
                std::vector<std::string> args = GUI::Utils::StringUtils::split(_command, " ");

                if (args.size() != 10)
                    return;
                std::size_t x = std::stoi(args[1]);
                std::size_t y = std::stoi(args[2]);

                cubeModel = GUI::Graphic::Object::CreateCubeModel();
                cubeModel->setPos(glm::vec3(x, 0, y));
                cubeModel->setScale(glm::vec3(0.5, 0.5, 0.5));
                program->load("assets/shaders/vertexShader.vertexshader", "assets/shaders/fragmentShader.fragmentshader");
                cubeModel->setProgram(program);
                cubeModel->loadProgram();
                _scene->addModel("tile_" + std::to_string(x) + "_" + std::to_string(y), cubeModel);
            }

        private:
    };
}
