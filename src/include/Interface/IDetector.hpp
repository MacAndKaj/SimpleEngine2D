//
// Created by maciej on 27.08.18.
//

#ifndef ENGINE_IDETECTOR_HPP
#define ENGINE_IDETECTOR_HPP

#include <functional>
#include <SFML/Window/Event.hpp>
#include <thread>

namespace eng
{

namespace det
{

class IDetector
{
public:
    virtual std::thread startMonitoring(std::function<void(sf::Event::EventType)> &notifier
                                        , sf::Window &window) = 0;
    virtual void stopMonitoring() = 0;
};

} //det
} //eng
#endif //ENGINE_IDETECTOR_HPP
