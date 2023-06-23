/*
** EPITECH PROJECT, 2023
** GUI
** File description:
** Container
*/

#pragma once
#include "Model.hpp"
#include "raylib.h"

namespace GUI::Game {
    class Container {
        public:
            Container(std::size_t quantity = 0, std::size_t maxSize = std::size_t(-1), std::shared_ptr<GUI::Graphic::Object::Model> model = std::make_shared<GUI::Graphic::Object::Model>(LoadModelFromMesh(GenMeshCube(1, 1, 1))));
            virtual ~Container(void) = default;

            void update(void);
            void draw(std::shared_ptr<GUI::Graphic::Object::Camera> camera);

            void setQuantity(std::size_t quantity) { _quantity = quantity; };
            std::size_t getQuantity(void) const { return _quantity; };

            void setMaxSize(std::size_t maxSize) { _maxSize = maxSize; };
            std::size_t getMaxSize(void) const { return _maxSize; };

            void setModel(std::shared_ptr<GUI::Graphic::Object::Model> model) { _model = model; };
            std::shared_ptr<GUI::Graphic::Object::Model> getModel(void) const { return _model; };

            Container &operator+=(std::size_t quantity);
            Container &operator-=(std::size_t quantity);
            Container &operator++(void);
            Container &operator--(void);
            Container &operator=(std::size_t quantity);
            Container &operator=(const Container &container);
            Container &operator+=(const Container &container);
            Container &operator-=(const Container &container);
            bool operator==(const Container &container) const;
            bool operator!=(const Container &container) const;
            bool operator<(const Container &container) const;
            bool operator>(const Container &container) const;
            bool operator<=(const Container &container) const;
            bool operator>=(const Container &container) const;
            bool operator==(std::size_t quantity) const;
            bool operator!=(std::size_t quantity) const;
            bool operator<(std::size_t quantity) const;
            bool operator>(std::size_t quantity) const;
            bool operator<=(std::size_t quantity) const;
            bool operator>=(std::size_t quantity) const;

        private:
            std::shared_ptr<GUI::Graphic::Object::Model> _model;
            std::size_t _quantity;
            std::size_t _maxSize;
    };
}
