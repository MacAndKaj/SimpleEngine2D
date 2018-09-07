//
// Created by maciej on 27.08.18.
//

#ifndef ENGINE_EVENTDETECTOR_HPP
#define ENGINE_EVENTDETECTOR_HPP

#include <Detectors/IEventDetector.hpp>
#include <Logger.hpp>
#include <SFML/Window.hpp>

namespace eng
{
class DetectorsModule;

namespace det
{

class EventDetector : public IEventDetector
{
public:
    virtual ~EventDetector();
    void startMonitoring(std::function<void(sf::Event)> &notifier
                         , std::shared_ptr<IEventGenerator> generator) override;
    void stopMonitoring() override;
    void handleEvents( std::shared_ptr<IEventGenerator> generator);
    bool isMonitoring() override;
private:
    EventDetector();

    Logger _log;
    std::function<void(sf::Event)> _notifier;
    std::vector<std::thread> _detectorThreads;
    friend class DetectorsModule;
    bool _monitoring;
};

} // det
} // eng
#endif //ENGINE_EVENTDETECTOR_HPP
