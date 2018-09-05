//
// Created by maciejkajdak on 06.09.18.
//

#ifndef ENGINE_EVENTGENERATOR_HPP
#define ENGINE_EVENTGENERATOR_HPP

#include <SFML/Window.hpp>
#include "IEventGenerator.hpp"

namespace eng
{

namespace det
{

class EventGenerator : public IEventGenerator
{
public:
    explicit EventGenerator(sf::Window &window);
    bool pollEvent(sf::Event &event) override;
    sf::Window &_window;
};

}
}

#endif //ENGINE_EVENTGENERATOR_HPP
