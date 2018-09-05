//
// Created by maciej on 27.08.18.
//

#ifndef ENGINE_EVENTDETECTOR_HPP
#define ENGINE_EVENTDETECTOR_HPP

#include <Interface/IDetector.hpp>
#include <Logger.hpp>
#include <SFML/Window.hpp>

namespace eng
{
class DetectorsModule;

namespace det
{

class EventDetector : public IDetector
{
public:
    virtual ~EventDetector();
    void startMonitoring(std::function<void(sf::Event::EventType)> &notifier
                         , std::shared_ptr<sf::Window> window) override;
    void stopMonitoring() override;
    void handleEvents( std::shared_ptr<sf::Window> window);
    bool isMonitoring() override;
private:
    EventDetector();

    Logger _log;
    std::function<void(sf::Event::EventType)> _notifier;
    std::vector<std::thread> _detectorThreads;
    friend class DetectorsModule;
    bool _monitoring;
};

} // det
} // eng
#endif //ENGINE_EVENTDETECTOR_HPP
