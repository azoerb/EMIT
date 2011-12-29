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

#include "PhysicsComponent.h"

void InputComponent::registerHandler(InputHandler* handler) {
    this->handler = handler;
}

cpVect InputComponent::update() {
    if (handler->isKeyDown(sf::Key::Right)) {
        cpVect forceVect = cpv(500.0, 0.0);
        return forceVect;
    } else if (handler->isKeyDown(sf::Key::Left)) {
        cpVect forceVect = cpv(-500.0, 0.0);
        return forceVect;
    } else {
        return cpv(0.0, 0.0);
    }
}