//
// Created by maciejkajdak on 06.09.18.
//

#ifndef ENGINE_ICOLLISIONDETECTOR_HPP
#define ENGINE_ICOLLISIONDETECTOR_HPP

#include <SFML/Window.hpp>
#include <functional>
#include <memory>


namespace eng
{
namespace det
{

class ICollisionDetector
{
public:
    virtual ~ICollisionDetector(){};
    virtual void startMonitoring(std::function<void(sf::Event::EventType)> &notifier,
                                 std::shared_ptr<ICollisionDetector> generator) = 0;
    virtual void stopMonitoring() = 0;
    virtual bool isMonitoring() = 0;
};

} //det
} //eng

#endif //ENGINE_ICOLLISIONDETECTOR_HPP
