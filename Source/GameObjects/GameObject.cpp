/*
 *  GameObject.cpp
 *  EMIT
 *
 *  Created by Andrew Zoerb on 1/15/12.
 *  Copyright 2012 Zoerbsoft. All rights reserved.
 *
 */

#include "GameObject.h"
#include "AllComponents.h"

using sf::Vector2f;

GameObject::GameObject() {
    physicsComponent = NULL;
    renderableComponent = NULL;
    inputComponent = NULL;
}

GameObject::~GameObject() {
    if (physicsComponent) { delete physicsComponent; }
    if (renderableComponent) { delete renderableComponent; }
    if (inputComponent) { delete inputComponent; }
}

void GameObject::update(float elapsedTime) {
    if (inputComponent) {
        inputComponent->update();
    }
    
    if (physicsComponent && renderableComponent) {
        vec2 pos = physicsComponent->getPosition();
        float rot = physicsComponent->getRotation();
        renderableComponent->update(elapsedTime, pos, rot);
    }
}

Component* GameObject::getComponent(ComponentType type) {
    switch (type) {
        case COMP_TYPE_RENDERABLE:
            return renderableComponent;
            break;
            
        case COMP_TYPE_PHYSICS:
            return physicsComponent;
            break;
            
        case COMP_TYPE_INPUT:
            return inputComponent;
            break;
    }
}

void GameObject::addComponent(Component* comp, ComponentType type) {
    switch (type) {
        case COMP_TYPE_RENDERABLE:
            renderableComponent = (RenderableComponent*) comp;
            break;
            
        case COMP_TYPE_PHYSICS:
            physicsComponent = (PhysicsComponent*) comp;
            break;
            
        case COMP_TYPE_INPUT:
            inputComponent = (PlayerInputComponent*) comp;
            break;
    }
}