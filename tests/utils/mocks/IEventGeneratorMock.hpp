//
// Created by maciejkajdak on 06.09.18.
//

#ifndef ENGINE_IEVENTGENERATORMOCK_HPP
#define ENGINE_IEVENTGENERATORMOCK_HPP

#include <gmock/gmock.h>
#include <Generators/IEventGenerator.hpp>


namespace eng
{

namespace det
{

class IEventGeneratorMock : public IEventGenerator
{
    MOCK_METHOD1(pollEvent,bool(sf::Event& event));
};

}
}


#endif //ENGINE_IEVENTGENERATORMOCK_HPP
