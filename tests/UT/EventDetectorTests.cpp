//
// Created by mkajdak on 30.08.18.
//

#include <gtest/gtest.h>
#include <mocks/IEventGeneratorMock.hpp>
#include <Detectors/EventDetector.hpp>
#include <Engine.hpp>
#include <chrono>

using ::testing::_;
using ::testing::Return;
using namespace testing;
using namespace std::literals::chrono_literals;

namespace eng
{

namespace det
{
class EventDetectorTests : public ::testing::Test
{
public:
    EventDetectorTests()
        : _engine(new Engine)
        , _sut(_engine->getDetectorsModule().getEventDetector())
    {
        _eventGeneratorMock = std::make_shared<IEventGeneratorMock>();
    }

    void callback(sf::Event)
    {
        _callbackApplied = true;
    }

    void isEventTypeEqualToGainedFocus(sf::Event event)
    {
        _callbackApplied = event.type == sf::Event::GainedFocus;
    }

    bool _callbackApplied;


    std::shared_ptr<IEventGeneratorMock> _eventGeneratorMock;
    std::unique_ptr<Engine> _engine;
    std::reference_wrapper<IEventDetector> _sut;
};


TEST_F(EventDetectorTests, EventDetectorTests_ShouldHandleEventAndStartMonitoring_Test)
{
    _callbackApplied = false;
    std::function<void(sf::Event)> func =
            std::bind(&EventDetectorTests::callback,this,std::placeholders::_1);
    EXPECT_CALL(*_eventGeneratorMock,pollEvent)
        .WillOnce(Return(true))
        .WillRepeatedly(Return(false));
    _sut.get().startMonitoring(func,_eventGeneratorMock);
    ASSERT_TRUE(_sut.get().isMonitoring());
    std::this_thread::sleep_for(std::chrono::milliseconds(1));
    _sut.get().stopMonitoring();
    ASSERT_FALSE(_sut.get().isMonitoring());
    ASSERT_TRUE(_callbackApplied);
}


TEST_F(EventDetectorTests, EventDetectorTests_ShouldHandleCloseEvent_Test)
{
    _callbackApplied = false;
    std::function<void(sf::Event)> func =
        std::bind(&EventDetectorTests::isEventTypeEqualToGainedFocus,this,std::placeholders::_1);
    _eventGeneratorMock->delegateToFake();
    _sut.get().startMonitoring(func,_eventGeneratorMock);
    ASSERT_TRUE(_sut.get().isMonitoring());

    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    _sut.get().stopMonitoring();
    ASSERT_TRUE(_callbackApplied);
}
}
}