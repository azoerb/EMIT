/*
 *  GameObject.h
 *  EMIT
 *
 *  Created by Andrew Zoerb on 11/8/11.
 *  Copyright 2011 Zoerbsoft. All rights reserved.
 *
 */

#pragma once

#include "AllComponents.h"
#include "Constants.h"

using sf::Vector2f;

class GameObject {
private:
    PhysicsComponent* physicsComponent;
    RenderableComponent* renderableComponent;
    InputComponent* inputComponent;
    
public:
    GameObject() {
        
    }
    
    ~GameObject() {
        if (physicsComponent) { delete physicsComponent; }
        if (renderableComponent) { delete renderableComponent; }
        if (inputComponent) { delete inputComponent; }
    }
    
    void update(float elapsedTime) {
        physicsComponent->update(elapsedTime);
        
        // Get the position and rotation from the physics engine
        cpVect pos = physicsComponent->getPosition();
        float rot = -cpvtoangle(physicsComponent->getRotation()) * 180 / PI;
        renderableComponent->update(elapsedTime, Vector2f(pos.x, pos.y), rot);
    }
    
    Component* getComponent(ComponentType type) {
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
    
    void addComponent(Component* comp, ComponentType type) {
        switch (type) {
            case COMP_TYPE_RENDERABLE:
                renderableComponent = (RenderableComponent*) comp;
                break;
                
            case COMP_TYPE_PHYSICS:
                physicsComponent = (PhysicsComponent*) comp;
                break;
                
            case COMP_TYPE_INPUT:
                inputComponent = (InputComponent*) comp;
                break;
        }
    }
};
