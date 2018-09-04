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

    std::unique_ptr<Engine> _engine;
    std::reference_wrapper<IDetector> _sut;
    sf::WindowMock _windowMock;
    void doSomething(){std::cout << "Szukam" << std::endl;}
};


TEST_F(EventDetectorTests, EventDetectorTests_ShouldHandleEvent_Test)
{
    std::function<void(sf::Event::EventType)> func =
            [this](sf::Event::EventType event){std::cout << "Jestem test" << std::endl;};
    EXPECT_CALL(_windowMock,pollEvent(_)).WillOnce(Return(true));
    auto thr = _sut.get().startMonitoring(func,_windowMock);
    //EXPECT_CALL(_windowMock,pollEvent(_)).
    //    WillRepeatedly(Invoke(&_windowMock,&sf::WindowMock::pollEventFromMock));
    std::this_thread::sleep_for(100us);
    thr.detach();
    _sut.get().stopMonitoring();
}
}
}