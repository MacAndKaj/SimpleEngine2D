//
// Created by mkajdak on 30.08.18.
//

#ifndef ENGINE_IDETECTORSMODULE_HPP
#define ENGINE_IDETECTORSMODULE_HPP

namespace eng
{
namespace det
{

class IDetector;

class IDetectorsModule
{
public:
    virtual ~IDetectorsModule() {};
    virtual IDetector &getCollisionDetector() const =0;
    virtual IDetector &getEventDetector() const = 0;
};

}
}

#endif //ENGINE_IDETECTORSMODULE_HPP
