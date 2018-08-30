//
// Created by mkajdak on 29.08.18.
//

#ifndef ENGINE_IELEMENT_HPP
#define ENGINE_IELEMENT_HPP

#include <Helpers/ElementProperties.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <functional>

class LetterButton;

namespace eng
{

class IElement : public sf::Drawable
{
public:
    IElement() : _elementProperties(0, 0)
    {}

    IElement(const IElement &) = delete;

    virtual ~IElement()
    {};
    virtual ElementProperties getElementProperties() const = 0;
    virtual unsigned int getElementID() const = 0;
protected:
    ElementProperties _elementProperties;

};

}

#endif //ENGINE_IELEMENT_HPP
