//
// Created by maciej on 27.08.18.
//

#include <Detectors/EventDetector.hpp>
#include <iostream>
#include <future>

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

void EventDetector::startMonitoring(std::function<void(sf::Event::EventType)> &notifier
                                    , std::shared_ptr<sf::Window> window)
{
    _monitoring = true;
    _notifier = notifier;
    auto thr = std::thread(&EventDetector::handleEvents,this,window);
    _detectorThreads.push_back(std::move(thr));
}

void EventDetector::stopMonitoring()
{
    _monitoring = false;
    for (auto &item : _detectorThreads)
    {
        item.join();
    }
}

void EventDetector::handleEvents( std::shared_ptr<sf::Window>  window)
{
    _log << __FUNCTION__ << " started for window" << logging::logEnd;
    std::cout << "Jestem handler" << std::endl;

    sf::Event event{};
    while(_monitoring)
    {
        std::cout << window->pollEvent(event) << std::endl;
        if(window->pollEvent(event))
        {
            std::cout << "Jestem event" << std::endl;
            if(_notifier)
                _notifier(event.type);
        }

    }
    _log << __FUNCTION__ << " stopped for window" << logging::logEnd;
}

bool EventDetector::isMonitoring()
{
    return _monitoring;
}


} //det
} //eng