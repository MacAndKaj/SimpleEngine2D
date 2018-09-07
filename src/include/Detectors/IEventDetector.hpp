//
// Created by maciej on 27.08.18.
//

#ifndef ENGINE_IDETECTOR_HPP
#define ENGINE_IDETECTOR_HPP

#include <functional>
#include <SFML/Window/Event.hpp>
#include <thread>
#include <Generators/IEventGenerator.hpp>

namespace eng
{

namespace det
{

class IEventDetector
{
public:
    virtual void startMonitoring(std::function<void(sf::Event)> &notifier
                                 , std::shared_ptr<IEventGenerator> generator) = 0;
    virtual void stopMonitoring() = 0;
    virtual bool isMonitoring() = 0;
};

} //det
} //eng
#endif //ENGINE_IDETECTOR_HPP
