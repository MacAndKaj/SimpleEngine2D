//
// Created by mkajdak on 30.08.18.
//

#ifndef ENGINE_IDETECTORSMODULE_HPP
#define ENGINE_IDETECTORSMODULE_HPP

#include <Detectors/ICollisionDetector.hpp>

namespace eng
{
namespace det
{

class IEventDetector;

class IDetectorsModule
{
public:
    virtual ~IDetectorsModule() {};
    virtual ICollisionDetector & getCollisionDetector() const =0;
    virtual IEventDetector &getEventDetector() const = 0;
};

}
}

#endif //ENGINE_IDETECTORSMODULE_HPP
