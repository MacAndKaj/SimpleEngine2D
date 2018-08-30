//
// Created by maciej on 26.08.18.
//

#ifndef ENGINE_COLLISIONDETECTOR_HPP
#define ENGINE_COLLISIONDETECTOR_HPP

#include <Interface/IDetector.hpp>
#include <Logger.hpp>

namespace eng
{
class DetectorsModule;

namespace det
{

class CollisionDetector : public IDetector
{
public:
    virtual ~CollisionDetector();
    void startMonitoring() override;
    void stopMonitoring() override;
private:
    CollisionDetector();
    Logger _log;
    friend class DetectorsModule;
};

} //det
} //eng

#endif //ENGINE_COLLISIONDETECTOR_HPP
