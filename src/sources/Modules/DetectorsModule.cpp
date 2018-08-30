//
// Created by mkajdak on 28.08.18.
//

#include <Modules/DetectorsModule.hpp>
#include <Detectors/CollisionDetector.hpp>
#include <Detectors/EventDetector.hpp>

namespace eng
{

namespace det
{

DetectorsModule::DetectorsModule()
        : _log("DetectorsModule")
        , _collisionDetectorPtr(new CollisionDetector)
        , _eventDetectorPtr(new EventDetector)
{

}


DetectorsModule::~DetectorsModule()
{

}

IDetector &DetectorsModule::getCollisionDetector() const
{
    return *_collisionDetectorPtr;
}

IDetector &DetectorsModule::getEventDetector() const
{
    return *_eventDetectorPtr;
}

} // det
} // eng