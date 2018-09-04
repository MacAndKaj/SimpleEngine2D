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
    std::thread startMonitoring(std::function<void(sf::Event::EventType)> &notifier
                                , sf::Window &window) override;
    void stopMonitoring() override;
    void handleEvents(sf::Window &window);
private:
    EventDetector();

    Logger _log;
    std::function<void(sf::Event::EventType)> _notifier;
    friend class DetectorsModule;
    bool _monitoring;
};

} // det
} // eng
#endif //ENGINE_EVENTDETECTOR_HPP
