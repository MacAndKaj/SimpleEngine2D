//
// Created by mkajdak on 30.08.18.
//

#ifndef PARANOID_IDECTECTORSMODULEMOCK_HPP
#define PARANOID_IDECTECTORSMODULEMOCK_HPP

#include <gmock/gmock.h>
#include <Modules/IDetectorsModule.hpp>

namespace eng
{

namespace det
{

class IDetectorsModuleMock : public IDetectorsModule
{
public:
    MOCK_CONST_METHOD0(getCollisionDetector,IDetector&());
    MOCK_CONST_METHOD0(getEventDetector,IDetector&());
};

}
}
#endif //PARANOID_IDECTECTORSMODULEMOCK_HPP