//
// Created by mkajdak on 30.08.18.
//

#ifndef ENGINE_IDETECTORMOCK_HPP
#define ENGINE_IDETECTORMOCK_HPP

#include <gmock/gmock.h>
#include <Detectors/IEventDetector.hpp>

namespace eng
{

namespace det
{

class IEventDetectorMock :public IEventDetector
{
public:
    MOCK_METHOD2(startMonitoring,void(
            std::function<void(sf::Event::EventType)> &notifier,
            std::shared_ptr<IEventGenerator> generator));
    MOCK_METHOD0(stopMonitoring,void());
    MOCK_METHOD0(isMonitoring,bool());

};

} //det
} //det

#endif //ENGINE_IDETECTORMOCK_HPP
