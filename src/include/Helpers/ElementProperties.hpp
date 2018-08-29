//
// Created by mkajdak on 29.08.18.
//

#ifndef PARANOID_ELEMENTPROPERTIES_HPP
#define PARANOID_ELEMENTPROPERTIES_HPP


#include <SFML/System.hpp>

namespace eng
{

class ElementProperties
{
public:
    ElementProperties() = delete;
    ElementProperties(unsigned int positionCentralY, unsigned int positionCentralX);
    ElementProperties(const ElementProperties& elementProperties);
    unsigned int getPositionCentralY() const;
    void setPositionCentralY(unsigned int positionCentralY);
    unsigned int getPositionCentralX() const;
    void setPositionCentralX(unsigned int positionCentralX);
    const sf::Vector2f &getSize() const;
    void setSize(const sf::Vector2f &size);
    unsigned int getElementID() const;
private:
    unsigned int _positionCentralY;
    unsigned int _positionCentralX;
    sf::Vector2f _size;
    unsigned int _elementID;
    static unsigned int _amountOfRegisteredElements;
};

} //eng

#endif //PARANOID_ELEMENTPROPERTIES_HPP
