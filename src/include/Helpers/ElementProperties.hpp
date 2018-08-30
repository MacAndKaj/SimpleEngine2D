//
// Created by mkajdak on 29.08.18.
//

#ifndef ENGINE_ELEMENTPROPERTIES_HPP
#define ENGINE_ELEMENTPROPERTIES_HPP


#include <SFML/System.hpp>
#include <Logger.hpp>

namespace eng
{

class ElementProperties
{
public:
    ElementProperties() = delete;
    ElementProperties(unsigned int positionCentralY, unsigned int positionCentralX);
    ElementProperties(const ElementProperties& elementProperties);

    //set
    unsigned int getPositionCentralY() const;
    unsigned int getPositionCentralX() const;
    const sf::Vector2f &getSize() const;
    unsigned int getID() const;

    //get
    void setPositionCentralY(unsigned int positionCentralY);
    void setPositionCentralX(unsigned int positionCentralX);
    void setSize(const sf::Vector2f &size);

    //relations
    bool operator<(const ElementProperties &rhs) const;
private:
    unsigned int _positionCentralY;
    unsigned int _positionCentralX;
    sf::Vector2f _size;
    unsigned int _elementID;
    Logger _log;
    static unsigned int _amountOfRegisteredElements;
};

} //eng

#endif //ENGINE_ELEMENTPROPERTIES_HPP
