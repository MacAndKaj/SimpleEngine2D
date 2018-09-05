//
// Created by maciej on 26.08.18.
//

#include <Detectors/CollisionDetector.hpp>

namespace eng
{
namespace det
{

CollisionDetector::CollisionDetector()
        : _log("CollisionDetector")
{

}

CollisionDetector::~CollisionDetector()
{

}

void CollisionDetector::startMonitoring(std::function<void(sf::Event::EventType)> &notifier,
                                        std::shared_ptr<ICollisionDetector> generator)
{

}

void CollisionDetector::stopMonitoring()
{

}

bool CollisionDetector::isMonitoring()
{
    return false;
}

} //det
} //eng