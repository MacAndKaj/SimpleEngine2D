//
// Created by mkajdak on 30.08.18.
//

#ifndef ENGINE_IENGINE_HPP
#define ENGINE_IENGINE_HPP

#include <Modules/DetectorsModule.hpp>


namespace eng
{

class IEngine
{
public:
    virtual ~IEngine() = default;;
    virtual const det::IDetectorsModule &getDetectorsModule() const = 0;
};

} //eng

#endif //ENGINE_IENGINE_HPP
