//
// Created by mkajdak on 30.08.18.
//

#ifndef PARANOID_IDETECTORSMODULE_HPP
#define PARANOID_IDETECTORSMODULE_HPP

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

#endif //PARANOID_IDETECTORSMODULE_HPP
