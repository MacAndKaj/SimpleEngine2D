//
// Created by maciejkajdak on 06.09.18.
//

#ifndef ENGINE_IEVENTGENERATOR_HPP
#define ENGINE_IEVENTGENERATOR_HPP

#include <SFML/Window/Event.hpp>

namespace eng
{

namespace det
{

class IEventGenerator
{
public:
    virtual ~IEventGenerator(){}
    virtual bool pollEvent(sf::Event& event) = 0;
};

}
}

#endif //ENGINE_IEVENTGENERATOR_HPP
