//
// Created by mkajdak on 28.08.18.
//

#ifndef ENGINE_DETECTORSMODULE_HPP
#define ENGINE_DETECTORSMODULE_HPP

#include <Logger.hpp>
#include "IDetectorsModule.hpp"

namespace eng
{
class Engine;

namespace det
{

class CollisionDetector;
class EventDetector;

class DetectorsModule : public IDetectorsModule
{
public:
    ICollisionDetector & getCollisionDetector() const override;
    IEventDetector &getEventDetector() const override;
    ~DetectorsModule() override;
protected:
    DetectorsModule();

private:

    Logger _log;

    std::unique_ptr<CollisionDetector> _collisionDetectorPtr;
    std::unique_ptr<EventDetector> _eventDetectorPtr;
    friend class eng::Engine;
};
} //det
} //eng
#endif //ENGINE_DETECTORSMODULE_HPP
