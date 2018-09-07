//
// Created by maciejkajdak on 06.09.18.
//

#ifndef ENGINE_IEVENTGENERATORMOCK_HPP
#define ENGINE_IEVENTGENERATORMOCK_HPP

#include <gmock/gmock.h>
#include <Generators/IEventGenerator.hpp>

using ::testing::_;
using ::testing::Invoke;
using ::testing::Return;

namespace eng
{

namespace det
{

class IEventGeneratorMock : public IEventGenerator
{
public:
    MOCK_METHOD1(pollEvent,bool(sf::Event& event));
    void delegateToFake()
    {
        EXPECT_CALL(*this,pollEvent(_))
            .WillOnce(Invoke(this,&IEventGeneratorMock::fakePollEvent))
            .WillRepeatedly(Return(true));
    }

    bool fakePollEvent(sf::Event& event)
    {
        event.type = sf::Event::GainedFocus;
        return true;
    }
};

}
}


#endif //ENGINE_IEVENTGENERATORMOCK_HPP
