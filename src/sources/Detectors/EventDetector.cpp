//
// Created by maciej on 27.08.18.
//

#include <Detectors/EventDetector.hpp>
#include <iostream>
namespace eng
{
namespace det
{

EventDetector::EventDetector()
        : _log("EventDetector")
        , _monitoring(false)
{

}

EventDetector::~EventDetector()
{

}

std::thread EventDetector::startMonitoring(std::function<void(sf::Event::EventType)> &notifier
                                           ,sf::Window& window)
{
    _monitoring = true;
    _notifier = std::move(notifier);
    return std::thread(&EventDetector::handleEvents,this,std::ref(window));
}

void EventDetector::stopMonitoring()
{
    _monitoring = false;
}

void EventDetector::handleEvents(sf::Window &window)
{
    sf::Event event{};
    while(_monitoring)
    {

        while(window.pollEvent(event))
        {
            std::cout << "Jestem event" << std::endl;

            if(_notifier)
                _notifier(event.type);
        }
    }
}


} //det
} //eng