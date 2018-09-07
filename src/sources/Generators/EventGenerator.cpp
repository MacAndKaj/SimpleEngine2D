//
// Created by maciejkajdak on 06.09.18.
//

#include <Generators/EventGenerator.hpp>


namespace eng
{

namespace det
{


EventGenerator::EventGenerator(sf::Window &window)
    : _window(window)
{
}

bool EventGenerator::pollEvent(sf::Event& event)
{
    if (not _window.get().isOpen()) return false;
    return _window.get().pollEvent(event);
}


}
}