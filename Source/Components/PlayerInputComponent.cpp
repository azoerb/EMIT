/*
 *  PlayerInputComponent.cpp
 *  EMIT
 *
 *  Created by Andrew Zoerb on 12/18/11.
 *  Copyright 2011 Zoerbsoft. All rights reserved.
 *
 */

#include "PlayerInputComponent.h"
#include "InputHandler.h"
#include "GameObject.h"

PlayerInputComponent::PlayerInputComponent(InputHandler* handler) {
    this->handler = handler;
}

void PlayerInputComponent::assignAction(sf::Key::Code key, void (*action)()) {
    map.insert(actionPair(key, action));
}

void PlayerInputComponent::update() {
    if (handler->isKeyDown(sf::Key::Right)) {
        moveRight();
    }
    actionMap::iterator iter;
    for (iter = map.begin(); iter != map.end(); iter++) {
        if (handler->isKeyDown(iter->first)) {
            // Perform the action
            //GameObject p = *parent;
            //(p.*p.(iter->second))();
        }
    }
}

void PlayerInputComponent::moveRight() {
    PhysicsComponent* physicsComp = (PhysicsComponent*) parent->getComponent(COMP_TYPE_PHYSICS);
    //b2Vec2 impulse = b2Vec2(1.0, 0.0);
    //physicsComp->applyImpulse(impulse);
}

void PlayerInputComponent::moveLeft() {

}
