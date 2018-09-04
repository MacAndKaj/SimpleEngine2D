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

std::thread CollisionDetector::startMonitoring(std::function<void(sf::Event::EventType)> &notifier
                                               , sf::Window &window)
{

}

void CollisionDetector::stopMonitoring()
{

}

} //det
} //eng