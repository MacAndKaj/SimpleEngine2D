//
// Created by mkajdak on 04.09.18.
//

#ifndef ENGINE_SFWINDOWMOCK_HPP
#define ENGINE_SFWINDOWMOCK_HPP

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <SFML/Window.hpp>

using ::testing::_;
using ::testing::Invoke;

namespace sf
{
class WindowFake : public Window
{
public:
    bool fakePollEvent(sf::Event& ev)
    {
        std::cerr << "Zwracam" << std::endl;
        ev.type = sf::Event::Closed;
        return true;
    }
};


class WindowMock : public Window
{
public:
    MOCK_METHOD1(pollEvent,bool(Event& event));
    void DelegateToFake()
    {
        ON_CALL(*this,pollEvent)
            .WillByDefault(Invoke(&_fake,&WindowFake::fakePollEvent));
    }


private:
    WindowFake _fake;
};



}
#endif //ENGINE_SFWINDOWMOCK_HPP
