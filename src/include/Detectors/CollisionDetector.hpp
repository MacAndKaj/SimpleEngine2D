//
// Created by maciej on 26.08.18.
//

#ifndef ENGINE_COLLISIONDETECTOR_HPP
#define ENGINE_COLLISIONDETECTOR_HPP

#include <Interface/IDetector.hpp>
#include <Logger.hpp>
#include <functional>
#include <thread>

namespace eng
{
class DetectorsModule;

namespace det
{

class CollisionDetector : public IDetector
{
public:
    virtual ~CollisionDetector();
    std::thread startMonitoring(std::function<void(sf::Event::EventType)> &notifier
                                , sf::Window &window) override;
    void stopMonitoring() override;
private:
    CollisionDetector();
    Logger _log;
    friend class DetectorsModule;
};

} //det
} //eng

#endif //ENGINE_COLLISIONDETECTOR_HPP
