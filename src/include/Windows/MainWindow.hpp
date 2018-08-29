//
// Created by maciej on 16.08.18.
//

#ifndef PARANOID_WINDOW_HPP
#define PARANOID_WINDOW_HPP

#include <map>
#include <SFML/Graphics/RenderWindow.hpp>
#include <Detectors/EventDetector.hpp>
#include <Detectors/CollisionDetector.hpp>
#include <Helpers/ElementProperties.hpp>
#include <Interface/IElement.hpp>
#include <Engine.hpp>

using namespace eng;

class MainWindow
{
public:
    explicit MainWindow(Engine &engine);
    virtual ~MainWindow();

    int run();
    void addItemToDraw(sf::Drawable &);

    //get
    unsigned int getWindowHeight() const;
    unsigned int getWindowWidth() const;
    const std::string &getWindowTitle() const;

    //set
    void setWindowHeight(unsigned int windowHeight);
    void setWindowWidth(unsigned int windowWidth);
    void setWindowTitle(const std::string &windowTitle);
private:
    void drawAllItems();

    unsigned int _windowHeight;
    unsigned int _windowWidth;
    sf::Color _defaultWindowColor;
    std::unique_ptr<sf::RenderWindow> _handlerWindow;
    det::EventDetector &_eventDetector;
    det::CollisionDetector &_collisionDetector;
    std::string _windowTitle;
    std::map<ElementProperties, std::reference_wrapper<const IElement>> _allDrawableItems;
    Logger _log;
};


#endif //PARANOID_WINDOW_HPP
