//
// Created by mkajdak on 04.09.18.
//

#ifndef ENGINE_SFWINDOWMOCK_HPP
#define ENGINE_SFWINDOWMOCK_HPP

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <SFML/Window.hpp>


namespace sf
{

class WindowMock : public Window
{
public:
    MOCK_METHOD1(pollEvent,bool(sf::Event&));

};

}
#endif //ENGINE_SFWINDOWMOCK_HPP
