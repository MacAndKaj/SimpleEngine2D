//
// Created by mkajdak on 29.08.18.
//

#include <Helpers/ElementProperties.hpp>

namespace eng
{

unsigned int ElementProperties::_amountOfRegisteredElements = 0;

ElementProperties::ElementProperties(unsigned int positionCentralY, unsigned int positionCentralX)
        : _log("ElementProperties")
        , _positionCentralY(positionCentralY)
        , _positionCentralX(positionCentralX)
        , _size(0,0)
{
    ++ElementProperties::_amountOfRegisteredElements;
    _elementID = ElementProperties::_amountOfRegisteredElements;
    _log << "Creating a new Element with ID: " << std::to_string(_elementID).c_str()
        << logging::logEnd;

}

unsigned int ElementProperties::getPositionCentralY() const
{
    return _positionCentralY;
}

void ElementProperties::setPositionCentralY(unsigned int positionCentralY)
{
    _positionCentralY = positionCentralY;
}

unsigned int ElementProperties::getPositionCentralX() const
{
    return _positionCentralX;
}

void ElementProperties::setPositionCentralX(unsigned int positionCentralX)
{
    _positionCentralX = positionCentralX;
}

const sf::Vector2f &ElementProperties::getSize() const
{
    return _size;
}

void ElementProperties::setSize(const sf::Vector2f &size)
{
    _size = size;
}

ElementProperties::ElementProperties(const ElementProperties &elementProperties)
    :_log("ElementProperties")
{
    _log << "Copying an element!!!" << logging::logEnd;
    _size = elementProperties._size;
    _positionCentralX = elementProperties._positionCentralX;
    _positionCentralY = elementProperties._positionCentralY;
    _elementID = elementProperties.getID();
}

unsigned int ElementProperties::getID() const
{
    return _elementID;
}

bool ElementProperties::operator<(const ElementProperties &rhs) const
{
    return _elementID < rhs._elementID;
}

}