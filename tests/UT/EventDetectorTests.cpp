//
// Created by mkajdak on 30.08.18.
//

#include <gtest/gtest.h>
#include <Detectors/EventDetector.hpp>
#include <Engine.hpp>
#include <mocks/SfWindowMock.hpp>
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
    }

    void callback(sf::Event::EventType)
    {
        std::cout << "Jestem test" << std::endl;
    }

    std::unique_ptr<Engine> _engine;
    std::reference_wrapper<IDetector> _sut;
    void doSomething(){std::cout << "Szukam" << std::endl;}
};


TEST_F(EventDetectorTests, EventDetectorTests_ShouldHandleEventAndStartMonitoring_Test)
{
    sf::WindowMock windowMock;

    windowMock.DelegateToFake();
    std::shared_ptr<sf::Window> windowPtr(&windowMock);
    sf::Event event{};
    ASSERT_TRUE(windowMock.pollEvent(event));
    std::function<void(sf::Event::EventType)> func =
            std::bind(&EventDetectorTests::callback,this,std::placeholders::_1);
    _sut.get().startMonitoring(func,windowPtr);
    ASSERT_TRUE(_sut.get().isMonitoring());
    _sut.get().stopMonitoring();
    ASSERT_FALSE(_sut.get().isMonitoring());
}
}
}