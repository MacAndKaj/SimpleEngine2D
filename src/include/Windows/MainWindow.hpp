//
// Created by maciej on 16.08.18.
//

#ifndef ENGINE_MAINWINDOW_HPP
#define ENGINE_MAINWINDOW_HPP

#include <map>
#include <SFML/Graphics/RenderWindow.hpp>
#include <Detectors/EventDetector.hpp>
#include <Detectors/CollisionDetector.hpp>
#include <Helpers/ElementProperties.hpp>
#include <Interface/IElement.hpp>
#include <Engine.hpp>
#include <Generators/IEventGenerator.hpp>

using namespace eng;

class MainWindow
{
public:
    explicit MainWindow(IEngine &engine);
    virtual ~MainWindow()
    {};

    int run();
    void addItemToDraw(std::unique_ptr<IElement> &);
    bool isElement(const unsigned int &id) const;
    void handleEvent(sf::Event event);

    //get
    unsigned int getWindowHeight() const;
    unsigned int getWindowWidth() const;

    const std::string &getWindowTitle() const;
    //set
    void setWindowHeight(unsigned int windowHeight);
    void setWindowWidth(unsigned int windowWidth);
    void setWindowTitle(const std::string &windowTitle);
private:
    void drawAllElements();
    void closeWindow();
    void keyPressed(sf::Event &event);


    unsigned int _windowHeight;
    unsigned int _windowWidth;
    sf::Color _defaultWindowColor;
    det::IEventDetector &_eventDetector;
    det::ICollisionDetector &_collisionDetector;
    std::shared_ptr<det::IEventGenerator> _eventGenerator;
    std::string _windowTitle;
    std::map<unsigned int, std::unique_ptr<IElement>> _allDrawableItems;
    Logger _log;
    std::unique_ptr<sf::RenderWindow> _handlerWindow;
};


#endif //ENGINE_MAINWINDOW_// HPP
