//
// Created by maciej on 16.08.18.
//

#include <SFML/Window/Event.hpp>
#include <Windows/MainWindow.hpp>
using namespace eng;

MainWindow::MainWindow(IEngine &engine)
        : _log("MainWindow")
        , _defaultWindowColor(sf::Color::Black)
        , _eventDetector(engine.getDetectorsModule().getEventDetector())
        , _collisionDetector(engine.getDetectorsModule().getCollisionDetector())
        , _windowTitle("MainWindow")
{
    auto desktopMode = sf::VideoMode::getDesktopMode();
    _windowWidth = desktopMode.width;
    _windowHeight = desktopMode.height;
    _handlerWindow = std::make_unique<sf::RenderWindow>(
            sf::VideoMode(_windowWidth, _windowHeight), _windowTitle);
    _handlerWindow->setVisible(false);
}

int MainWindow::run()
{
    _handlerWindow->setVisible(true);
    while (_handlerWindow->isOpen())
    {
        _handlerWindow->clear(_defaultWindowColor);
        drawAllElements();
        _handlerWindow->display();
    }

    return EXIT_SUCCESS;
}

void MainWindow::addItemToDraw(std::unique_ptr<IElement> &item)
{
    _log << __FUNCTION__ << " element ID: " <<
        std::to_string(item->getElementID()).c_str() << logging::logEnd;
    _allDrawableItems.insert(std::make_pair(
            item->getElementID(), std::move(item)));
}

void MainWindow::drawAllElements()
{
    if (not _allDrawableItems.empty())
    {
        for (const auto &drawableItem : _allDrawableItems)
        {
            _handlerWindow->draw(*(drawableItem.second));
        }
    }
    else
    {
        _log << "Nothing to draw!" << logging::logEnd;
    }
}

unsigned int MainWindow::getWindowHeight() const
{
    return _windowHeight;
}

void MainWindow::setWindowHeight(unsigned int windowHeight)
{
    _windowHeight = windowHeight;
}

unsigned int MainWindow::getWindowWidth() const
{
    return _windowWidth;
}

void MainWindow::setWindowWidth(unsigned int windowWidth)
{
    _windowWidth = windowWidth;
}

const std::string &MainWindow::getWindowTitle() const
{
    return _windowTitle;
}

void MainWindow::setWindowTitle(const std::string &windowTitle)
{
    _windowTitle = windowTitle;
}

bool MainWindow::isElement(const unsigned int &id) const
{
    if (_allDrawableItems.find(id) != _allDrawableItems.end())
    {
        return true;
    }
    else
    {
        _log << __FUNCTION__ << "element with ID:"  << std::to_string(id).c_str() << " not found" << logging::logEnd;
    }
    return false;
}

