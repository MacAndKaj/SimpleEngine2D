//
// Created by maciej on 12.08.18.
//

#include <Buttons/LetterButton.hpp>
#include <iostream>

LetterButton::LetterButton()
        : _log("LetterButton")
        , _clicked(false)
        , _focused(false)
{
    _buttonText.setString("LetterButton");
    if (!_font.loadFromFile("Pacific_Again.ttf"))
    {
        _log << __FUNCTION__ << "Error while loading font!" << logging::logEnd;

    }
    _buttonText.setFont(_font);
    _buttonText.setFillColor(_basicColor);

}

LetterButton::~LetterButton()
{

}

void LetterButton::click()
{
    if (_focused)
    {
        _buttonText.setFillColor(_onClickColor);
        _clicked = true;
    }

}

void LetterButton::unclick()
{
    if (_clicked)
    {
        if (_callback)
        {
            _log << __FUNCTION__ << " callback applied." << logging::logEnd;
            _callback();
        }
        _buttonText.setFillColor(_onFocusColor);
        _clicked = false;
    }
}

bool LetterButton::isClicked()
{
    return _clicked;
}

void LetterButton::setFunctionality(std::function<void()> &functionality)
{
    _callback = functionality;
}

void LetterButton::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(_buttonText, states);
}

void LetterButton::setBasicColor(const sf::Color &basicColor)
{
    _basicColor = basicColor;
}

void LetterButton::setOnFocusColor(const sf::Color &onFocusColor)
{
    _onFocusColor = onFocusColor;
}

void LetterButton::setOnClickColor(const sf::Color &onClickColor)
{
    _onClickColor = onClickColor;
}

void LetterButton::focus()
{
    if (not _focused)
    {
        _buttonText.setFillColor(_onFocusColor);
        _focused = true;
    }
}

void LetterButton::unfocus()
{
    if (_focused)
    {
        _buttonText.setFillColor(_basicColor);
        _focused = false;
    }
}

void LetterButton::setButtonText(const std::string &buttonText)
{
    _buttonText.setString(buttonText);
    _log.setNameOfLoggerOwner("LetterButton(" + buttonText + ')');
}

eng::ElementProperties LetterButton::getElementProperties() const
{
    return _elementProperties;
}

unsigned int LetterButton::getElementID() const
{
    return _elementProperties.getID();
}


