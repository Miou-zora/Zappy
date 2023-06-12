/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** Cube
*/

#pragma once
#include "Model.hpp"

namespace GUI::Graphic::Object {
    /**
     * @brief Create a Cube Model object. (UV mapping not implemented)
     *
     * @return std::shared_ptr<Model> The cube model
     */
    std::shared_ptr<Model> CreateCubeModel(void);
}
