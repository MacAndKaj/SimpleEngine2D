//
// Created by mkajdak on 30.08.18.
//

#ifndef ENGINE_IDETECTORMOCK_HPP
#define ENGINE_IDETECTORMOCK_HPP

#include <gmock/gmock.h>
#include <Interface/IDetector.hpp>

namespace eng
{

namespace det
{

class IDetectorMock :public IDetector
{
public:
    MOCK_METHOD2(startMonitoring,void(
            std::function<void(sf::Event::EventType)> &notifier,
            std::shared_ptr<sf::Window> window));
    MOCK_METHOD0(stopMonitoring,void());
    MOCK_METHOD0(isMonitoring,bool());

};

} //det
} //det

#endif //ENGINE_IDETECTORMOCK_HPP
