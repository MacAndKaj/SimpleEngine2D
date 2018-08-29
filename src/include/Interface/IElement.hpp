//
// Created by mkajdak on 29.08.18.
//

#ifndef PARANOID_IELEMENT_HPP
#define PARANOID_IELEMENT_HPP

#include <Helpers/ElementProperties.hpp>
#include <SFML/Graphics/Drawable.hpp>


namespace eng
{

class IElement : public sf::Drawable
{
public:
    IElement(): _elementProperties(0,0){}
    virtual ~IElement() {};
    virtual ElementProperties getElementProperties() const = 0;
protected:
    ElementProperties _elementProperties;

};

}

#endif //PARANOID_IELEMENT_HPP
