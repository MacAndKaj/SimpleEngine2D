//
// Created by mkajdak on 30.08.18.
//

#ifndef PARANOID_IDETECTORMOCK_HPP
#define PARANOID_IDETECTORMOCK_HPP

#include <gmock/gmock.h>
#include <Interface/IDetector.hpp>

namespace eng
{

namespace det
{

class IDetectorMock :public IDetector
{
public:
    MOCK_METHOD0(startMonitoring,void());
    MOCK_METHOD0(stopMonitoring,void());
};

} //det
} //det

#endif //PARANOID_IDETECTORMOCK_HPP
