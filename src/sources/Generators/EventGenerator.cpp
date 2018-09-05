//
// Created by maciejkajdak on 06.09.18.
//

#include "Generators/EventGenerator.hpp"


namespace eng
{

namespace det
{


EventGenerator::EventGenerator(sf::Window &window)
    :_window(window)
{

}

bool EventGenerator::pollEvent(sf::Event &event)
{
    return _window.pollEvent(event);
}


}
}