//
// Created by mkajdak on 30.08.18.
//

#include <gmock/gmock.h>
#include <Engine.hpp>

namespace eng
{

class IEngineMock : public Engine
{
public:
    MOCK_CONST_METHOD0(getDetectorsModule, det::IDetectorsModule & ());
};

}