//
// Created by maciej on 26.08.18.
//

#ifndef ENGINE_COLLISIONDETECTOR_HPP
#define ENGINE_COLLISIONDETECTOR_HPP

#include <Detectors/ICollisionDetector.hpp>
#include <Logger.hpp>
#include <functional>
#include <thread>

namespace eng
{
class DetectorsModule;

namespace det
{

class CollisionDetector : public ICollisionDetector
{
public:
    ~CollisionDetector() override;
    void startMonitoring(std::function<void(sf::Event::EventType)> &notifier,
                         std::shared_ptr<ICollisionDetector> generator) override;
    void stopMonitoring() override;
    bool isMonitoring() override;
private:
    CollisionDetector();
    Logger _log;
    friend class DetectorsModule;
};

} //det
} //eng

#endif //ENGINE_COLLISIONDETECTOR_HPP
