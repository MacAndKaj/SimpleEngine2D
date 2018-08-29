//
// Created by maciej on 16.08.18.
//

#include <SFML/Window/Event.hpp>
#include <Windows/MainWindow.hpp>
using namespace eng;

MainWindow::MainWindow(Engine &engine)
        : _log("MainWindow")
        , _defaultWindowColor(sf::Color::Black)
        , _eventDetector(engine.getDetectorsFactory().getEventDetector())
        , _collisionDetector(engine.getDetectorsFactory().getCollisionDetector())
        , _windowTitle("MainWindow")
{
    auto desktopMode = sf::VideoMode::getDesktopMode();
    _windowWidth = desktopMode.width;
    _windowHeight = desktopMode.height;
    _handlerWindow = std::make_unique<sf::RenderWindow>(
            sf::VideoMode(_windowWidth, _windowHeight), _windowTitle);
}

MainWindow::~MainWindow()
{

}

int MainWindow::run()
{
    while (_handlerWindow->isOpen())
    {
        _handlerWindow->clear(_defaultWindowColor);
        drawAllItems();
        _handlerWindow->display();
    }

    return EXIT_SUCCESS;
}

void MainWindow::addItemToDraw(sf::Drawable &item)
{

}

void MainWindow::drawAllItems()
{
    if (not _allDrawableItems.empty())
    {
        for (const auto &drawableItem : _allDrawableItems)
        {
            _handlerWindow->draw(drawableItem.second.get());
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
