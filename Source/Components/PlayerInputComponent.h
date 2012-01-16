/*
 *  PlayerInputComponent.h
 *  EMIT
 *
 *  Created by Andrew Zoerb on 12/18/11.
 *  Copyright 2011 Zoerbsoft. All rights reserved.
 *
 */

#pragma once

#include "InputComponent.h"

typedef void (*action)();
typedef std::map<sf::Key::Code, action> actionMap;
typedef std::pair<sf::Key::Code, action> actionPair;

class PlayerInputComponent : public InputComponent {
private:
    actionMap map;
    
    void moveRight();
    void moveLeft();
    
public:
    PlayerInputComponent(GameObject* parent, InputHandler* handler);
    void assignAction(sf::Key::Code key, void (*action)());
    void update();
};
