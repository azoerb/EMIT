/*
 *  InputComponent.cpp
 *  EMIT
 *
 *  Created by Andrew Zoerb on 12/18/11.
 *  Copyright 2011 Zoerbsoft. All rights reserved.
 *
 */

#include "InputComponent.h"
#include "InputHandler.h"

void InputComponent::registerHandler(InputHandler* handler) {
    this->handler = handler;
}

void InputComponent::assignAction(sf::Key::Code key, void (*action)()) {
    map.insert(actionPair(key, action));
}

void InputComponent::update() {
    actionMap::iterator iter;
    for (iter = map.begin(); iter != map.end(); iter++) {
        if (handler->isKeyDown(iter->first)) {
            // Perform the action
            iter->second();
        }
    }
}