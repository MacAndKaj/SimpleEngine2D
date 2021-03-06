//
// Created by maciej on 30.07.18.
//

#ifndef ENGINE_ICLICKABLE_HPP
#define ENGINE_ICLICKABLE_HPP
#include <SFML/Graphics/Drawable.hpp>

class IClickable {
public:
    virtual void click() = 0;
    virtual void unclick() = 0;
    virtual bool isClicked() = 0;
    virtual void focus() = 0;
    virtual void unfocus() = 0;
};


#endif //ENGINE_ICLICKABLE_HPP
