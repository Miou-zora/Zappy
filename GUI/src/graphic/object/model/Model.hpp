/*
** EPITECH PROJECT, 2023
** GUI
** File description:
** Model
*/

#pragma once

#include "Object.hpp"
#include "Camera.hpp"
#include <vector>
#include <string>
#include <memory>

namespace GUI::Graphic::Object {
    /**
     * @brief Model class that handle a model
     */
    class Model : virtual public Object {
        public:
            /**
             * @brief Construct a new Model object
             */
            Model(::Model model = { 0 }, Color color = BLUE);

            /**
             * @brief Copy constructor of Model
             *
             * @param other model to copy
             */
            Model(const Model &model);

            /**
             * @brief Destroy the Model object
             */
            ~Model(void) = default;

            /**
             * @brief Copy operator of Model
             *
             * @param other model to copy
             * @return Model& reference of the model
             */
            Model &operator=(const Model &model);

            /**
             * @brief update the model
             */
            void update(void);

            /**
             * @brief draw the model
             */
            void draw(std::shared_ptr<GUI::Graphic::Object::Camera> camera);

            std::shared_ptr<BoundingBox> getBoundingBox(void);

            void setModel(std::shared_ptr<::Model> model) { _model = model; };
            std::shared_ptr<::Model> getModel(void) { return _model; }

            void setColor(Color color) { _color = color; };
            Color getColor(void) { return _color; }

        private:
            std::shared_ptr<::Model> _model;
            Color _color;
    };
}
