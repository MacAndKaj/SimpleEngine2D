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
    stopMonitoring();
}

void EventDetector::startMonitoring(std::function<void(sf::Event::EventType)> &notifier,
                                    std::shared_ptr<IEventGenerator> generator)
{
    _monitoring = true;
    _notifier = notifier;
    auto thr = std::thread(&EventDetector::handleEvents,this,generator);
    _detectorThreads.push_back(std::move(thr));
}

void EventDetector::stopMonitoring()
{
    _monitoring = false;
    for (auto &item : _detectorThreads)
    {
        if (item.joinable())item.join();
    }
}

void EventDetector::handleEvents( std::shared_ptr<IEventGenerator> generator )
{
    _log << __FUNCTION__ << " started for window" << logging::logEnd;
    sf::Event event{};
    while(_monitoring)
    {
        if(generator->pollEvent(event))
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