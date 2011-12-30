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

void InputComponent::update() {
    if (handler->isKeyDown(sf::Key::Right)) {
    } else if (handler->isKeyDown(sf::Key::Left)) {
    } else if (handler->isKeyDown(sf::Key::Down)) {
    } else if (handler->isKeyDown(sf::Key::Up)) {
    } else {
    }
}