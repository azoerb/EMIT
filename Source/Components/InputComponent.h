/*
 *  InputComponent.h
 *  EMIT
 *
 *  Created by Andrew Zoerb on 12/18/11.
 *  Copyright 2011 Zoerbsoft. All rights reserved.
 *
 */

#pragma once

#include "Component.h"
#include <map>
#include <SFML/Graphics.hpp>

typedef void (*action)();
typedef std::map<sf::Key::Code, action> actionMap;
typedef std::pair<sf::Key::Code, action> actionPair;

class InputHandler;

class InputComponent : public Component {
private:
    InputHandler* handler;
    actionMap map;
    
public:
    InputComponent(InputHandler* handler);
    void assignAction(sf::Key::Code key, void (*action)());
    void update();
};
