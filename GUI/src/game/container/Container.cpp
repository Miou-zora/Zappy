/*
** EPITECH PROJECT, 2023
** GUI
** File description:
** Container
*/

#include "Container.hpp"
#include "Cube.hpp"

namespace GUI::Game {
    Container::Container(size_t quantity, size_t size):
        _quantity(quantity),
        _maxSize(size)
    {

    }

    void Container::draw(std::shared_ptr<GUI::Graphic::Object::Camera> camera)
    {
        if (_model == nullptr)
            return;
        _model->draw(camera);
    }

    void Container::update(void)
    {
        if (_model == nullptr)
            return;
        _model->setScale(glm::vec3(0.05 + 0.01 * _quantity, 0.05 + 0.01 * _quantity, 0.05 + 0.01 * _quantity));
        _model->update();
    }

    void Container::load(std::shared_ptr<GUI::Graphic::Program> _program)
    {
        if (_quantity == 0)
            return;
        _model = GUI::Graphic::Object::CreateCubeModel();
        _model->setProgram(_program);
        _model->update();
        _model->loadProgram();
    }

    Container &Container::operator+=(size_t quantity)
    {
        _quantity = (_quantity + quantity >= _maxSize) ? _maxSize : _quantity + quantity;
        return *this;
    }

    Container &Container::operator-=(size_t quantity)
    {
        _quantity = (_quantity > quantity) ? 0 : _quantity - quantity;
        return *this;
    }

    Container &Container::operator++(void)
    {
        *this += 1;
        return *this;
    }

    Container &Container::operator--(void)
    {
        *this -= 1;
        return *this;
    }

    Container &Container::operator=(size_t quantity)
    {
        _quantity = (quantity >= _maxSize) ? _maxSize : quantity;
        return *this;
    }

    Container &Container::operator=(const Container &container)
    {
        _quantity = container._quantity;
        _maxSize = container._maxSize;
        return *this;
    }

    Container &Container::operator+=(const Container &container)
    {
        _quantity += container._quantity;
        return *this;
    }

    Container &Container::operator-=(const Container &container)
    {
        _quantity -= container._quantity;
        return *this;
    }

    bool Container::operator==(const Container &container) const
    {
        return (_quantity == container._quantity) &&
                (_maxSize == container._maxSize);
    }

    bool Container::operator!=(const Container &container) const
    {
        return !(*this == container);
    }

    bool Container::operator<(const Container &container) const
    {
        return (this->_quantity < container._quantity);
    }

    bool Container::operator>(const Container &container) const
    {
        return (this->_quantity > container._quantity);
    }

    bool Container::operator<=(const Container &container) const
    {
        return (this->_quantity <= container._quantity);
    }

    bool Container::operator>=(const Container &container) const
    {
        return (this->_quantity >= container._quantity);
    }

    bool Container::operator==(size_t quantity) const
    {
        return (_quantity == quantity);
    }

    bool Container::operator!=(size_t quantity) const
    {
        return (_quantity != quantity);
    }

    bool Container::operator<(size_t quantity) const
    {
        return (_quantity < quantity);
    }

    bool Container::operator>(size_t quantity) const
    {
        return (_quantity > quantity);
    }

    bool Container::operator<=(size_t quantity) const
    {
        return (_quantity <= quantity);
    }

    bool Container::operator>=(size_t quantity) const
    {
        return (_quantity >= quantity);
    }
}
