//
// Created by maciejkajdak on 06.09.18.
//

#ifndef ENGINE_ICOLLISIONDETECTORMOCK_HPP
#define ENGINE_ICOLLISIONDETECTORMOCK_HPP

#include <gmock/gmock.h>
#include <Detectors/ICollisionDetector.hpp>

namespace eng
{

namespace det
{


class ICollisionDetectorMock : public ICollisionDetector
{
public:
    MOCK_METHOD2(startMonitoring,void(
        std::function<void(sf::Event::EventType)> &notifier,
        std::shared_ptr<ICollisionDetector> generator));
    MOCK_METHOD0(isMonitoring,bool());
    MOCK_METHOD0(stopMonitoring,void());
};


}
}

#endif //ENGINE_ICOLLISIONDETECTORMOCK_HPP
